#include <string>
#include <vector>
#include <algorithm>

using namespace std;



bool Compare(int left, int right)
{
    return left > right;
}


int solution(vector<int> picks, vector<string> minerals) 
{
    
    int answer = 0;
    int count = 0;
    vector<int> result;
    

    for (int i = 0; i < picks.size(); ++i)
    {
        count += picks[i];
    }
    int maxCount = count * 5;

    if (maxCount > minerals.size())
        maxCount = minerals.size();


    if (maxCount % 5 == 0)
        result.resize(maxCount / 5);
    else
        result.resize((maxCount / 5) + 1);

    int idx = 0;
    int sum = 0;
    for (int i = 0; i < maxCount; ++i)
    {
        if (i != 0)
            idx = i / 5;

        if (minerals[i] == "diamond")
        {
            sum = 25;
        }
        else if (minerals[i] == "iron")
        {
            sum = 5;
        }
        else if (minerals[i] == "stone")
        {
            sum = 1;
        }
        result[idx] += sum;
    }



    // 85 = 3, 31 = 7
    sort(result.begin(), result.end(), Compare);
    int picIdx = 0;
    int temp = 0;

    for (int i = 0; i < result.size(); ++i)
    {
        while (picIdx < picks.size() && picks[picIdx] == 0)
        {
            ++picIdx;
        }
        if (picIdx == picks.size())
        {
            break;
        }

        if (picIdx == 0) // ´ÙÀÌ¾Æ¸óµå °î±ªÀÌ
        {
            temp = result[i] / 25;

            if (temp > 5)
            {

            }
            else
            {
                temp = 5;
            }

            answer += temp;
        }
        else if (picIdx == 1) // Ã¶ °î±ªÀÌ
        {
            temp = result[i] / 5;
            if (temp > 5)
            {

            }
            else
            {
                temp = 5;
            }
            answer += temp;
        }
        else if (picIdx == 2) // µ¹ °î±ªÀÌ
        {
            temp = result[i];
            if (temp > 5)
            {

            }
            else
            {
                temp = 5;
            }
            answer += temp;
        }


        maxCount -= 5;
        --picks[picIdx];
    }



    return answer;
}



//[1, 3, 2]	["diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"]

int main()
{

    int result = solution({ 1,3,2 }, { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" });


    return 0;
}