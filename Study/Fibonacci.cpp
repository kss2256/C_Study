#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

////1234567�������� �ᱹ ���Ƽ� �������?�ߴµ� �ʹ� ������ �ȵǳ�
int solution(int n)
{
    if (n < 2 || n >= 100000)
        return 0;

    int value = 0;
    if (n <= 1)
        return n;
    
    return solution(n - 2) + solution(n - 1);
}




//������� �غ����� �����ɸ��Ű��Ƽ� �������� ������
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