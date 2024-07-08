#include <iostream>

using namespace std; 

/*
	���ڸ� ���� �˰����� �ϳ�.
	0�� �ε��� ���� ������ 
	1�� �ε��� ���� ������
	�̷���..

	O(n^2)

*/


//���� ����
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