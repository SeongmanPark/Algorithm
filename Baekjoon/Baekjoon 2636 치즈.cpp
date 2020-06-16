#include <iostream>
//#include <fstream>
using namespace std;

int map[101][101];
bool visit[101][101] = { false };
bool erase[101][101] = { false };
int cheese[101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int cheese_count;

bool isWall(int x, int y, int N, int M)
{
	if (x < 1 || x > N || y < 1 || y > M)
		return true;
	else return false;
}

void dfs(int x, int y, int N, int M)
{
	for (int i = 0; i < 4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if (!isWall(new_x, new_y, N, M) && !visit[new_x][new_y])
		{
			visit[new_x][new_y] = true;
			if (map[new_x][new_y] == 1)
			{
				erase[new_x][new_y] = true;
			}
			else if (map[new_x][new_y] == 0)
			{
				dfs(new_x, new_y, N, M);
			}
		}
	}
}

int main()
{
	//ifstream input("input.txt");
	int N, M;
	int time = 0;
	input >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			input >> map[i][j];
			if (map[i][j] == 1) cheese_count++;
		}
	}
	cheese[time] = cheese_count;
	while (1)
	{
		time++;
		dfs(1, 1, N, M);
		// 가장자리 표시하기
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (erase[i][j])
					map[i][j] = 0;
			}
		}
		// 가장자리 지우기
		cheese_count = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (map[i][j] == 1)
					cheese_count++;
				visit[i][j] = false;
			}
		}
		
		if (cheese_count == 0)
			break;
		else
		{
			cheese[time] = cheese_count;
		}
	}
	cout << time << '\n' << cheese[time-1] << '\n';
}
// dfs로 간단하게 구현하였다. 문제를 해결할 때 예외를 잘 생각하기.
