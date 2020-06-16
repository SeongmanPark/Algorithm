#include <iostream>
#include <queue>
//#include <fstream>
using namespace std;
int map[101][101];
bool visit[101][101];
int N, M;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > M) return true;
	else return false;
}

void bfs()
{
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(1, 1), 1));
	visit[1][1] = true;
	int cur_x, cur_y, cur_dist, new_x, new_y;

	while (!q.empty())
	{
		cur_x = q.front().first.first;
		cur_y = q.front().first.second;
		cur_dist = q.front().second;
		q.pop();
		if (cur_x == N && cur_y == M)
		{
			cout << cur_dist << '\n';
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			new_x = cur_x + dx[i];
			new_y = cur_y + dy[i];
			if (isWall(new_x, new_y)) continue;
			if (visit[new_x][new_y]) continue;
			if (map[new_x][new_y] == 0) continue;
			visit[new_x][new_y] = true;
			q.push(make_pair(make_pair(new_x, new_y), cur_dist + 1));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");
	char a;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> a;
			map[i][j] = a - '0';
		}
	}

	bfs();
	return 0;
}

//BFS 왜 정답률이 낮지 ?
