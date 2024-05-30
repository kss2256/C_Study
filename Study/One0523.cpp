#include <string>
#include <vector>

using namespace std;



/*
문제 설명
어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.

예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 이 중 가장 큰 숫자는 94 입니다.

문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다. number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.

제한 조건
number는 2자리 이상, 1,000,000자리 이하인 숫자입니다.
k는 1 이상 number의 자릿수 미만인 자연수입니다.
입출력 예

number	        k	return
"1924"	        2	"94"            4 - 2   = 2     3
"1231234"	    3	"3234"          7 - 3   = 4     4
"1231234"	    2	"32341"         7 - 2   = 5     3
"4177252841"	4	"775841"       10 - 4   = 6     5
*/

string solution(string number, int k)
{
    string answer = "";
    vector<int> result;
    //diff = 자리수
    int diff = number.length() - k;
    //2차원 배열 
    int diff2 = number.length() - (k - 1);

    for (int i = 0; i < number.length(); ++i)
    {
        result.push_back(number[i] - '0');
    }

    //자리수 만큼 반복문 돌고
    for (int i = 0; i <= number.length() - diff; ++i)
    {
      for(int j = 0 ; j < )



    }




    return answer;
}



int main()
{

    string result = solution("1924", 2);


    return 0;
}