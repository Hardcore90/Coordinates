#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include <locale>
using namespace std;
int main()
{
/*Задание №1

Реализуйте программу, которая считывает из файла наборы координат и выводит только те координаты, которые расположены в квадрате :

Широта: от 50 до 80

Долгота : от 20 до 45 */

	setlocale(LC_ALL, "Russian");

	ifstream ifile("coordinates.txt", ios::in);
	if (ifile.is_open()) 
	{	
		
		bool flag = false;
		while (!ifile.eof())
		{		
			string line;
			double lat, lon;			
			getline(ifile, line);
			//cout << line << endl;
			stringstream ss(line);
			ss.ignore(1);
			ss >> lat;
			ss.ignore(2);
			ss >> lon;
			
			if (lat > 50 && lon > 20)
			{			
				if (lat < 80 && lon < 45)
				{
					cout << lat << ", " << lon << endl;
					cout << endl;
					flag = true;
				}							
			}	
		}
		if (flag == false)
		{
			cout << "Нет соответсвующих координат!" << endl;
		}
	}
	

	return 0;
}

