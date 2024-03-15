#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 20001;
const int INF = 1e9;
const int START = 1;

int n, m, k;
vector<vector<pair<int, int>>> graph;
bool visited[MAX_N];
int dist[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;

    graph.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        graph[a].push_back({b, d - c});
        graph[b].push_back({a, d - c});
    }

    fill(dist, dist + n + 1, INF);
    dist[START] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, START});

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        for (const pair<int, int>& p : graph[u]) {
            int v = p.first;
            int weight = p.second;
            if (!visited[v] && curDist + weight < dist[v]) {
                dist[v] = curDist + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << k - dist[n] << endl;

    return 0;
}