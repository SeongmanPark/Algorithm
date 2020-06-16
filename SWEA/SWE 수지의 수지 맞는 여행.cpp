#include <iostream>
#include <cstring>
#include <fstream>

#define MAX(a,b) (a>b ? a:b)
using namespace std;

int testCase, R, C, answer;
char map[21][21];
bool visit[21][21] = { false };
bool alpha[101] = { false };
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int a = 1;

bool isWall(int x, int y)
{
	if (x < 1 || y<1 || x>R || y>C)
		return true;
	else return false;
}

void init()
{
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));
	memset(alpha, 0, sizeof(alpha));
	answer = 0;
	a++;
}

void dfs(int depth, int x, int y)
{
	answer = MAX(answer, depth);
	
	for (int i = 0; i < 4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if (isWall(new_x, new_y) || visit[new_x][new_y] || alpha[map[new_x][new_y]]) continue;
		else
		{
			alpha[map[new_x][new_y]] = true;
			visit[new_x][new_y] = true;
			dfs(depth + 1, new_x, new_y);
			alpha [map[new_x][new_y]]= false;
			visit[new_x][new_y] = false;
		}
	}
}

int main()
{
	ifstream input("input.txt");
	input >> testCase;

	while (testCase-- > 0)
	{
		input >> R >> C;
		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				input >> map[i][j];
			}
		}

		alpha[map[1][1]] = true;
		dfs(1, 1, 1);

		cout << "#" << a << " " << answer << '\n';
		init();
	}
}

// dfs를 이용하였다.
