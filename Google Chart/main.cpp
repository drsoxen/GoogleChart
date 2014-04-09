//
//  main.cpp
//  Google Chart
//
//  Created by Chris Ziraldo on 2013-09-19.
//  Copyright (c) 2013 Chris Ziraldo. All rights reserved.
//

#include <iostream>
#include "Charter.h"

int main(int argc, const char * argv[])
{
  
  g_GoogleChart.InitChart(ChartTypeBarVerticalGrouped, "Test Chart", 320, 480, 0, 100);
  ChartDataSet* one = new ChartDataSet();
  one->colour = C_RED;
  one->data.push_back(10);
  one->data.push_back(30);
  one->data.push_back(50);
  one->data.push_back(70);

  g_GoogleChart.addDataSet(one);

  ChartDataSet* two = new ChartDataSet();
  two->colour = C_BLUE;
  two->data.push_back(20);
  two->data.push_back(40);
  two->data.push_back(60);
  two->data.push_back(80);

  g_GoogleChart.addDataSet(two);
 
  g_GoogleChart.GetChart();

  system("qlmanage -p Chart.jpg");
  
  return 0;
}

