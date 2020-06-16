#include <iostream>
//#include <fstream>
#define MIN(A,B) (A<B ? A:B)

using namespace std;
int N, jump_count;
int map[1001];
int dp[1001];
int a;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> map[i];
		dp[i] = 0x7FFFFFFE;
	}

	dp[1] = 0;

	for (int i = 1; i <= N; i++)
	{
		a = map[i];
		for (int j = 0; j <= a; j++)
		{
			dp[i + j] = MIN(dp[i] + 1, dp[i + j]);
		}
	}

	if (dp[N] == 0x7FFFFFFE)
	{
		cout << -1 << '\n';
		return 0;
	}
	cout << dp[N] << '\n';
	
	return 0;
}

// 간단한 DP 구현 문제이다.
// 점화식도 문제 보자마자 바로 생각나서 코딩함.
// 0x7FFFFFFF에서 1을 더하면 맨앞 부호비트가 바뀌어서 -가 됨으로 주의하기.
