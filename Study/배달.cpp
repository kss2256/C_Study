#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;



int solution(int N, vector<vector<int> > road, int K) 
{
    int answer = 1;

    vector<bool> visit(N + 1, false);
    vector<vector<pair<int, int>>> town(N + 1);
    queue<pair<int,int>> q;
    int temp = 0;

    for (int i = 0; i < road.size(); ++i)
    {
        if (road[i][0] > road[i][1])
        {
            temp = road[i][0];
            road[i][0] = road[i][1];
            road[i][1] = temp;
        }
    }

    sort(road.begin(), road.end());


    for (int i = 0; i < road.size(); ++i)
    {
        town[road[i][0]].push_back({ road[i][1], road[i][2] });
    }
    
    visit[1] = true;
    for (int i = 0; i < town[1].size(); i++)
    {
        if(town[1][i].second <= K)
        q.push({ town[1][i].first, town[1][i].second});
    }
    
    int expense = 0, idx = 0;
    while (!q.empty())
    {
        idx = q.front().first;
        expense = q.front().second;
        q.pop();
        if (visit[idx] == false)
        {
            visit[idx] = true;
            ++answer;
        }

		for (int i = 0; i < town[idx].size(); )
		{
			if (town[idx][i].second + expense <= K)
			{
				expense += town[idx][i].second;
				idx = town[idx][i].first;
                if (visit[idx] == false)
                {
                    visit[idx] = true;
                    ++answer;
                    i = 0;
                }
               
			}
            else
            {
                i++;
            }
		}

      
        

    }
   



    return answer;
}


//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//vector<pair<int, int>> adj[51]; // ���� ����Ʈ (���, �Ÿ�)
//int dist[51]; // �ִ� �Ÿ� �迭
//
//int solution(int N, vector<vector<int>> road, int K) 
//{
//
//    int a, b, c;
//
//    for (int i = 0; i < road.size(); ++i)
//    {
//        a = road[i][0];
//        b = road[i][1];
//        c = road[i][2];
//
//        adj[a].push_back({ b, c });
//        adj[b].push_back({ a, c });
//
//    }
//
//
//    // �Ÿ� �迭�� ���Ѵ�� �ʱ�ȭ
//    fill(dist, dist + 51, 1e9);
//    dist[1] = 0; // 1�� �������� ����
//
//    // �켱���� ť�� ����� ���ͽ�Ʈ�� �˰���
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    pq.push({ 0, 1 }); // (�Ÿ�, ���)
//
//    while (!pq.empty()) {
//        int current_dist = pq.top().first;
//        int current_node = pq.top().second;
//        pq.pop();
//
//        if (current_dist > dist[current_node]) continue;
//
//        for (auto& next : adj[current_node]) {
//            int next_node = next.first;
//            int next_dist = next.second;
//
//            if (dist[next_node] > dist[current_node] + next_dist) {
//                dist[next_node] = dist[current_node] + next_dist;
//                pq.push({ dist[next_node], next_node });
//            }
//        }
//    }
//
//    // K ���Ϸ� ��� ������ ������ �� ���
//    int answer = 0;
//    for (int i = 1; i <= N; ++i) {
//        if (dist[i] <= K) {
//            answer++;
//        }
//    }
//
//    return answer;
//}



int main()
{
    //5	[[1,2,1],[2,3,3],[5,2,2],[1,4,2],[5,3,1],[5,4,2]]	3  return 4

    //int result = solution(5, { {1,2,1} ,{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2} }, 3);
    //int result = solution(6, { {1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1} }, 4);
    int result = solution(4, { {1,2,1},{1,3,4},{2,3,1},{3,4,1}}, 4);


	return 0;
}