#include <iostream>

using namespace std;

/*
	서로 인접한 두 원소를 검사하여 정렬하는 알고리즘
	인접한 2개의 레코드를 비교하여 크기가 순서대로 되어 있지 않으면 서로 교환한다.

	O(n^2)

*/
void BubbleSort(int* data, int n)
{
	int temp = 0;
	for (int i = n - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (data[j] > data[j + 1])
			{
				temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
			}
		}
	}

}




int main()
{

	int date[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };


	BubbleSort(date, 10);



	for (int i = 0; i < 10; ++i)
	{
		cout << date[i] << endl;
	}



	return 0;
}