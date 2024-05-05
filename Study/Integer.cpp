#include <string>
#include <vector>
#include <iostream>
#include <cmath>


using namespace std;

long long solution(int a, int b)
{
    long long answer = 0;

    if (a == b)
        return a;

    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    //등차 수열의 합 공식
    // S = n / 2 * (a + b)
    answer = (long long)(a + b) * (b - a + 1) / 2;
    



    return answer;
}

long long sym(long long value)
{
    long long answer = 0;

    float test  = sqrt(value);

    if (test - (int)test != 0)
    {
        return -1;
    }
    else
    {
        test += 1;

        answer = test * test;
    }

    return answer;
}


int main()
{

    long long test = 0;

    test = sym(121);

    std::cout << test;


    return 0;
 }