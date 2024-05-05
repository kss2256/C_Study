#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;


/*
    n개의 노드가 있는 그래프가 있습니다. 각 노드는 1부터 n까지 번호가 적혀있습니다.
    1번 노드에서 가장 멀리 떨어진 노드의 갯수를 구하려고 합니다. 
    가장 멀리 떨어진 노드란 최단경로로 이동했을 때 간선의 개수가 가장 많은 노드들을 의미합니다.

    노드의 개수 n, 간선에 대한 정보가 담긴 2차원 배열 vertex가 매개변수로 주어질 때, 
    1번 노드로부터 가장 멀리 떨어진 노드가 몇 개인지를 return 하도록 solution 함수를 작성해주세요.

    제한사항
    노드의 개수 n은 2 이상 20,000 이하입니다.
    간선은 양방향이며 총 1개 이상 50,000개 이하의 간선이 있습니다.
    vertex 배열 각 행 [a, b]는 a번 노드와 b번 노드 사이에 간선이 있다는 의미입니다.

*/


//[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]

/*
    배열 포문을 다 돌고 1노드를 찾는다.
    0,0 이 1이면 0,1이 간선 노드가 될거고.
    3,1 이 1이면 3,0이 간선 노드가 될거고.
    1노드의 짝꿍은 비용이 1 일거다.

   
*/





int solution(int n, vector<vector<int>> edge) 
{
    //노드 ,페어 (벡터, 2 , true);
    unordered_map<int, pair<vector<int>, pair<int, bool>>> graph;

    //그래프 초기화 노드 번호에 맞춰 1부터 시작
    for (int i = 1; i <= n; ++i) 
    {
        graph[i] = { {}, {-1, false} };
    }

    //그래프의 인덱스가 노드가 될거고, 그 노드에 간선 노드 저장
    for (int i = 0; i < edge.size(); i++)
    {
            int a = edge[i][0];
            int b = edge[i][1];
            graph[a].first.push_back(b);
            graph[b].first.push_back(a);
    }
   
   
    //시작 노드 1부터 점수 0으로 올리고 확인체크
    graph[1].second = { 0, true };

    //q에 노드1을 넣어줌.
    queue<int> q;
    q.push(1);

    while (!q.empty()) 
    {

        int current = q.front();
        q.pop();

        //현재 노드와 이웃노드 개수 가져오기
        int num_neighbors = graph[current].first.size();
        for (int i = 0; i < num_neighbors; ++i) 
        {
            //현재 노드의 이웃노드번호 꺼내와서
            int neighbor = graph[current].first[i];
            //그노드의 방문 이력이 있는지 확인
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