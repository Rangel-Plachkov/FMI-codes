#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class ShortestPathFinder {
public:
    ShortestPathFinder(long long numVertices) : n(numVertices), graph(numVertices) {}

    void addEdge(long long u, long long v, long long w) {
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    long long shortestPath(long long src, long long dest) {
        const long long INF = LLONG_MAX;
        typedef std::pair<long long, std::pair<long long, long long>> PQNode;
        std::priority_queue<PQNode, std::vector<PQNode>, std::greater<PQNode>> pq;

        std::vector<std::vector<long long>> dist(n, std::vector<long long>(2, INF));
        pq.push(std::make_pair(0, std::make_pair(src, 0)));
        pq.push(std::make_pair(0, std::make_pair(src, 1)));
        dist[src][0] = 0;
        dist[src][1] = 0;

        while (!pq.empty()) {
            long long u = pq.top().second.first;
            long long dir = pq.top().second.second;
            long long d = pq.top().first;
            pq.pop();

            if (u == dest)
                return d;

            for (const Edge& edge : graph[u]) {
                long long v = edge.vertex;
                long long w = edge.weight;

                if (dir == 0 && u > v && d + w < dist[v][1]) {
                    dist[v][1] = d + w;
                    pq.push(std::make_pair(dist[v][1], std::make_pair(v, 1)));
                }

                if (dir == 1 && u < v && d + w < dist[v][0]) {
                    dist[v][0] = d + w;
                    pq.push(std::make_pair(dist[v][0], std::make_pair(v, 0)));
                }
            }
        }

        return INF;
    }

private:
    struct Edge {
        long long vertex;
        long long weight;
        Edge(long long v, long long w) : vertex(v), weight(w) {}
    };

    long long n;
    std::vector<std::vector<Edge>> graph;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long n, m;
    std::cin >> n >> m;

    ShortestPathFinder finder(n);

    for (long long i = 0; i < m; i++) {
        long long u, v, w;
        std::cin >> u >> v >> w;
        finder.addEdge(u - 1, v - 1, w);
    }

    std::cout << finder.shortestPath(0, n - 1) << std::endl;

    return 0;
}
