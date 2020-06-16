#include <iostream>
//#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

int map[51][51];
bool visit[51][51] = { false };
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
// 상하좌우
int N, M, answer;
queue < pair<int, int>> q;
int weight[51][51];

bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > M)
		return true;
	else return false;
}

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (!isWall(new_x, new_y) && !visit[new_x][new_y] && map[new_x][new_y] == 1)	// 벽X, 아직방문x, 육지면?
			{
				visit[new_x][new_y] = true;
				q.push(make_pair(new_x, new_y));
				weight[new_x][new_y] = weight[x][y] + 1;
			}
		}
	}
	int temp = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (weight[i][j] > temp)
			{
				temp = weight[i][j];
			}
		}
	}
	if (temp > answer)
	{
		answer = temp;
	}

}

int main()
{
	//ifstream input("input.txt");
	input >> N >> M;
	char data;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			input >> data;
			switch (data)
			{
				case 'W': {
					map[i][j] = 0;
					break;
				}
				case 'L': {
					map[i][j] = 1;
				}
				default: {
					break;
				}
			}
		}
	}
	// 배열 입력 완료

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			memset(visit, 0, sizeof(visit));
			memset(weight, 0, sizeof(weight));
			if (map[i][j] == 1)
			{
				q.push(make_pair(i, j));
				visit[i][j] = true;
				bfs();
			}
		}
	}
	cout << answer << '\n';
}

// 처음에 dfs로 접근했다가 잘못된것을 깨달은 후, dfs로 품
