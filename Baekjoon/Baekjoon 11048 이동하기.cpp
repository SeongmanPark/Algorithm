#include <iostream>
//#include <fstream>
#define MAX(A,B) (A>B ? A:B)
using namespace std;
int map[1001][1001];
int dp[1001][1001] = { -1 };
int N, M;

int dx[] = { 1,0,1 };
int dy[] = { 0,1,1 };

bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > M) return true;
	else return false;
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
	dp[1][1] = map[1][1];
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (isWall(i + dx[k], j + dy[k])) continue;
				dp[i + dx[k]][j + dy[k]] = MAX(dp[i][j] + map[i + dx[k]][j + dy[k]], dp[i + dx[k]][j + dy[k]]);
			}
		}
	}
	cout << dp[N][M] << '\n';
}

// DP를 이용하여 풀었다.
// isWall 함수가 없어서 런타임 에러가 났었음.
