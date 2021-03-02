#include <iostream>
#include <iomanip>
#include <string>
#include "strutils.h"



using namespace std;


bool InputCheck( string color, string height, string length , string width)
{
	
        
			if ( atof(height) <= 0 )
			{
				cout << "Invalid entry for " << color << " cuboid. Dimensions should be positive real numbers!" << endl;
				return false ;
			}
		    if (atof(length) <= 0 )
			{
				cout << "Invalid entry for " << color << " cuboid. Dimensions should be positive real numbers!" << endl;
				return false ;
			}

			if ( atof(width) <= 0 )
			{
				cout << "Invalid entry for " << color << " cuboid. Dimensions should be positive real numbers!" << endl;
				return false ;
			}

		return true ;
}


void CubeControlFunc ( string color, double height, double length , double width)
 {

	 if ( length == height && height == width)
	 {
		cout << color << " cuboid is a cube."  ;
		cout << endl ;
	 }

	 else
	 {
		 cout << color << " cuboid is not a cube."  ;
		 cout << endl ;
	 }
	 
 }

void AreaVolumeDisplay(string color , double area, double volume)
 {
	 cout << "Results for the " << color << " cuboid:" << endl ;
	 cout << "Area: " << area << endl;
	 cout << "Volume: " << volume << endl;
	 
 }


void CalculateFunc(string color, double height, double length , double width, double &Area, double & Volume)
{
	Area = 2 * (height * width + width * length + height * length) ;
	Volume = height * width * length ;
	AreaVolumeDisplay(color, Area, Volume ) ;
	CubeControlFunc(color, height, length, width) ;
	cout << endl ;
}

string CompareFunc( string color1, string color2 , string method , double color1value , double color2value)
{
	
	string s ;
    if( color1value > color2value)
	{
		s= color1 + " has the largest " + method + "." ;
		return s ;
	}
	else if(color2value > color1value)
	{
		s= color2 + " has the largest " + method + "." ;
		return s;
	}
	else 
	{
		s = "Two cuboids have the same " + method + "." ;
		return s;
	}
 
}


 int main ()
{
	 cout.setf(ios::fixed);
	 cout.precision(2);
	
	 string color_first , color_second , a_1 ,b_1 , volume, area ,  first_length , first_width, first_height , second_length , second_width, second_height;
	 double Area_1 , Area_2 , Volume_1 , Volume_2 ;
	 cout << "Hello! This program compares two cuboids..."  << endl;
	 cout << "Please enter colors for the two cuboids: "  ;
	 cin >> color_first >> color_second ;
	
	 a_1 = color_first ;
	 b_1 = color_second ;
	 ToUpper(a_1) ;
	 ToUpper(b_1) ;
	 
	 if ( color_first == color_second || a_1 == b_1 )
	 {
		 cout << "Color names cannot be the same, good bye..." << endl ;
	 }

	 else if(color_first != color_second && a_1 != b_1 )
	 { 
		 cout << "Please enter length, width and height of the " << color_first << " cuboid: " ;
		 cin >> first_length >> first_width >> first_height ;
		 
		 
		 if (InputCheck( color_first, first_height, first_length , first_width))
		 {
			 
			 cout << "Please enter length, width and height of the " << color_second << " cuboid: "  ;
			 cin >> second_length >> second_width >> second_height ;
			 if (InputCheck( color_second, second_height, second_length , second_width))
			 {
				CalculateFunc( color_first, atof(first_height), atof(first_length), atof(first_width), Area_1, Volume_1) ;
				
				CalculateFunc( color_second, atof(second_height), atof(second_length), atof(second_width), Area_2 , Volume_2) ;
				
				string comparison1 = CompareFunc(color_first, color_second, "volume", Volume_1, Volume_2)  ;
				string comparison2 = CompareFunc(color_first, color_second, "area" , Area_1, Area_2) ;
				
				cout << "Comparison of the two cuboids:" << endl ;
				cout << comparison1 << endl ;
				cout << comparison2 << endl ;
			 }
		 }
	 }
	 
}
