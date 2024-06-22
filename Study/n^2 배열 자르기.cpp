#include <string>
#include <vector>

using namespace std;

//  3	2	5	[3,2,2,3]

vector<int> solution(int n, long long left, long long right) 
{
    vector<int> answer;

    long long start = left;
    int col, row = 0;
    //2 , 3 , 4 , 5
    for (int i = 0; i < (right - left) + 1; ++i)
    {
        col = (start / n);
        row = (start % n);

        if (row > col)
            col = row;

        answer.push_back(col + 1);
        ++start;
    }

    return answer;
}


int main()
{

    vector<int> result = solution(3, 2, 5);


    return 0;
}