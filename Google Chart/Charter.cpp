#include "Charter.h"
#include "curl/curl.h"

void GoogleChart::InitChart(ChartType type, string title, int height, int width)
{
  BaseURL = "http://chart.googleapis.com/chart?";
  m_type = type;
  m_title = title;
  m_height = height;
  m_width = width;
}

void GoogleChart::addDataSet(ChartDataSet* dataSet)
{
  m_dataSets.push_back(dataSet);
}

size_t curl_write(void *ptr, size_t size, size_t nmemb, FILE *stream) {
  return fwrite(ptr, size, nmemb, stream);
}

string GoogleChart::GetChart()
{
  //printf("%s",BuildUrl().c_str());
  
  std::string dir;
  
  CURL *curl = curl_easy_init();
  if(curl)
  {
    FILE *file = fopen("Chart.jpg", "wb");
    
    curl_easy_setopt(curl, CURLOPT_URL, BuildUrl().c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_write);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
    
    curl_easy_perform(curl);
    
    fclose(file);
  }
  curl_easy_cleanup(curl);
  
  return dir;

}

string GoogleChart::BuildUrl()
{
  string CurrentUrl = BaseURL;
  
  bool barChart = false;
  bool sparkLine = false;
  bool pieChart = false;
  bool isMap = false;
  
  // Chart type
  switch (m_type)
  {
    case ChartTypeBarHorizontalStacked:
      CurrentUrl.append("cht=bhs");
      barChart = true;
      break;
    case ChartTypeBarVerticalStacked:
      CurrentUrl.append("cht=bvs");
      barChart = true;
      break;
    case ChartTypeBarVerticalOverlap:
      CurrentUrl.append("cht=bvo");
      barChart = true;
      break;
    case ChartTypeBarHorizontalGrouped:
      CurrentUrl.append("cht=bhg");
      barChart = true;
      break;
    case ChartTypeBarVerticalGrouped:
      CurrentUrl.append("cht=bvg");
      barChart = true;
      break;
    case ChartTypeLineChart:
      CurrentUrl.append("cht=lc");
      break;
    case ChartTypeLineChartSparkLine:
      CurrentUrl.append("cht=ls");
      sparkLine = true;
      break;
    case ChartTypePie:
      CurrentUrl.append("cht=p");
      pieChart = true;
      break;
    case ChartTypePie3D:
      CurrentUrl.append("cht=p3");
      pieChart = true;
      break;
    case ChartTypeThematicMap:
      CurrentUrl.append("cht=t");
      isMap = true;
      break;
    default:
      CurrentUrl.append("cht=bhs");
      barChart = true;
      break;
  }
  
  char buff[512];
  
  //make size
  sprintf(buff, "&chs=%dx%d", m_width, m_height);
  CurrentUrl.append(buff);
  
  //Add Data
   CurrentUrl.append("&chd=t:");
  for (int i = 0; i < m_dataSets.size(); i++)
  {
    for (int j = 0; j < m_dataSets[i]->data.size(); j++)
    {
      sprintf(buff, "%d",m_dataSets[i]->data[j]);
      CurrentUrl.append(buff);
      
      if(j < m_dataSets[i]->data.size()-1)
        CurrentUrl.append(",");
    }
    if(i < m_dataSets.size()-1)
    CurrentUrl.append("|");
  }
  
  
  CurrentUrl.append("&chco=");
  for (int i = 0; i < m_dataSets.size(); i++)
  {
    
    sprintf(buff, "%s",m_dataSets[i]->colour.c_str());
    CurrentUrl.append(buff);
    
    if(i < m_dataSets.size()-1)
      CurrentUrl.append(",");
  }
  
  //Add Chart Title
  std::replace( m_title.begin(), m_title.end(), ' ', '+');
  sprintf(buff, "&chtt=%s", m_title.c_str());
  CurrentUrl.append(buff);
  
  return CurrentUrl;
}