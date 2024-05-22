#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;


bool Compare(int left, int right)
{
    return left > right;
}

//int solution(vector<vector<int>> land) 
//{
//    int answer = 0;
//    queue<vector<int>> q;
//    vector<vector<bool>> visit(land.size(), vector<bool>(land[0].size(), false));
//    int result = 0;
//
//
//
//    for (int col = 0; col < land[0].size(); ++col)
//    {
//        //8 8 8 7 7 7 9 2
//        visit.assign(land.size(), std::vector<bool>(land[0].size(), false));
//        result = 0;
//        for (int row = 0; row < land.size(); ++row)
//        {
//            if (land[row][col] == 1 && visit[row][col] == false)
//            {
//                visit[row][col] = true;
//                q.push({ row,col });
//                ++result;
//
//                while (!q.empty())
//                {
//                    vector<int>idx = q.front();
//                    q.pop();
//
//                    //위 아래 좌  우
//                    if (idx[0] > 0)
//                    {
//                        if (visit[idx[0] - 1][idx[1]] == false && land[idx[0] - 1][idx[1]] == 1)
//                        {
//                            visit[idx[0] - 1][idx[1]] = true;
//                            q.push({ idx[0] - 1,idx[1] });
//                            ++result;
//                        }
//                    }                    
//                    if (idx[0] < land.size() - 1)
//                    {
//                        if (visit[idx[0] + 1][idx[1]] == false && land[idx[0] + 1][idx[1]] == 1)
//                        {
//                            visit[idx[0] + 1][idx[1]] = true;
//                            q.push({ idx[0] + 1,idx[1] });
//                            ++result;
//                        }
//                    }
//                    if (idx[1] > 0)
//                    {
//                        if (visit[idx[0]][idx[1] - 1] == false && land[idx[0]][idx[1] - 1] == 1)
//                        {
//                            visit[idx[0]][idx[1] - 1] = true;
//                            q.push({ idx[0] ,idx[1] - 1 });
//                            ++result;
//                        }
//                    }
//                    if (idx[1] < land[0].size() - 1)
//                    {
//                        if (visit[idx[0]][idx[1] + 1] == false && land[idx[0]][idx[1] + 1] == 1)
//                        {
//                            visit[idx[0]][idx[1] + 1] = true;
//                            q.push({ idx[0],idx[1] + 1 });
//                            ++result;
//                        }
//                    }
//                  
//
//                }
//                
//            }
//            if(result > answer)
//            answer = result;
//        }
//
//    }
//
//    
//    
//    
//    return answer;
//}


struct node 
{
public:

    bool visit = false;
    int number = -1;
};

int bfs(vector<vector<int>>& land, vector<vector<node>>& visit, int row, int col, int _idx)
{
    int result = 0;
    queue<vector<int>> q;
    visit[row][col].visit = true;
    visit[row][col].number = _idx;
    q.push({ row,col });
    
    vector<int> dirX = { -1, 1, 0, 0 };
    vector<int> dirY = { 0, 0, -1, 1 };

    while (!q.empty())
    {
        vector<int>idx = q.front();
        q.pop();
        ++result;

        for (int i = 0; i < 4; i++)
        {
            int nx = idx[0] + dirX[i];
            int ny = idx[1] + dirY[i];

            if (nx >= 0 && nx < land.size() && ny >= 0 && ny < land[0].size() &&
                !visit[nx][ny].visit && land[nx][ny] == 1) 
            {
                visit[nx][ny].visit = true;
                visit[nx][ny].number = _idx;
                q.push({ nx, ny });
            }
        }

    }


    return result;
}


int solution(vector<vector<int>> land)
{
    int answer = 0;
    vector<vector<node>> visits(land.size(), std::vector<node>(land[0].size()));
    vector<set<int>> s(land[0].size());
    vector<int> results, sum;
    int IDX = -1;

    // N x N 판에 있는 석유 덩어리 별로 저장 하기
    for (int col = 0; col < land[0].size(); ++col)
    {
        //8 8 8 7 7 7 9 2        
        for (int row = 0; row < land.size(); ++row)
        {
            if (land[row][col] == 1 && visits[row][col].visit == false)
            {
                ++IDX;
                results.push_back(bfs(land, visits, row, col, IDX));
            }
        }
    }

    //set 에 석유 덩어리 번호 추가하기 중복 X
    for (int i = 0; i < land[0].size(); ++i)
    {
        for (int j = 0; j < land.size(); ++j)
        {
            if (visits[j][i].visit == true)
            {
                s[i].insert(visits[j][i].number);
            }
        }
    }

    vector<vector<int>> itervec(s.size());

    for (int i = 0; i < s.size(); ++i)
    {
        itervec[i].reserve(s[i].size());
        copy(s[i].begin(), s[i].end(), back_inserter(itervec[i]));
    }

    sum.resize(land[0].size());

    for (int i = 0; i < itervec.size(); i++)
    {
        for (int j = 0; j < itervec[i].size(); j++)
        {
            sum[i] += results[itervec[i][j]];
        }
    }

    sort(sum.begin(), sum.end(), Compare);



    return answer = sum[0];
}



int main()
{

    


    int result = solution({ 
        {0, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 0, 1, 1, 0},
        {1, 1, 1, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 1, 1},
        });



    return 0;
}