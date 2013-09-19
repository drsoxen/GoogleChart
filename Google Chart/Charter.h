#ifndef __Charter__
#define __Charter__

#include <stdio.h>
#include <vector>
#include <string>
#include "Singleton.h"

using std::string;
using std::vector;

struct ChartDataSet
{
  ChartDataSet(){};
  
  string colour;
  vector<int> data;
};

enum ChartType
{
  // Bar Chart
  ChartTypeBarHorizontalStacked = 0,
  ChartTypeBarVerticalStacked,
  ChartTypeBarVerticalOverlap,
  ChartTypeBarHorizontalGrouped,
  ChartTypeBarVerticalGrouped,
  // Line Charts
  ChartTypeLineChart,
  ChartTypeLineChartSparkLine,
  ChartTypeLineChartXY,
  // Pie Charts
  ChartTypePie,
  ChartTypePie3D,
  ChartTypePieConcentric,
  // Visualization API
  ChartTypeThematicMap
};

enum ChartLegendPosition
{
  ChartLegendPositionLeft = 0,
  ChartLegendPositionRight,
  ChartLegendPositionTop,
  ChartLegendPositionBottom
};

enum ChartMapGeographicArea
{
  ChartMapGeographicAreaAfrica = 0,
  ChartMapGeographicAreaAsia,
  ChartMapGeographicAreaMiddleEast,
  ChartMapGeographicAreaSouthAmerica,
  ChartMapGeographicAreaUSA,
  ChartMapGeographicAreaWorld
};

class GoogleChart: public Singleton<GoogleChart>
{
public:
  
  void InitChart(ChartType type, string title, int height, int width);
  void addDataSet(ChartDataSet* dataSet);
  string GetChart();
  
private:
  friend class Singleton<GoogleChart>;
  GoogleChart(){};
  ~GoogleChart(){};
  
  string BuildUrl();
  
  string BaseURL;
  std::vector<ChartDataSet*> m_dataSets;
  ChartType m_type;
  string m_title;
  int m_height;
  int m_width;
};

#define g_GoogleChart GoogleChart::Ref()

