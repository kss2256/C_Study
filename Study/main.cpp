#include <iostream>

#include "ksVector.h"
#include "ksList.h"
#include "ksStack.h"
#include "ksCircleQue.h"
#include "ksTree.h"


bool Up(int x, int y) { return x > y; }
bool Down(int x, int y) { return x < y; }

bool Up(float x, float y) { return x > y; }
bool Down(float x, float y) { return x < y; }


int main()
{

	ks::Vector<float> myVector;

	myVector.push_Back(10.21f);
	myVector.push_Back(10.2f);
	myVector.push_Back(10.1f);
	myVector.push_Back(35.2f);
	myVector.push_Back(25.1f, Up);

	for (size_t i = 0; i < myVector.size(); i++)
	{
		std::cout << myVector[i] << std::endl;
	}



	return 0;
}