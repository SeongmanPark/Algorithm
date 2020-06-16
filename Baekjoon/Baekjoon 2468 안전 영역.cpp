#include <iostream>
//#include <fstream>
#include <algorithm>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int map[101][101];
bool visit[101][101] = { false };
int max_height = 0;
int safe_zone = 0;
int max_safe_zone = 0;

void init(int N)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			visit[i][j] = false;
		}
	}
	safe_zone = 0;
}

bool isWall(int x, int y, int N)
{
	if (x <1 || x > N || y < 1 || y > N)
	{
		return true;
	}
	else return false;
}

void dfs(int N, int x, int y, int k)
{
	for (int i = 0; i < 4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];

		if (!isWall(new_x, new_y, N) && !visit[new_x][new_y] && map[new_x][new_y] > k)
		{
			visit[new_x][new_y] = true;
			dfs(N, new_x, new_y, k);
		}
	}
}

int main()
{
	//ifstream input("input.txt");
	int N;
	input >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			input >> map[i][j];
			if (map[i][j] > max_height)
			{
				max_height = map[i][j];
			}
		}
	}

	for(int k = max_height; k >=0; k--)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (!visit[i][j] && map[i][j] > k)
				{
					visit[i][j] = true;
					safe_zone++;
					dfs(N, i, j, k);
				}
			}
		}
		if (safe_zone > max_safe_zone)
		{
			max_safe_zone = safe_zone;
		}
		init(N);
	}
	cout << max_safe_zone << '\n';

}

// dfs로 간단하게 구현, k = max_height 부터 시작, 높이가 전부 1일때 히든 
