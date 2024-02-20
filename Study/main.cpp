#include <iostream>
#include <map>

#include "ksVector.h"
#include "ksList.h"
#include "ksStack.h"
#include "ksCircleQue.h"
#include "ksTree.h"



int main()
{

	ks::Vector<int, true> test;

	
	test.push_Back(5);
	test.push_Back(1);	
	test.push_Back(3);
	test.push_Back(8);
	test.push_Back(2);


	for (size_t i = 0; i < test.size(); i++)
	{
		std::cout << test[i] << std::endl;
	}

	


	return 0;
}