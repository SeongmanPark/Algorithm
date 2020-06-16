#include <iostream>
//#include <fstream>
#include <queue>
#include <cstring>

using namespace std;
int N, M, cheese_count, answer;
int map[101][101];
bool visit[101][101];
int erase[101][101];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > M) return true;
	else return false;
}

void bfs()
{
	memset(erase, 0, sizeof(erase));
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;
	int new_x, new_y, cur_x, cur_y;
	q.push(make_pair(1, 1));
	visit[1][1] = true;
	while (!q.empty())
	{
		cur_x = q.front().first;
		cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			new_x = cur_x + dx[i];
			new_y = cur_y + dy[i];
			if (isWall(new_x, new_y) || visit[new_x][new_y]) continue;
			if (map[new_x][new_y] == 1)
			{
				erase[new_x][new_y]++;
				continue;
			}
			visit[new_x][new_y] = true;
			q.push(make_pair(new_x, new_y));

		}
	}
}

void checkCheese()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (erase[i][j] >= 2)
			{
				map[i][j] = 0;
				cheese_count--;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				cheese_count++;
			}
		}
	}

	while (1)
	{
		if (cheese_count == 0)
			break;
		bfs();
		checkCheese();
		answer++;
	}
	cout << answer << '\n';
}

// 완탐 간단한 구현 문제
