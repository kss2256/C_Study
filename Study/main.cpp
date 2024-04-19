#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <algorithm>

#include "ksVector.h"
#include "ksList.h"
#include "ksStack.h"
#include "ksCircleQue.h"
#include "ksTree.h"



bool Up(int x, int y) { return x > y; }
bool Down(int x, int y) { return x < y; }

bool Up(float x, float y) { return x > y; }
bool Down(float x, float y) { return x < y; }


//void TEST(int _x, int _y)
//{
//	for (int i = 0; i < _x; i++)
//	{
//		for (int j = 0; j < _y; j++)
//		{
//			if (i == 0 || i == _x - 1 || j == 0 || j == _y - 1)
//			{
//				std::cout << "*";
//			}		
//			else
//			{
//				std::cout << " ";
//			}
//		}
//		std::cout << "\n";
//	}
//}

void TEST(int _x, int _y)
{
	for (int i = 1; i < _x + 1; i++)
	{
		for (int j = 1; j < _y + 1; j++)
		{
			if (i == 1 || i == _x || j == 1 || j == _y)
			{
				std::cout << "*";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}

double Sqrt(double n)
{
	double s = 0;
	double t = 0;

	s = n / 2;
	for (; s != t;)
	{
		t = s;
		s = ((n / t) + t) / 2;
	}
	return s;
}




int main()
{
	
	ks::Vector<float> myVector;

	myVector.push_Back(10.21f);
	myVector.push_Back(10.2f);
	myVector.push_Back(10.1f);
	myVector.push_Back(35.2f);
	myVector.push_Back(25.1f, Up);

	std::vector<int> cardinal;
	cardinal.push_back(1);
	cardinal.push_back(2);
	cardinal.push_back(3);
	cardinal.push_back(4);


	
	

	auto Lamda = [value = 6](float x)->int
		{
			return value + x;
		};

	float test = Lamda(5.2);


	TEST(5,4);

	float PI = 3.141592;

	float Radian;
	float Degree;

	Radian = (180 * PI) / 180;
	Degree = (1 * 180) / PI;

	

	std::cout << Radian << std::endl;
	std::cout << Degree<< std::endl;



	


	return 0;
}