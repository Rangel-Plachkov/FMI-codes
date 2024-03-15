#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1005;
const int INF = 1e9;

int n, m,k;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<pair<int, int>> finish;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs() {
    queue<pair<int, int>> q;

    for (const auto& f : finish) {
        q.push(f);
        visited[f.first][f.second] = true;
        dist[f.first][f.second] = 0;
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || grid[nx][ny] == '#') {
                continue;
            }

            visited[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    cin >> n >> m>> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i=0; i< k ; i++){
        int x,y;
        cin>>x>>y;
        finish.push_back({x-1, y-01});
    }

    memset(dist, INF, sizeof(dist));
    bfs();

    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                cout << -1 << " ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }*/
    long long res = 0;
    for(int x=0; x<n;x++){
        for(int y=0; y<m;y++){
            if(grid[x][y] != '#'){
                res += dist[x][y];
            }
        }
    }
    cout<<res;

    return 0;
}