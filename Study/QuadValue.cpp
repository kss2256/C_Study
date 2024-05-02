#include <string>
#include <vector>
#include <iostream>

using namespace std;


/*
0�� 1�� �̷���� 2n x 2n ũ���� 2���� ���� �迭 arr�� �ֽ��ϴ�. 
����� �� arr�� ���� Ʈ���� ���� ������� �����ϰ��� �մϴ�. ��ü���� ����� ������ �����ϴ�.

����� �����ϰ��� �ϴ� Ư�� ������ S��� �����մϴ�.
���� S ���ο� �ִ� ��� ���� ���� ���̶��, S�� �ش� �� �ϳ��� �����ŵ�ϴ�.
�׷��� �ʴٸ�, S�� ��Ȯ�� 4���� ������ ���簢�� ����(����� ���� �������ֽñ� �ٶ��ϴ�.)���� �ɰ� ��,
�� ���簢�� ������ ���� ���� ����� ������ �õ��մϴ�.
arr�� �Ű������� �־����ϴ�. ���� ���� ������� arr�� �������� ��, 
�迭�� ���������� ���� 0�� ������ 1�� ������ �迭�� ��Ƽ� return �ϵ��� solution �Լ��� �ϼ����ּ���.
*/

/*
    [1, 1, 0, 0]
    [1, 0, 0, 0]
    [1, 0, 0, 1]
    [1, 1, 1, 1]
*/

/*
    col * row ĭ�� �迭 / 4 �� ���� �߿�
    4�� ���� ���� ���� 4���� �迭 ���� ���� ��.

    
    64 / 4 = 16  16ĭ�� �迭 (col = 4 , row = 4)
    16 / 4 = 4   4 ĭ�� �迭 <- ���� 4�� ��           
    

*/

vector<int> solution(vector<vector<int>> arr) 
{
    vector<int> answer;
    vector<vector<vector<int>>> calculate;
    vector<vector<int>> calculateClone;
    int colhalf = arr.size() / 2;
    int rowhalf = arr[0].size() / 2;
    int calculateCount = 0;



    calculate.resize(4);
    calculateClone = arr;

	while (colhalf % 2 == 0)
	{

		for (int row = 0; row < calculateClone.size(); ++row)
		{
			for (int col = 0; col < calculateClone[row].size(); ++col)
			{
				//1��и�
				if (col >= colhalf && row < rowhalf)
				{
					calculate[0].push_back(calculateClone[row][col]);
				}
				//2��и�
				else if (col < colhalf && row < rowhalf)
				{
					calculate[1].push_back(calculateClone[row][col]);
				}
				//3��и�
				else if (col < colhalf && row >= rowhalf)
				{
					calculate[2].push_back(calculateClone[row][col]);
				}
				//4��и�
				else if (col >= colhalf && row >= rowhalf)
				{
					calculate[3].push_back(calculateClone[row][col]);
				}
			}
		}
        calculateClone = calculate;
	}



    for (size_t i = 0; i < calculate.size(); i++)
    {
        for (size_t j = 0; j < calculate[i].size(); j++)
        {
            cout << calculate[i][j];
        }
        cout << endl;
    }




    return answer;
}


int main()
{
    vector<int> result;
    vector<vector<int>> values =
    {
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 1},
        {1, 1, 1, 1}
    };

   

   
    result = solution(values);

   /* for (size_t i = 0; i < values.size(); i++)
    {
        for (size_t j = 0; j < values[i].size(); j++)
        {
            cout << values[i][j];
        }
        cout << endl;
    }*/


    return 0;
}