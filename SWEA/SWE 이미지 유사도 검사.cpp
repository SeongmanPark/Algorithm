#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#define MAX(A,B) (A>B ? A:B)
using namespace std;
int testCase, N;
int dp[501][501];
int a = 1;
void init()
{
	memset(dp, 0, sizeof(dp));
	a++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("input.txt");

	cin >> testCase;
	register string s1, s2;
	while (testCase-- > 0)
	{
		cin >> N;
		cin >> s1 >> s2;
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (s1[i] == s2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
				else dp[i + 1][j + 1] = MAX(dp[i + 1][j], dp[i][j + 1]);
			}
		}
		cout << fixed;
		cout.precision(2);
		cout << "#" << a << " " << (double)dp[N][N] * 100 / N << "\n";
		init();
	}
}

// 전형적인 dp문제이다.
// 배열을 2번 돌면서 이 전에 계산한 결과값과 새로운 결과값 중 큰 
