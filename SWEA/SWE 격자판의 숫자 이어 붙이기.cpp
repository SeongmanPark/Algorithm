#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
// 상 하 좌 우

int arr[4][4];
bool visit[10000000] = { false };

bool isWall(int x, int y)
{
	if (x < 0 || x > 3 || y < 0 || y > 3)
	{
		return true;
	}
	return false;
}

void dfs(int x, int y, int depth, int temp, int digit)
{
	if (depth == 7)	// 7번 재귀하면
	{
		if (visit[temp]) {
			return;
		}
		// 중복된게 없으면
		else
		{
			visit[temp] = true;
			return;
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if (isWall(new_x, new_y))
			{
				continue;
			}	// 벽이면 pass
			else 
			{
				dfs(new_x, new_y, ++depth, temp+arr[new_x][new_y]*digit, digit/10);
				depth--;
			}
		}
	}
}

int main()
{
	ifstream input("input.txt");
	int testCase;
	input >> testCase;
	int n = 1;
	while (testCase-- > 0)
	{
		string data;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				input >> arr[i][j];
			}
		}

		int depth = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				dfs(i, j, ++depth, arr[i][j]*1000000, 100000 );
				depth--;
			}
		}
		int cnt = 0;
		for (int i = 0; i < 10000000; i++)
		{
			if (visit[i]) cnt++;
		}
		for (int i = 0; i < 10000000; i++)
		{
			visit[i] = false;
		}
		cout <<"#" << n << " " << cnt << endl;
		n++;
	}
}

// string으로 input 받았을때 런타임 에러가 떠서 int로 고쳐서 풀었다. 
