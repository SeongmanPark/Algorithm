#include <iostream>
//#include <fstream>
#include <cstring>

using namespace std;
char map[13][7];
bool visit[13][7];
// while문 한 번에 방문했던 노드 체크 !!!!!
bool erase[13][7];
// while문 한 번에 지울 노드 체크 !!!!!!
bool temp_erase[13][7];
// 색깔별로 dfs 재귀호출에 지울 노드 체크 !!!!!!!
bool crash = false;
// 푸요푸요를 지울수 있으면 true !!!!!
int answer;
// 연쇄
int depth;
// 연속으로 네개 이상 붙어있는지 확인하는 변수 !!!!

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
// 상 하 좌 우

bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > 12 || y > 6) return true;
	else return false;
}

void erase_map()
{
	for (int i = 1; i <= 12; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			if (erase[i][j])
				map[i][j] = '.';
		}
	}
}

void down()
{
	for (int j = 1; j <= 6; j++)
	{
		for (int k = 1; k <= 12; k++)
		{
			for (int i = 12; i >= 2; i--)
			{
				if (map[i][j] == '.' && map[i - 1][j] != '.')
				{
					map[i][j] = map[i - 1][j];
					map[i - 1][j] = '.';
				}
			}
		}
	}
}

void dfs(char color, int x, int y)
{
	if (depth >= 4)
	{
		crash = true;
		for (int i = 1; i <= 12; i++)
		{
			for (int j = 1; j <= 6; j++)
			{
				if (temp_erase[i][j])
				{
					erase[i][j] = temp_erase[i][j];
				}
			}
		}
	}

	int new_x, new_y;
	for (int i = 0; i < 4; i++)
	{
		new_x = x + dx[i];
		new_y = y + dy[i];
		if (map[new_x][new_y] != color) continue;
		// 색이 다르면 ??? dfs ㄴㄴ
		if (visit[new_x][new_y]) continue;
		// 이미 방문한 노드니까 continue
		if (isWall(new_x, new_y)) continue;
		// 벽이면 ?? continue
		visit[new_x][new_y] = true;
		temp_erase[new_x][new_y] = true;
		depth++;
		dfs(color, new_x, new_y);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");

	for (int i = 1; i <= 12; i++)
		for (int j = 1; j <= 6; j++)
			cin >> map[i][j];

	while (1)
	{
		crash = false;
		memset(visit, 0, sizeof(visit));
		memset(erase, 0, sizeof(erase));
		for (int i = 1; i <= 12; i++)
		{
			for (int j = 1; j <= 6; j++)
			{
				memset(temp_erase, 0, sizeof(temp_erase));
				if (map[i][j] != '.' && !visit[i][j])
				{
					visit[i][j] = true;
					temp_erase[i][j] = true;
					depth = 1;
					dfs(map[i][j], i, j);
				}
			}
		}

		erase_map();
		// 지우기 !!!
		down();
		// 지웠으니까 푸요푸요 내리는 함수!!
		if (!crash) break;
		answer++;
	}
	cout << answer << '\n';
}

// 시뮬레이션 + 완전탐색 문제이다.
// 한 번에 통과했음, 연속된 색깔을 셀 때 depth를 인자로 줘서 좀 헤맸던 문제 !!!
