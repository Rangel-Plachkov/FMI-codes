#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const long long MAXN = 20005;
const long long INF = INT_MAX;

long long n, m, k;
vector<pair<long long, long long>> adj [MAXN];
long long dist[MAXN];
bool visited[MAXN];

void dijkstra(long long s, long long t) {
    memset(dist, INF, sizeof(dist));
    memset(visited, false, sizeof(visited));
    dist[s] = 0;

    //priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    priority_queue<pair<long long, long long>> pq;

    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        long long u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        
        for (long long i = 0; i < adj[u].size(); i++) {
            
            long long to = adj[u][i].first;
            
            long long weight = adj[u][i].second;
            cout<<dist[to];
            if (dist[u] + weight < dist[to]) {
                dist[to] = dist[u] + weight;
                pq.push(make_pair(dist[to], to));
            }
        }
    }
    for(long long i=0; i<n;i++){
        cout<<i<<" "<<dist[t]<<endl;
    }
    //cout <<k - dist[t];
}

int main() {
    cin >> n >> m >> k;
   // adj.resize(MAXN);

    for (long long i = 0; i < m; i++) {
        long long u, v, p ,t;
        cin >> u >> v >> p >> t;
        adj[u].push_back(make_pair(v, t-p));
        adj[v].push_back(make_pair(u, t-p));
    }

    //long long s, t;
    //cin >> s >> t;

    dijkstra(1, 8);

    return 0;
}