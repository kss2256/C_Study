#include <vector>
#include <string>
#include <sstream>

using namespace std;


/*
문제 설명
JadenCase란 모든 단어의 첫 문자가 대문자이고, 그 외의 알파벳은 소문자인 문자열입니다. 
단, 첫 문자가 알파벳이 아닐 때에는 이어지는 알파벳은 소문자로 쓰면 됩니다. (첫 번째 입출력 예 참고)
문자열 s가 주어졌을 때, s를 JadenCase로 바꾼 문자열을 리턴하는 함수, solution을 완성해주세요.

제한 조건
s는 길이 1 이상 200 이하인 문자열입니다.
s는 알파벳과 숫자, 공백문자(" ")로 이루어져 있습니다.
숫자는 단어의 첫 문자로만 나옵니다.
숫자로만 이루어진 단어는 없습니다.
공백문자가 연속해서 나올 수 있습니다.

입출력 예

        s	                            return
"3people unFollowed me"	        "3people Unfollowed Me"
"for the last week"	            "For The Last Week"

*/


//대문자로 변환 
int mytoupper(int s)
{
    //소문자 지워주고 대문자 더해주기
    if ((s >= 'a') && (s <= 'z'))
    {
        s = s - 'a' + 'A';
    }

    return s;
}

//소문자로 변환
int mytolower(int s)
{
    //대문자 지워주고 소문자 더해주기
    if ((s >= 'A') && (s <= 'Z'))
    {
        s = s - 'A' + 'a';
    }

    return s;

}


string solution(string s)
{
    string answer = "";

    bool cheak = false;

    for (size_t i = 0; i < s.size(); ++i)
    {
        if (i == 0)
        {
            s[i] = mytoupper(s[i]);
		}
        else
		s[i] = mytolower(s[i]);

		if (cheak)
		{
			s[i] = mytoupper(s[i]);
			cheak = false;
		}

        if (s[i] == ' ')
        {
            cheak = true;
        }
    }
   
    return s;
}


int main()
{
    string result = solution("3people unFollowed me");
  


	return 0;
}