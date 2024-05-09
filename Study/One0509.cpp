#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


/*
문제 설명
0과 1로 이루어진 어떤 문자열 x에 대한 이진 변환을 다음과 같이 정의합니다.

x의 모든 0을 제거합니다.
x의 길이를 c라고 하면, x를 "c를 2진법으로 표현한 문자열"로 바꿉니다.
예를 들어, x = "0111010"이라면, x에 이진 변환을 가하면 x = "0111010" -> "1111" -> "100" 이 됩니다.

0과 1로 이루어진 문자열 s가 매개변수로 주어집니다. 
s가 "1"이 될 때까지 계속해서 s에 이진 변환을 가했을 때, 
이진 변환의 횟수와 변환 과정에서 제거된 모든 0의 개수를 각각 배열에 담아 
return 하도록 solution 함수를 완성해주세요.

제한사항
s의 길이는 1 이상 150,000 이하입니다.
s에는 '1'이 최소 하나 이상 포함되어 있습니다.

입출력 예
s	                result
"110010101001"	    [3,8]
"01110"	            [3,3]
"1111111"	        [4,1]

*/

//

vector<int> solution(string s) 
{
    vector<int> answer;
    int zero = 0, one = 0, Cheak = 0; //Cheak가 반복 횟수를 저장할 변수, zero는 반복하면서 나온 총 0의 개수
    vector<int> result;               //result는 2진 변환 값을 계속 업데이트              
   
    
    while (result.size() != 1)
    {
        result.clear();
        ++Cheak;
        //1회차
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '1')
                ++one;
            else
                ++zero;
        }

        //1의 개수를 더해서 그 값을 2진변환 해서 result에 업데이트
        while (one > 1)
        {
            result.push_back(one % 2);
            one /= 2;
        }
        result.push_back(one);  //마지막에 0 혹은 1이 되고 그 값을 넣어주고

        reverse(result.begin(), result.end());  //거꾸로 들어갔으니 바꿔준다.
        one = 0;
        s.clear();                              //s 비워주고 나눠진 값을 합쳐줌
        for (int j = 0; j < result.size(); j++)
        {
            s += to_string(result[j]);
        }
        
    }

	answer = { Cheak , zero };


    return answer;
}


int main()
{

    vector<int> result = solution("110010101001");
    //vector<int> result = solution("0111010");




    return 0;
}