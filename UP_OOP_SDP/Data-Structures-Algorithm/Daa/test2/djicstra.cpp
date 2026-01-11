
/*
#include<iostream>
#include<queue>
#include<string>

struct ppl{
    int age;
    std::string name;

    bool operator<(const ppl& other){
        return age < other.age;
    }
};

int main(){
    //std::priority_queue<ppl> pq;
    //std::ios_base::sync_with_stdio(false);
    //std::sort(numbers.begin(), numbers.end());

    //std::cout<<pq.top();
    //pq.pop();
    //std::cout<<pq.top();
    std::cout<<std::min(4,10);
}
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int find(int u, vector<int>& parent) {
    if (parent[u] == u) {
        return u;
    }
    return parent[u] = find(parent[u], parent);
}

void merge(int u, int v, vector<int>& parent) {
    u = find(u, parent);
    v = find(v, parent);
    if (u != v) {
        parent[u] = v;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cost(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n+1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    vector<Edge> mst;
    int total_cost = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if (find(u, parent) != find(v, parent)) {
            mst.push_back(edges[i]);
            merge(u, v, parent);
            total_cost += w;
        }
    }

    cout << total_cost << endl;
    for (int i = 0; i < mst.size(); i++) {
        int u = mst[i].u;
        int v = mst[i].v;
        int w = mst[i].w;
        if (cost[u] < cost[v]) {
            cout << u << " " << v << " " << (w+1)/2 << endl;
        } else {
            cout << v << " " << u << " " << (w+1)/2 << endl;
        }
    }

    return 0;
}