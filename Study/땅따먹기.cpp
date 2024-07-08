#include <iostream>
#include <vector>
using namespace std;


int solution(vector<vector<int> > land)
{
    int rows = land.size();
    int cols = land[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));


    for (int i = 0; i < cols; ++i) 
    {
        dp[0][i] = land[0][i];
    }

    // dp 배열 채우기
    for (int i = 1; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            int max_value = 0;
            for (int k = 0; k < cols; ++k)
            {
                if (j != k) 
                { // 같은 열이 아닌 경우
                    max_value = max(max_value, dp[i - 1][k]);
                }
            }
            dp[i][j] = land[i][j] + max_value;
        }
    }

 
    int answer = 0;
    for (int i = 0; i < cols; ++i) 
    {
        answer = max(answer, dp[rows - 1][i]);
    }

    return answer;
}



int main()
{
    //[[1,2,3,5],[5,6,7,8],[4,3,2,1]]	16
    int result = solution({ {1,2,3,5}, {5,6,7,8}, {4,3,2,1} });



    return  0;
}