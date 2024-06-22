#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//[2,6,8,14]	168
//[1,2,3]	    6

bool Compare(int left, int right)
{
    return left < right;
}

int solution(vector<int> arr)
{
    
    //[2,6,8,14]

    sort(arr.begin(), arr.end(), Compare);
    
    const int max = arr[arr.size() - 1];
    int number = max;
    int mult = 1;

    for (int i = 0; i < arr.size(); )
    {
        if (number % arr[i] == 0)
        {
            ++i;
        }
        else
        {
            number = max * ++mult;
            i = 0;
        }
    }


   
    return number;
}


int main()
{

    int result = solution({2,6,8,14});
    //int result = solution({1,2,3,});


    return 0;
}


