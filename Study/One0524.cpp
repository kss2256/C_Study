#include <string>
#include <vector>

using namespace std;

/*

문제 설명
가로, 세로 길이가 n인 정사각형으로된 체스판이 있습니다. 
체스판 위의 n개의 퀸이 서로를 공격할 수 없도록 배치하고 싶습니다.

예를 들어서 n이 4인경우 다음과 같이 퀸을 배치하면 n개의 퀸은 서로를 한번에 공격 할 수 없습니다.


체스판의 가로 세로의 세로의 길이 n이 매개변수로 주어질 때, n개의 퀸이 조건에 만족 하도록 
배치할 수 있는 방법의 수를 return하는 solution함수를 완성해주세요.

*/


//대각선 + 가로 검사 
bool attack(const vector<int>& queens, int row, int col) 
{
    for (int i = 0; i < row; ++i)
    {
        //퀸의 개수만큼 가로열과 대각선 검사
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