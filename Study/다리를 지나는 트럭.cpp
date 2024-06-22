#include <vector>
#include <queue>

using namespace std;



int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    //�ɸ��� �� 2��
    //�ִ� ���� 10kg
    //Ʈ���� 7,4,5,6
    //2, 10, {7,4,5,6}
    int answer = 0;
    int curTime = 0, curWeight = 0, curIdx = 0;
    
    //���� + �ð�
    queue<pair<int, int>> q;

    while (curIdx < truck_weights.size() || !q.empty())
    {
        //�ð�����
        ++curTime;
        //����
        if (!q.empty() && curTime - q.front().second >= bridge_length)
        {
            curWeight -= q.front().first;
            q.pop();
        }
        //Ʈ�����
        if (curIdx < truck_weights.size() && curWeight + truck_weights[curIdx] <= weight)
        {
            q.push({ truck_weights[curIdx], curTime });
            curWeight += truck_weights[curIdx];
            ++curIdx;   
        }

    }

    


    return curTime;
}


int main()
{

    int result = solution(2, 10, {7,4,5,6});
    //int result = solution(100, 100, {10});
    //int result = solution(100, 100, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10});


    return 0;
}