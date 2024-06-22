#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int T = 0, Y = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'p' || s[i] == 'P')
            ++T;
        if (s[i] == 'y' || s[i] == 'Y')
            ++Y;
    }


    return T == Y;
}

int main()
{

    bool result = solution("pPoooyY");

    return 0;
}