#include <iostream>
//#include <fstream>
using namespace std;

int map[101][101];
long long dp[101][101];
// 문제에서 경로의 수는 2^63-1보다 작다고 했으니까 
// long long으로 바꿔주기
bool isGo[101][101];
int N;
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };

bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > N)
		return true;
	else return false;
}

void print()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}
	isGo[1][1] = true;
	dp[1][1] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!isGo[i][j]) continue;
			if (i == N && j == N)
			{
				break;
			}
			int a = map[i][j];
			int new_x, new_y;	
			for (int k = 0; k < 2; k++)
			{
				new_x = i + a * dx[k];
				new_y = j + a * dy[k];
				if (isWall(new_x, new_y)) continue;
				isGo[new_x][new_y] = true;
				dp[new_x][new_y] += dp[i][j];
				//print();
			}
		}
	}
	cout << dp[N][N] << '\n';
	return 0;
}

//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//int N, answer;
//int map[101][101];
//int dx[] = { 1, 0 };
//int dy[] = { 0, 1 };
//
//bool isWall(int x, int y)
//{
//	if (x < 1 || y < 1 || x > N || y > N)
//		return true;
//	else return false;
//}
//
//void dfs(int x, int y)
//{
//	if (x == N && y == N)
//	{
//		answer++;
//		return;
//	}
//	int a = map[x][y];
//	int new_x, new_y;
//	for (int i = 0; i < 2; i++)
//	{
//		new_x = x + a*dx[i];
//		new_y = y + a*dy[i];
//		if (isWall(new_x, new_y)) continue;
//		dfs(new_x, new_y);
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	ifstream cin("input.txt");
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			cin >> map[i][j];
//		}
//	}
//	dfs(1, 1);
//	cout << answer << '\n';
//}

// 1번째 풀이 : dfs로 경로의 수 구하기
// 만약 N=100이고 모든 map의 수가 1이면 ?
// 2^10000이라는 어마어마한 재귀함수를 호출해야한다. 당근 시간초과 남..

// 2번째 풀이 : 다이나믹 프로그래밍
// (1,1) 부터 시작하여 도달할 수 있는 좌표를 true표시 한후 누적 경로를 더함으로써 해결 !!!
// 문제에 경로의 수는 2^63-1보다 작다고 했으므로 long long으로 타입을 정하였다.
