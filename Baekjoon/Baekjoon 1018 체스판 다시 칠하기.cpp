#include <iostream>
//#include <fstream>
// 체스판
#define MIN(A,B) (A<B ? A:B)
using namespace std;
int N, M;
int answer = 0x7FFFFFFF;
char map[51][51];

void start1(int x, int y)
{
	int misscount = 0;
	
	for (int i = x; i < x + 8; i++)
	{
		for (int j = y; j < y + 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				if (map[i][j] != 'B')
				{
					misscount++;
				}
			}
			else
			{
				if (map[i][j] != 'W')
				{
					misscount++;
				}
			}

			if (misscount >= answer)
				return;
		}
	}

	answer = MIN(answer, misscount);
}

void start2(int x, int y)
{
	int misscount = 0;

	for (int i = x; i < x + 8; i++)
	{
		for (int j = y; j < y + 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				if (map[i][j] == 'B')
				{
					misscount++;
				}
			}
			else
			{
				if (map[i][j] == 'W')
				{
					misscount++;
				}
			}

			if (misscount >= answer)
				return;
		}
	}

	answer = MIN(answer, misscount);
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
	
	for (int i = 1; i <= N - 7; i++)
	{
		for (int j = 1; j <= M - 7; j++)
		{
			start1(i, j);
			start2(i, j);
		}
	}

	cout << answer << '\n';
}

// 맨 위가 B인 경우와 W인 경우 두 경우를 생각하며 간단하게 구현하였다 (완탐)
