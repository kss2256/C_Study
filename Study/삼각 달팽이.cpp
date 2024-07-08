#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) 
{
    vector<int> answer;

    vector<vector<int>> result(n + 1, vector<int>(n + 1, 0));

    //아래, 오른쪽, 대각선
    int dx[] = {0, 1, -1 };
    int dy[] = {1, 0, -1 };

    int count = 0, idx = 0, curX = 0, curY = 0;

   
    while (true)
    {
        result[curY][curX] = ++count;
        int nextX = curX + dx[idx];
        int nextY = curY + dy[idx];

        if (nextX == n || nextY == n || result[nextY][nextX] != 0) 
        {
            idx = (idx + 1) % 3;
            nextX = curX + dx[idx];
            nextY = curY + dy[idx];
            if (nextX == n || nextY == n || result[nextY][nextX] != 0)
                break;
        }
        curX = nextX;
        curY = nextY;
      
    }
    
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            if (result[i][j] != 0)
            {
                answer.push_back(result[i][j]);
            }

        }

    }

    return answer;
}


int main()
{
    vector<int> result = solution(4);


    return 0;
}