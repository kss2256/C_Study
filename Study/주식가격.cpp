#include <string>
#include <vector>
#include <stack>


using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer(prices.size(), 0);
    stack<int> stackInt;

    //1, 2, 3, 2, 3

    for (int i = 0; i < prices.size(); ++i) 
    {       
        while (!stackInt.empty() && prices[stackInt.top()] > prices[i])
        {
            int top = stackInt.top();
            stackInt.pop();
            answer[top] = i - top;
        }
        // ���� �ε��� ���ÿ� �߰�
        stackInt.push(i);
    }

    //������ �ȶ����� �༮�� �ִ밪���� ���ؼ� �Ѱ��ֱ�
    while (!stackInt.empty())
    {
        int top = stackInt.top();
        stackInt.pop();
        answer[top] = prices.size() - 1 - top;
    }


    return answer;
}


int main()
{

    vector<int> result = solution({ 1, 2, 3, 2, 3 });


    return 0;
}