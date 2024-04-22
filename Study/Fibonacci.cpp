#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



int solution(int n) 
{
    int answer = 0;
    

    int a = 0, b = 1;

    for (int i = 2; i <= n; ++i) 
    {
        int sum = (a + b) % 1234567;
        a = b;
        b = sum;
    }
    answer = b;
    return answer;
}

int main() 
{
    int a = solution(3);



    return 0;
}