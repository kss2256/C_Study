#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/*
    Stack/Queue
�迭 arr�� �־����ϴ�. �迭 arr�� �� ���Ҵ� ���� 0���� 9������ �̷���� �ֽ��ϴ�. �̶�,
�迭 arr���� ���������� ��Ÿ���� ���ڴ� �ϳ��� ����� ���� �����Ϸ��� �մϴ�. ��,
���ŵ� �� ���� ������ ��ȯ�� ���� �迭 arr�� ���ҵ��� ������ �����ؾ� �մϴ�. ���� ���,

arr = [1, 1, 3, 3, 0, 1, 1] �̸� [1, 3, 0, 1] �� return �մϴ�.
arr = [4, 4, 4, 3, 3] �̸� [4, 3] �� return �մϴ�.
�迭 arr���� ���������� ��Ÿ���� ���ڴ� �����ϰ� ���� ������ return �ϴ� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
�迭 arr�� ũ�� : 1,000,000 ������ �ڿ���
�迭 arr�� ������ ũ�� : 0���� ũ�ų� ���� 9���� �۰ų� ���� ����

����� ��
arr	answer
[1,1,3,3,0,1,1]	[1,3,0,1]
[4,4,4,3,3]	[4,3]

*/



vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    queue<int> q;
    q.push(arr[0]);

    for (int i = 0; i < arr.size(); ++i)
    {
        if (q.front() != arr[i])
        {
            q.push(arr[i]);
            answer.push_back(q.front());
            q.pop();
        }
    }

   
    answer.push_back(q.front());

    return answer;
}

int main()
{

    vector<int> result = solution({1,1,3,3,0,1,1});



    return 0;
}


//    //vector �迭���� �ߺ����� �ʴ� ���ҵ��� �տ������� ä�������� �Լ�.(algorithm)
//    ���۷����� ���� ����ϰ� �ϸ� ��뵵 ���� �ϰڴ�
//
//vector<int> solution(vector<int> arr)
//{
//
//	arr.erase(unique(arr.begin(), arr.end()), arr.end());
//
//	vector<int> answer = arr;
//	return answer;
//}