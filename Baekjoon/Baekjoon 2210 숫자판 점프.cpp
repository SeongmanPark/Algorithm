#include <iostream>
//#include <fstream>

using namespace std;
int map[6][6];
bool visit[1000000];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int answer;
bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > 5 || y > 5) return true;
	else return false;
}

void dfs(int depth, int sum, int digit, int x, int y)
{
	if (depth == 6)
	{
		if (visit[sum]) return;
		else
		{
			visit[sum] = true;
			answer++;
			return;
		}
		
	}
	
	int new_x, new_y;
	for (int i = 0; i < 4; i++)
	{
		new_x = x + dx[i];
		new_y = y + dy[i];
		if (isWall(new_x, new_y)) continue;
		dfs(depth + 1, sum + digit * map[new_x][new_y], digit * 10, new_x, new_y);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");

	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			cin >> map[i][j];
	// 입력 완료..
	
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			dfs(1, map[i][j], 10, i, j);
		}
	}

	cout << answer << '\n';
}

// dfs
