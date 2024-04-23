#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/*

    Value                       percentage              return
    [93, 30, 55]	            [1, 30, 5]	            [2, 1]
    [95, 90, 99, 99, 80, 99]	[1, 1, 1, 1, 1, 1]	    [1, 3, 2]

    ��� �ݺ��ؾ� ���� �𸣴� ���Ϲ� �۾�
    ������ 
    

*/



vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    vector<int> sumvec;
    sumvec.resize(progresses.size());
    for (size_t i = 0; i < progresses.size(); i++)
    {
        sumvec[i] = progresses[i];
    }
    
    int test = 0;
    int iter = 0;

    //�ݺ�
    while (iter < progresses.size())
    {
		for (int i = iter; i < speeds.size(); ++i)
		{
            //���ǵ� ��ŭ �����ֱ�
			sumvec[i] += speeds[i];
		}

        //100% �޼���
        if (sumvec[iter] >= 100)
        {
            while (sumvec[iter] >= 100)
            {
                ++iter;
                ++test;

                if (iter >= progresses.size())
                {
                    answer.push_back(test);
                    return answer;
                }
            }
            answer.push_back(test);
            test = 0;
        }

    }


    return answer;
}


int main()
{
    //[93, 30, 55]	[1, 30, 5]
    //[95, 90, 99, 99, 80, 99]  [1, 1, 1, 1, 1, 1]          
    vector<int> a;
    vector<int> b = { 93, 30, 55 };
    vector<int> c = { 1, 30, 5 };

   

    a = solution(b, c);

    for (size_t i = 0; i < a.size(); i++)
    {
        cout << a[i];
    }

    return 0;
}