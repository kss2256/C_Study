#include <iostream>

using namespace std;

/*
    5	        2
    6	        2
    5000	    5
*/


int solution(int n)
{
    int ans = 0;
    int temp = n;

    while (temp > 0)
    {
        if (temp == 1)
        {
            ++ans;
            temp = 0;
        }
        if (temp % 2 != 0)
        {
            ++ans;
        }
        temp /= 2;

    }



    return ans;
}

int main()
{

    int result = solution(5000);

    std::cout << result << std::endl;

    return 0;
}