#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


/*
    ������ n���� �޾� �� n�� ����� ������
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