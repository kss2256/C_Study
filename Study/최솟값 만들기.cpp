#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;


bool Up(int left, int right)
{
    return left < right;
}

bool Down(int left, int right)
{
    return left > right;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end(), Up);
    sort(B.begin(), B.end(), Down);

    for (int i = 0; i < A.size(); ++i)
    {
        answer += A[i] * B[i];
    }


    return answer;
}


int main()
{

    int result = solution({1,4,2}, {5,4,4});


    return 0;
}