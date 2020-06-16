#include <iostream>
//#include <fstream>
#define MIN(A,B) (A<B ? A:B)

using namespace std;
int N;
int map[11][11];
bool visit[11][11] = { false };
int answer = 0x7FFFFFFF;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void dfs(int depth, int total)
{
	if (depth == 3)
	{
		answer = MIN(answer, total);
		return;
	}

	for (int i = 2; i <= N - 1; i++)
	{
		for (int j = 2; j <= N - 1; j++)
		{
			if (!visit[i][j] && !visit[i-1][j] && !visit[i+1][j] && !visit[i][j-1] && !visit[i][j+1])
			{
				visit[i][j] = true;
				int sum = map[i][j];
				for (int k = 0; k < 4; k++)
				{
					visit[i + dx[k]][j + dy[k]] = true;
					sum += map[i + dx[k]][j + dy[k]];
				}
				dfs(depth + 1, sum + total);
				visit[i][j] = false;
				for (int k = 0; k < 4; k++)
				{
					visit[i + dx[k]][j + dy[k]] = false;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];

	for (int i = 2; i <= N - 1; i++)
	{
		for (int j = 2; j <= N - 1; j++)
		{
			if (!visit[i][j])	// 방문하지 않았다면 ?
			{
				visit[i][j] = true;
				int sum = map[i][j];
				for (int k = 0; k < 4; k++)
				{
					visit[i + dx[k]][j + dy[k]] = true;
					sum += map[i + dx[k]][j + dy[k]];
				}
				dfs(1, sum);
				visit[i][j] = false;
				for (int k = 0; k < 4; k++)
				{
					visit[i + dx[k]][j + dy[k]] = false;
				}
			}
		}
	}
	cout << answer << '\n';
}

// 조합을 이용하여 풀었다.
// visit 배열 체크만 신경쓰면 굉장히 쉬운 
