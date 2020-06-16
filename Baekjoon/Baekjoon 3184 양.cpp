#include <iostream>
//#include <fstream>
#include <queue>
using namespace std;

char map[251][251];
bool visit[251][251];
int R, C, sheep, wolf;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > R || y > C) return true;
	else return false;
}

void bfs(int x, int y)
{
	int new_x, new_y, cur_x, cur_y;
	int temp_sheep = 0;
	int temp_wolf = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		cur_x = q.front().first;
		cur_y = q.front().second;
		q.pop();

		switch (map[cur_x][cur_y])
		{
			case 'o': // 양일때
			{
				temp_sheep++;
				break;
			}
			case 'v':
			{
				temp_wolf++;
				break;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			new_x = cur_x + dx[i];
			new_y = cur_y + dy[i];
			if (isWall(new_x, new_y)) continue;
			if (visit[new_x][new_y]) continue;
			if (map[new_x][new_y] == '#') continue;
			visit[new_x][new_y] = true;
			q.push(make_pair(new_x, new_y));
		}
	}

	if (temp_sheep > temp_wolf)
	{
		sheep += temp_sheep;
	}
	else
	{
		wolf += temp_wolf;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if ((map[i][j] == 'o' || map[i][j] == 'v' || map[i][j] == '.') && !visit[i][j]) // 필드일때 탐색 시작
			{
				visit[i][j] = true;
				bfs(i, j);
			}
		}
	}

	cout << sheep << " " << wolf << '\n';
	return 0;
}

// BFS, 간단 구현.
