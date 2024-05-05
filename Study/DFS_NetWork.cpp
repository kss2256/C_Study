#include <string>
#include <vector>
#include <queue>
#include <iostream>


using namespace std;



// [1, 1, 0]
// [1, 1, 0]
// [0, 0, 1]
int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    vector<bool>visit(n, false);
    std::queue<int> q;

    for (int i = 0; i < n; ++i)
    {

        if (visit[i] == false)
        {
            ++answer;
            visit[i] = true;
            q.push(i);
        }

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            for (int j = 0; j < computers[temp].size(); ++j)
            {
                if (computers[temp][j] == 1 && visit[j] == false)
                {
                    q.push(j);
                    visit[j] = true;
                }
            }
        }


    }


    return answer;
}



int main()
{
    //[[1, 0, 0], [1, 1, 0], [0, 0, 1]]
    //4, [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]]  = 4
    //5, [1,1,0,1,0], [1, 1, 0, 0, 0], [0,0,1,0,1], [1,0,0,1,1], [0,0,1,1,1] = 1

    vector<vector<int>> netWork =
    {
		{1, 1, 0},
		{1, 1, 0},
		{0, 0, 1},
    };

    int test = solution(3, netWork);

    std::cout << test;


    return 0;
}

