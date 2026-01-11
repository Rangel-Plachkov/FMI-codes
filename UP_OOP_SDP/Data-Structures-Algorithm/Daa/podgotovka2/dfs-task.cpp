#include<vector>
#include<list>
#include<iostream>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<int>>& adj_list, vector<bool>& visited, int current, int destination) {
        visited[current] = true;

        if (current == destination)
            return true;

        for (int neighbor : adj_list[current]) {
            if (!visited[neighbor]) {
                if (dfs(adj_list, visited, neighbor, destination))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj_list(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        vector<bool> visited(n, false);
        return dfs(adj_list, visited, source, destination);
    }
};

int main(){

}