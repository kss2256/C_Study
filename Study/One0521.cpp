#include <string>
#include <vector>

using namespace std;


/*
���� ����
Finn�� ���� ���а��ο� ���� �ֽ��ϴ�. ���� ���θ� �ϴ� Finn�� �ڿ��� n�� 
������ �ڿ������ ǥ�� �ϴ� ����� ��������� ����� �˰� �Ǿ����ϴ�. 
������� 15�� ������ ���� 4������ ǥ�� �� �� �ֽ��ϴ�.

1 + 2 + 3 + 4 + 5 = 15
4 + 5 + 6 = 15
7 + 8 = 15
15 = 15
�ڿ��� n�� �Ű������� �־��� ��, ���ӵ� �ڿ������ n�� ǥ���ϴ� 
����� ���� return�ϴ� solution�� �ϼ����ּ���.

���ѻ���
n�� 10,000 ������ �ڿ��� �Դϴ�.
����� ��
n	result
15	4
����� �� ����
����� ��#1
������ ���ÿ� �����ϴ�.

*/



int solution(int n) 
{
    
    int answer = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (i == n)
        {
            return ++answer;
        }

        int sum = i + 1;
        int result = sum + i;

        while (result <= n)
        {
            if (result == n)
            {
                ++answer;
                break;
            }
            else if (result > n)
                break;

            ++sum;
            result += sum;
        }

    }

   


    return answer;
}


int main()
{

    int result = solution(15);



    return 0;
}