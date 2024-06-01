#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while (a != b)
    {
        ++answer;
        a = (a / 2) + (a % 2);
        b = (b / 2) + (b % 2);
    }

    return answer;
}


int main()
{

    int result = solution(8,4,7);



    return 0;
}