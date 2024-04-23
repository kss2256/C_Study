#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

////1234567나머지는 결국 같아서 상관없나?했는데 너무 느려서 안되나
int solution(int n)
{
    if (n < 2 || n >= 100000)
        return 0;

    int value = 0;
    if (n <= 1)
        return n;
    
    return solution(n - 2) + solution(n - 1);
}




//꼬리재귀 해보려다 오래걸릴거같아서 포문으로 마무리
int solution(int n) 
{
    if (n < 2 || n >= 100000)
        return 0;

    int one = 0, two = 1;

    for (int i = 2; i <= n; ++i) 
    {
        int sum = (one + two) % 1234567;
        one = two;
        two = sum;
    }
    
    return two;
}

int main() 
{
    int a = solution(90000);

    printf("%d", a);

    return 0;
}