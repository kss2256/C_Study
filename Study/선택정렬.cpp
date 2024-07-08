#include <iostream>

using namespace std; 

/*
	제자리 정렬 알고리즘의 하나.
	0번 인덱스 제일 작은거 
	1번 인덱스 제일 작은거
	이런식..

	O(n^2)

*/


//선택 정렬
void SelectSort(int* data, int arraysize)
{
	int temp = 0, idx = 0, min = 0;

	for (int i = 0; i < arraysize; ++i)
	{
		min = INT32_MAX;
		for (int j = i; j < arraysize; ++j)
		{
			//{1, 10, 5, 8, 7, 6, 4, 3, 2, 9}
			if (min > data[j])
			{
				min = data[j];
				idx = j;
			}
		}

		temp = min;
		data[idx] = data[i];
		data[i] = min;
	}

}




int main()
{

	int date[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	
	

	SelectSort(date, 10);


	
	for (int i = 0; i < sizeof(date) / 4; ++i)
	{
		cout << date[i] << endl;
	}



	return 0;
}