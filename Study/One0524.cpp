#include <string>
#include <vector>

using namespace std;

/*

���� ����
����, ���� ���̰� n�� ���簢�����ε� ü������ �ֽ��ϴ�. 
ü���� ���� n���� ���� ���θ� ������ �� ������ ��ġ�ϰ� �ͽ��ϴ�.

���� �� n�� 4�ΰ�� ������ ���� ���� ��ġ�ϸ� n���� ���� ���θ� �ѹ��� ���� �� �� �����ϴ�.


ü������ ���� ������ ������ ���� n�� �Ű������� �־��� ��, n���� ���� ���ǿ� ���� �ϵ��� 
��ġ�� �� �ִ� ����� ���� return�ϴ� solution�Լ��� �ϼ����ּ���.

*/


//�밢�� + ���� �˻� 
bool attack(const vector<int>& queens, int row, int col) 
{
    for (int i = 0; i < row; ++i)
    {
        //���� ������ŭ ���ο��� �밢�� �˻�
        int quen = queens[i];
        if (quen == col || abs(quen - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}


int recursion(vector<int>& queens, int row, int n)
{
    if (row == n) 
        return 1;


    int count = 0;
    for (int col = 0; col < n; ++col)
    {
        if (attack(queens, row, col))
        {
            queens[row] = col;
            count += recursion(queens, row + 1, n);
        }
    }
    return count;
}



int solution(int n) 
{
    vector<int> queens(n, -1);

    return recursion(queens, 0, n);
}

#include <queue>



int main()
{

    int result = solution(4);

  



    return 0;
}