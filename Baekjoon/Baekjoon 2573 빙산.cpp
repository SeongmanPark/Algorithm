#include <iostream>
//#include <fstream>
#include <cstring>
using namespace std;

int answer;
int map[301][301];
bool visit[301][301] = { false };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
typedef struct mountain
{
	int x, y, height, sea_count;
}m;
// 빙하의 정보를 담는 구조체
m mountain_info[10001];
int mountain_info_index = 0;

bool isAllZero(int N, int M)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] != 0)
				return false;
		}
	}

	return true;
}

bool isWall(int N, int M, int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > M)
		return true;
	else return false;
}

void find_sea(int N, int M, int mountain_info_index)
{
	for (int i = 0; i < mountain_info_index; i++)
	{
		if (mountain_info[i].height == 0) continue;
		for (int j = 0; j < 4; j++)
		{
			int new_x = mountain_info[i].x + dx[j];
			int new_y = mountain_info[i].y + dy[j];
			if (isWall(N, M, new_x, new_y)) continue;	// 벽이면 continue
			if (map[new_x][new_y] == 0)
			{
				mountain_info[i].sea_count++;	// 인접한 바다의 수 count
			}
		}
	}
}

void dfs(int N, int M, int x, int y)
{	
	for (int i = 0; i < 4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if (!isWall(N, M, new_x, new_y) && map[new_x][new_y] != 0 && !visit[new_x][new_y])
		{
			visit[new_x][new_y] = true;
			dfs(N, M, new_x, new_y);
		}
	}
}

int main()
{
	//ifstream input("input.txt");
	int N, M;
	input >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			input >> map[i][j];
			if (map[i][j] != 0)
			{
				mountain_info[mountain_info_index].x = i;
				mountain_info[mountain_info_index].y = j;
				mountain_info[mountain_info_index].height = map[i][j];
				mountain_info_index++;
			}
		}
	}


	while (1)
	{
		int dfs_count = 0;
		for (int i = 1; i <= N; i++)	// 섬의 개수를 찾기
		{
			for (int j = 1; j <= M; j++)
			{
				if (map[i][j] != 0 && !visit[i][j])
				{
					dfs_count++;
					visit[i][j] = true;
					dfs(N, M, i, j);
					if (dfs_count >= 2)		// 섬의 개수가 2이상이 되면 ?
					{
						cout << answer << endl;
						return 0;
					}
				}
			}
		}
		// 섬 개수 1
		answer++;
		find_sea(N, M, mountain_info_index);

		for (int i = 0; i < mountain_info_index; i++)
		{
			if (mountain_info[i].height == 0) continue;
			else
			{
				mountain_info[i].height -= mountain_info[i].sea_count;
				if (mountain_info[i].height < 0)
				{
					mountain_info[i].height = 0;
					map[mountain_info[i].x][mountain_info[i].y] = 0;
				}
				else
				{
					map[mountain_info[i].x][mountain_info[i].y] = mountain_info[i].height;
				}
			}
			mountain_info[i].sea_count = 0;
		}
		bool flag = isAllZero(N, M);
		if (flag)
		{
			cout << 0 << '\n';
			return 0;
		}
		memset(visit, 0, sizeof(visit));
	}
}
// 문제를 똑바로 다 읽지 않아서 시간초과가 난 문제, 문제를 잘 읽자 !!
