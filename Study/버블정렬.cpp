#include <iostream>

using namespace std;

/*
	���� ������ �� ���Ҹ� �˻��Ͽ� �����ϴ� �˰���
	������ 2���� ���ڵ带 ���Ͽ� ũ�Ⱑ ������� �Ǿ� ���� ������ ���� ��ȯ�Ѵ�.

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