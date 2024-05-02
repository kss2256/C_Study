#include <string>
#include <vector>
#include <iostream>

using namespace std;


/*
0과 1로 이루어진 2n x 2n 크기의 2차원 정수 배열 arr이 있습니다. 
당신은 이 arr을 쿼드 트리와 같은 방식으로 압축하고자 합니다. 구체적인 방식은 다음과 같습니다.

당신이 압축하고자 하는 특정 영역을 S라고 정의합니다.
만약 S 내부에 있는 모든 수가 같은 값이라면, S를 해당 수 하나로 압축시킵니다.
그렇지 않다면, S를 정확히 4개의 균일한 정사각형 영역(입출력 예를 참고해주시기 바랍니다.)으로 쪼갠 뒤,
각 정사각형 영역에 대해 같은 방식의 압축을 시도합니다.
arr이 매개변수로 주어집니다. 위와 같은 방식으로 arr을 압축했을 때, 
배열에 최종적으로 남는 0의 개수와 1의 개수를 배열에 담아서 return 하도록 solution 함수를 완성해주세요.
*/

/*
    [1, 1, 0, 0]
    [1, 0, 0, 0]
    [1, 0, 0, 1]
    [1, 1, 1, 1]
*/

/*
    col * row 칸의 배열 / 4 의 값이 중요
    4로 나눈 값이 다음 4개의 배열 개수 값이 됨.

    
    64 / 4 = 16  16칸의 배열 (col = 4 , row = 4)
    16 / 4 = 4   4 칸의 배열 <- 값이 4면 끝           
    

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
				//1사분면
				if (col >= colhalf && row < rowhalf)
				{
					calculate[0].push_back(calculateClone[row][col]);
				}
				//2사분면
				else if (col < colhalf && row < rowhalf)
				{
					calculate[1].push_back(calculateClone[row][col]);
				}
				//3사분면
				else if (col < colhalf && row >= rowhalf)
				{
					calculate[2].push_back(calculateClone[row][col]);
				}
				//4사분면
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