#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;


/*
    n���� ��尡 �ִ� �׷����� �ֽ��ϴ�. �� ���� 1���� n���� ��ȣ�� �����ֽ��ϴ�.
    1�� ��忡�� ���� �ָ� ������ ����� ������ ���Ϸ��� �մϴ�. 
    ���� �ָ� ������ ���� �ִܰ�η� �̵����� �� ������ ������ ���� ���� ������ �ǹ��մϴ�.

    ����� ���� n, ������ ���� ������ ��� 2���� �迭 vertex�� �Ű������� �־��� ��, 
    1�� ���κ��� ���� �ָ� ������ ��尡 �� �������� return �ϵ��� solution �Լ��� �ۼ����ּ���.

    ���ѻ���
    ����� ���� n�� 2 �̻� 20,000 �����Դϴ�.
    ������ ������̸� �� 1�� �̻� 50,000�� ������ ������ �ֽ��ϴ�.
    vertex �迭 �� �� [a, b]�� a�� ���� b�� ��� ���̿� ������ �ִٴ� �ǹ��Դϴ�.

*/


//[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]

/*
    �迭 ������ �� ���� 1��带 ã�´�.
    0,0 �� 1�̸� 0,1�� ���� ��尡 �ɰŰ�.
    3,1 �� 1�̸� 3,0�� ���� ��尡 �ɰŰ�.
    1����� ¦���� ����� 1 �ϰŴ�.

   
*/





int solution(int n, vector<vector<int>> edge) 
{
    //��� ,��� (����, 2 , true);
    unordered_map<int, pair<vector<int>, pair<int, bool>>> graph;

    //�׷��� �ʱ�ȭ ��� ��ȣ�� ���� 1���� ����
    for (int i = 1; i <= n; ++i) 
    {
        graph[i] = { {}, {-1, false} };
    }

    //�׷����� �ε����� ��尡 �ɰŰ�, �� ��忡 ���� ��� ����
    for (int i = 0; i < edge.size(); i++)
    {
            int a = edge[i][0];
            int b = edge[i][1];
            graph[a].first.push_back(b);
            graph[b].first.push_back(a);
    }
   
   
    //���� ��� 1���� ���� 0���� �ø��� Ȯ��üũ
    graph[1].second = { 0, true };

    //q�� ���1�� �־���.
    queue<int> q;
    q.push(1);

    while (!q.empty()) 
    {

        int current = q.front();
        q.pop();

        //���� ���� �̿���� ���� ��������
        int num_neighbors = graph[current].first.size();
        for (int i = 0; i < num_neighbors; ++i) 
        {
            //���� ����� �̿�����ȣ �����ͼ�
            int neighbor = graph[current].first[i];
            //�׳���� �湮 �̷��� �ִ��� Ȯ��
            if (!graph[neighbor].second.second)
            { 
                graph[neighbor].second = { graph[current].second.first + 1, true };
                q.push(neighbor);
            }
        }
    }


    int max_distance = 0;
    for (auto it = graph.begin(); it != graph.end(); ++it) 
    {
        max_distance = max(max_distance, (int)it->second.second.first);
    }

    int count = 0;
    for (auto it = graph.begin(); it != graph.end(); ++it) 
    {
        if (it->second.second.first == max_distance) {
            count++;
        }
    }

    return count;
}




int main()
{
    vector<vector<int>> value =
    {
        {3, 6},
        {4, 3},
        {3, 2},
        {1, 3},
        {1, 2},
        {2, 4},
        {5, 2}
    };

    int test = solution(6, value);




    return 0;
}