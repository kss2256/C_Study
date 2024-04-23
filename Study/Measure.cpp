#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


/*
    임의의 n수를 받아 그 n의 약수를 골라오기
*/

int solution(int n) 
{
    int answer = 0;
    

    for (size_t i = 1; i <= n; i++)
    {
        if (n % i == 0)
            answer += i;
    }

    return answer;
}


int main()
{

    int a = solution(12);

    printf("%d",a);



    return 0;
}