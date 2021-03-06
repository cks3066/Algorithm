// 다익스트라 알고리즘 : 하나의 정점에서 각 정점들로 가는 최단 경로
// i로 가는 최단 경로 1차원 배열에 저장
// O(NlogN)

#define _CRT_SECURE_NO_WARNINGS
#define number 6
#define INF 1000000000

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>>a[number + 1];// 간선정보
int d[number + 1]; // 최소비용

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<int, int>> pq;  // 힙 구조 사용
    pq.push(make_pair(0, start));
    // 가까운 순서대로 처리하므로 큐를 사용
    while (!pq.empty()) {
        int current = pq.top().second;
        // 짧은 것이 먼저 오도록 음수화(-)
        int distance = -pq.top().first;
        pq.pop();
        //최단 거리가 아닌 경우 스킵합니다.
        if (d[current] < distance) continue;
        for (int i = 0; i < a[current].size(); i++) {
            // 선택된 노드의 인접 노드
            int next = a[current][i].second;
            // 선택된 노드 거쳐서 인접 노드로 가는 비용
            int nextDistance = distance + a[current][i].first;
            // 기존의 최소 비용보다 더 저렴하다면 교체합니다.
            if (nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 기본적으로 연결되지 않은 경우 비용은 무한
    for (int i = 1; i <= number; i++) {
        d[i] = INF;
    }

    // 그래프 생성
    // x번 노드에서 y번 노드로 가는 가중치는 z
    // a[x].push_back(make_pair(z, y));
    // Pair(가중치,다음 노드)
    a[1].push_back(make_pair(2, 2));
    a[1].push_back(make_pair(5, 3));
    a[1].push_back(make_pair(1, 4));

    a[2].push_back(make_pair(2, 1));
    a[2].push_back(make_pair(3, 3));
    a[2].push_back(make_pair(2, 4));

    a[3].push_back(make_pair(5, 1));
    a[3].push_back(make_pair(3, 2));
    a[3].push_back(make_pair(3, 4));
    a[3].push_back(make_pair(1, 5));
    a[3].push_back(make_pair(5, 6));

    a[4].push_back(make_pair(1, 1));
    a[4].push_back(make_pair(2, 2));
    a[4].push_back(make_pair(3, 3));
    a[4].push_back(make_pair(1, 5));

    a[5].push_back(make_pair(1, 3));
    a[5].push_back(make_pair(1, 4));
    a[5].push_back(make_pair(2, 6));

    a[6].push_back(make_pair(5, 3));
    a[6].push_back(make_pair(2, 5));

    dijkstra(1);

    // 결과 출력
    for (int i = 1; i <= number; i++) {
        cout << d[i] << ' ';
    }

    return 0;
}
