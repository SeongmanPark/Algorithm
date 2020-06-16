#include <iostream>
//#include <fstream>
#include <cstring>
#define MAX(A,B) (A>B ? A:B)
using namespace std;

int map[9][9];
int temp_map[9][9];
bool visit[9][9];
int N, M, answer, wall_count, temp_answer;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > M)
		return true;
	else return false;
}

int SafeZone()
{
	int safe = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (temp_map[i][j] == 0)
				safe++;
		}
	}
	return safe;
}

void dfs(int x, int y)
{
	int new_x, new_y;

	for (int i = 0; i < 4; i++)
	{
		new_x = x + dx[i];
		new_y = y + dy[i];
		if (isWall(new_x, new_y) || visit[new_x][new_y] || temp_map[new_x][new_y] != 0) continue;
		visit[new_x][new_y] = true;
		temp_map[new_x][new_y] = 2;
		dfs(new_x, new_y);
	}
}

void virus()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (temp_map[i][j] == 2 && !visit[i][j])
			{
				visit[i][j] = true;
				dfs(i, j);
			}
		}
	}
	// 바이러스 다 퍼뜨림..
	temp_answer = SafeZone();
	answer = MAX(temp_answer, answer);
}

void MakeWall(int cnt)
{
	if (cnt == 3)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				temp_map[i][j] = map[i][j];
			}
		}
		memset(visit, 0, sizeof(visit));
		virus();
		return;
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				MakeWall(cnt + 1);
				map[i][j] = 0;
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
		}
	}
	// 입력 완료

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				MakeWall(1);
				map[i][j] = 0;
			}
		}
	}
	cout << answer << '\n';
	return 0;
}

// 조합과 완전탐색을 이용하여 풀었다.
