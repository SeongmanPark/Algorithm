#include <iostream>
#include <queue>
//#include <fstream>
#define MIN(A,B) (A<B ? A:B);

using namespace std;
int n, m;
int dist[101][101];
int map[101][101];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int main() {
    //ifstream cin("input.txt");
    cin >> m >> n;
    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            map[i][j] = c - '0';
            dist[i][j] = 0x7FFFFFFF;
        }
    }
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    dist[1][1] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x < 1 || new_y < 1 || new_x > n || new_y > m) continue;
            // 배열의 인덱스를 벗어나면 continue
            if (dist[new_x][new_y] <= dist[x][y] + map[new_x][new_y]) continue;
            // 이전 정점에서 새로운 정점으로 가는 거리를 더한 값이 최소가 아니라면 continue 
            q.push(make_pair(new_x, new_y));
            dist[new_x][new_y] = dist[x][y] + map[new_x][new_y];
        }
    }
    cout << dist[n][m] << endl;
}
