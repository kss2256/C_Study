#include <string>
#include <vector>
#include <algorithm>

using namespace std;


#define MAX_ARROW 11

int dfs(int idx)
{





    return 0;
}



//5, {2,1,1,1,0,0,0,0,0,0,0}
vector<int> solution(int n, vector<int> info) 
{
    vector<int> answer;
    vector<vector<int>> information(3, vector<int>(MAX_ARROW, 0));
    vector<vector<int>> result(3, vector<int>(MAX_ARROW, 0));
    

    int peach = 0, ryan = 0;
    int ryanArrowScore[MAX_ARROW] = {0};
    

    for (int i = 0; i < info.size(); i++)
    {       
        if (info[i] != 0)
            peach += 10 - i;

        ryanArrowScore[i] = info[i] + 1;

        information[0][i] = 10 - i;        
        information[2][i] = info[i] + 1;

        information[1][i] = information[0][i];
        if (info[i] != 0)
        {
            information[1][i] *= 2;
        }

    } 


	int arrow = n, idx = 0;
    //점수판 / 얻을수 있는기회 점수 / 필요한 화살 수

	//{2,1,1,1,0,0,0,0,0,0,0}

    for (int i = 0; i < info.size(); ++i)
    {
        dfs(i);
    }





    return answer;
}





//vector<int> solution(int n, vector<int> info)
//{
//    vector<int> answer;
//    int peach = 0, ryan = 0;
//
//    for (int i = 0; i < info.size(); i++)
//    {
//        if(info[i] != 0)
//        peach += 10 - i;
//    }
//
//    vector<pair<vector<int>, int>> field(info.size(), pair<vector<int>, int>(vector<int>(info.size(), 0), 0));
//    int arrow = n, idx = 0;
//    
//    //{2,1,1,1,0,0,0,0,0,0,0}
//    while (idx < info.size())
//    {
//        arrow = n;
//        int curIdx = idx, temp = 0, sum = 0;
//
//        while (arrow > 0)
//        {
//            temp = info[curIdx] + 1;
//            if (temp <= arrow && temp < 3)
//            {
//                field[idx].first[curIdx] = temp;
//                arrow -= temp;
//                if (curIdx != 0)
//                    sum += 10 - curIdx;
//                else
//                {
//                    sum += 10;
//                }
//
//
//            }
//            // curIdx가 info.size()를 넘어가면 다시 0부터 시작
//            curIdx = (curIdx + 1) % info.size();
//        }
//
//        field[idx].second = sum;
//        ++idx;
//    }
//
//    int a = 0, b = 0;
//    for (size_t i = 0; i < field.size(); i++)
//    {
//        if (field[i].second > a)
//        {
//            a = field[i].second;
//            b = i;
//        }
//
//    }
//
//    int count = 0;
//
//    for (int i = 0; i < info.size(); i++)
//    {
//        if (info[i] != 0)
//            ryan += info[i] * (10 - i);
//    }
//    if (ryan > peach)
//    {
//       
//        for (size_t i = 0; i < field[b].first.size(); i++)
//        {
//            count += field[b].first[i];
//        }
//        if (count != n)
//        {
//            field[b].first[info.size() - 1] = n - count;
//        }
//        answer = field[b].first;
//    }
//    else
//    {
//        answer = vector<int>({ -1 });
//    }
//
//    
//
// 
//    return answer;
//}



int main()
{
    //[0,2,2,0,1,0,0,0,0,0,0]

    vector<int> result = solution(5, {2,1,1,1,0,0,0,0,0,0,0});
    //vector<int> result = solution(1, {1,0,0,0,0,0,0,0,0,0,0});
    //vector<int> result = solution(10, { 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3 });



    return 0;
}