#define C_ALICEBLUE	"F0F8FF"
#define C_ANTIQUEWHITE	"FAEBD7"
#define C_AQUA	"00FFFF"
#define C_AQUAMARINE	"7FFFD4"
#define C_AZURE	"F0FFFF"
#define C_BEIGE	"F5F5DC"
#define C_BISQUE	"FFE4C4"
#define C_BLACK	"000000"
#define C_BLANCHEDALMOND	"FFEBCD"
#define C_BLUE	"0000FF"
#define C_BLUEVIOLET	"8A2BE2"
#define C_BROWN	"A52A2A"
#define C_BURLYWOOD	"DEB887"
#define C_CADETBLUE	"5F9EA0"
#define C_CHARTREUSE	"7FFF00"
#define C_CHOCOLATE	"D2691E"
#define C_CORAL	"FF7F50"
#define C_CORNFLOWERBLUE	"6495ED"
#define C_CORNSILK	"FFF8DC"
#define C_CRIMSON	"DC143C"
#define C_CYAN	"00FFFF"
#define C_DARKBLUE	"00008B"
#define C_DARKCYAN	"008B8B"
#define C_DARKGOLDENROD	"B8860B"
#define C_DARKGRAY	"A9A9A9"
#define C_DARKGREEN	"006400"
#define C_DARKKHAKI	"BDB76B"
#define C_DARKMAGENTA	"8B008B"
#define C_DARKOLIVEGREEN	"556B2F"
#define C_DARKORANGE	"FF8C00"
#define C_DARKORCHID	"9932CC"
#define C_DARKRED	"8B0000"
#define C_DARKSALMON	"E9967A"
#define C_DARKSEAGREEN	"8FBC8F"
#define C_DARKSLATEBLUE	"483D8B"
#define C_DARKSLATEGRAY	"2F4F4F"
#define C_DARKTURQUOISE	"00CED1"
#define C_DARKVIOLET	"9400D3"
#define C_DEEPPINK	"FF1493"
#define C_DEEPSKYBLUE	"00BFFF"
#define C_DIMGRAY	"696969"
#define C_DODGERBLUE	"1E90FF"
#define C_FIREBRICK	"B22222"
#define C_FLORALWHITE	"FFFAF0"
#define C_FORESTGREEN	"228B22"
#define C_FUCHSIA	"FF00FF"
#define C_GAINSBORO	"DCDCDC"
#define C_GHOSTWHITE	"F8F8FF"
#define C_GOLD	"FFD700"
#define C_GOLDENROD	"DAA520"
#define C_GRAY	"808080"
#define C_GREEN	"008000"
#define C_GREENYELLOW	"ADFF2F"
#define C_HONEYDEW	"F0FFF0"
#define C_HOTPINK	"FF69B4"
#define C_INDIANRED	"CD5C5C"
#define C_INDIGO	"4B0082"
#define C_IVORY	"FFFFF0"
#define C_KHAKI	"F0E68C"
#define C_LAVENDER	"E6E6FA"
#define C_LAVENDERBLUSH	"FFF0F5"
#define C_LAWNGREEN	"7CFC00"
#define C_LEMONCHIFFON	"FFFACD"
#define C_LIGHTBLUE	"ADD8E6"
#define C_LIGHTCORAL	"F08080"
#define C_LIGHTCYAN	"E0FFFF"
#define C_LIGHTGOLDENRODYELLOW	"FAFAD2"
#define C_LIGHTGRAY	"D3D3D3"
#define C_LIGHTGREEN	"90EE90"
#define C_LIGHTPINK	"FFB6C1"
#define C_LIGHTSALMON	"FFA07A"
#define C_LIGHTSEAGREEN	"20B2AA"
#define C_LIGHTSKYBLUE	"87CEFA"
#define C_LIGHTSLATEGRAY	"778899"
#define C_LIGHTSTEELBLUE	"B0C4DE"
#define C_LIGHTYELLOW	"FFFFE0"
#define C_LIME	"00FF00"
#define C_LIMEGREEN	"32CD32"
#define C_LINEN	"FAF0E6"
#define C_MAGENTA	"FF00FF"
#define C_MAROON	"800000"
#define C_MEDIUMAQUAMARINE	"66CDAA"
#define C_MEDIUMBLUE	"0000CD"
#define C_MEDIUMORCHID	"BA55D3"
#define C_MEDIUMPURPLE	"9370DB"
#define C_MEDIUMSEAGREEN	"3CB371"
#define C_MEDIUMSLATEBLUE	"7B68EE"
#define C_MEDIUMSPRINGGREEN	"00FA9A"
#define C_MEDIUMTURQUOISE	"48D1CC"
#define C_MEDIUMVIOLETRED	"C71585"
#define C_MIDNIGHTBLUE	"191970"
#define C_MINTCREAM	"F5FFFA"
#define C_MISTYROSE	"FFE4E1"
#define C_MOCCASIN	"FFE4B5"
#define C_NAVAJOWHITE	"FFDEAD"
#define C_NAVY	"000080"
#define C_OLDLACE	"FDF5E6"
#define C_OLIVE	"808000"
#define C_OLIVEDRAB	"6B8E23"
#define C_ORANGE	"FFA500"
#define C_ORANGERED	"FF4500"
#define C_ORCHID	"DA70D6"
#define C_PALEGOLDENROD	"EEE8AA"
#define C_PALEGREEN	"98FB98"
#define C_PALETURQUOISE	"AFEEEE"
#define C_PALEVIOLETRED	"DB7093"
#define C_PAPAYAWHIP	"FFEFD5"
#define C_PEACHPUFF	"FFDAB9"
#define C_PERU	"CD853F"
#define C_PINK	"FFC0CB"
#define C_PLUM	"DDA0DD"
#define C_POWDERBLUE	"B0E0E6"
#define C_PURPLE	"800080"
#define C_RED	"FF0000"
#define C_ROSYBROWN	"BC8F8F"
#define C_ROYALBLUE	"4169E1"
#define C_SADDLEBROWN	"8B4513"
#define C_SALMON	"FA8072"
#define C_SANDYBROWN	"F4A460"
#define C_SEAGREEN	"2E8B57"
#define C_SEASHELL	"FFF5EE"
#define C_SIENNA	"A0522D"
#define C_SILVER	"C0C0C0"
#define C_SKYBLUE	"87CEEB"
#define C_SLATEBLUE	"6A5ACD"
#define C_SLATEGRAY	"708090"
#define C_SNOW	"FFFAFA"
#define C_SPRINGGREEN	"00FF7F"
#define C_STEELBLUE	"4682B4"
#define C_TAN	"D2B48C"
#define C_TEAL	"008080"
#define C_THISTLE	"D8BFD8"
#define C_TOMATO	"FF6347"
#define C_TURQUOISE	"40E0D0"
#define C_VIOLET	"EE82EE"
#define C_WHEAT	"F5DEB3"
#define C_WHITE	"FFFFFF"
#define C_WHITESMOKE	"F5F5F5"
#define C_YELLOW	"FFFF00"
#define C_YELLOWGREEN	"9ACD32"

#endif /* defined(__Charter__) */



