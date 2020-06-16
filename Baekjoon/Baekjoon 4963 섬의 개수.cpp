#include <iostream>
//#include <fstream>
#include <cstring>
using namespace std;
int map[51][51];
bool visit[51][51];
int W, H;
int answer;
int a = 1;
int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
// 8방향 설정

void init()
{
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));
	a++;
	answer = 0;
}

bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > H || y > W) return true;
	else return false;
}

void dfs(int x, int y)
{
	int new_x, new_y;
	for (int i = 0; i < 8; i++)
	{
		new_x = x + dx[i];
		new_y = y + dy[i];
		if (isWall(new_x, new_y)) continue;
		if (visit[new_x][new_y]) continue;
		if (map[new_x][new_y] == 1)
		{
			visit[new_x][new_y] = true;
			dfs(new_x, new_y);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");

	while (1)
	{
		cin >> W >> H;
		
		if (W == 0 && H == 0)
			break;

		for (int i = 1; i <= H; i++)
			for (int j = 1; j <= W; j++)
				cin >> map[i][j];

		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				if (map[i][j] == 1 && !visit[i][j])
				{
					answer++;
					dfs(i, j);
				}
			}
		}
		cout << answer << '\n';
		init();
	}
	return 0;
}

// 섬의 개수 문제.
// dfs로 해결 (머리 식힐겸 풀어봄).
