#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
    1. 격자의 총 갯수를 알고있다.
    2. 가로가 세로보다 크거나 최소한 같아야 한다.

    예외 처리
    갈색 격자의 수 brown은 8 이상 5,000 이하인 자연수입니다.
    노란색 격자의 수 yellow는 1 이상 2,000,000 이하인 자연수입니다.
    카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.


*/


//1트 실패 뭐가 문제인지 모르겠다
//vector<int> solution(int brown, int yellow) 
//{
//    //예외 처리 (가로세로 예외는 밑에서 바꿔줌)
//    if(brown < 8 || brown > 5000 || yellow < 1 || yellow > 2000000)
//      {
//          cout << "수량 제한 오류" << endl;
//      }
// 
//    vector<int> answer;
//    int Sum = brown + yellow;
//
//    //노랑색이 짝수일 경우
//    if (yellow % 2 == 0)
//    {
//        int half = yellow / 2;
//        int result = Sum % (half + 2);
//        while (result != 0)
//        {
//            half = half / 2;
//            result = Sum % (half + 2);
//        }
//
//        result = Sum / (half + 2);
//        if (result > half + 2)
//        {
//            answer.push_back(result);
//            answer.push_back(half + 2);
//        }
//        else
//        {
//            answer.push_back(half + 2);
//            answer.push_back(result);
//        }
//    }
//    //노랑색이 홀수일 경우
//    else
//    {
//        answer.push_back(yellow + 2);
//        answer.push_back(3);
//    }
//
//    return answer;
//}

/*
    1. 두 색상의 합 = 총 블럭의 갯수를 알수 있다.
    2. 반복문을 돌면서 하나씩 체크를 해보자
    3. 가로 세로 개수는?
    4. 노랑색 을 기준으로 해서 노랑색이 몇줄이던 하나씩 체크하면서
    가로로 +2 세로로 +2 해주면 되는데 여기에 총 블럭 개수를 알수 있으니깐
    5. 가로 >= 세로의 값이 나와야 하고 
	6. 가로나 세로나 전부 3줄 이상은 되어야 하니 3부터 시작 반복문 돌리면 될듯    

*/


//2트
vector<int> solution(int brown, int yellow)
{
	vector<int> result;

	//예외 처리 (가로세로 예외는 밑에서 바꿔줌)
	if (brown < 8 || brown > 5000 || yellow < 1 || yellow > 2000000)
	{
		cout << "수량 제한 오류" << endl;
	}

	//최소 라인줄이 3부터라 3부터 시작
	int blockTotal = brown + yellow;
	int col = 3;
	int row = 0;

	while (true)
	{
		//임의의 가로세로 값을 구해서 노랑색 개수 맞추면 된다
		row = blockTotal / col;

		if ((col - 2) * (row - 2) == yellow)
		{
			//가로 세로 예외 처리 큰놈이 가로로
			if (col > row)
			{
				result.push_back(col);
				result.push_back(row);
			}
			else
			{
				result.push_back(row);
				result.push_back(col);
			}
			break;
		}

		++col;
	}

	return result;
}



int main() 
{
    
    vector<int> result = solution(10, 2);
    
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << ",";
    }

    return 0;
}