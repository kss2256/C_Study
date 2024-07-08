#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    int sign = 1;
    vector<int> result;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '-')
        {
            sign = -1;
        }
        else if (s[i] == '+')
        {
            sign = 1;
        }
        else
            result.push_back(char(s[i] - '0'));
    }

    //»çÀÌÁî 4 / 1, 2, 3, 4

    for (int i = 0; i < result.size(); i++)
    {
        answer = answer * 10 + result[i];
    }

    return answer * sign;
}



int main()
{

    int result = solution("1234");


    return 0;
}