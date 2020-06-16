#include <iostream>
//#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

int testCase;
int plan[13];
int pay[5];
int total = 10000000000;
int a = 1;
// 모든 인덱스 1부터 시작

void init()
{
	total = 10000000000;
	a++;
}

void dfs(int month, int cost)
{
	if (month == 13)
	{
		total = min(total, cost);
		return;
	}

	if (cost >= total)
	{
		return;
	}

	for (int i = 1; i <= 4; i++)
	{
		switch (i)
		{
			case 1:
			{
				dfs(month + 1, cost + (plan[month] * pay[i]) );
				break;
			}
			case 2:
			{
				dfs(month + 1, cost + pay[i]);
				break;
			}
			case 3:
			{
				dfs(month + 3, cost + pay[i]);
				break;
			}
			case 4:
			{
				dfs(13, cost + pay[i]);
				break;
			}
		}
	}
}

int main()
{
	//ifstream input("input.txt");
	input >> testCase;

	while (testCase-- > 0)
	{
		for (int i = 1; i <= 4; i++)
		{
			input >> pay[i];	// 1일, 1달, 3달, 1년 (1, 2, 3, 4)
		}
		for (int i = 1; i <= 12; i++)
		{
			input >> plan[i];
		}
		// 연 계획, 비용 저장 완료

		for (int i = 1; i <= 4; i++)
		{
			switch (i)
			{
				case 1:
				{
					dfs(2, plan[1] * pay[i]);
					break;
				}
				case 2:
				{
					dfs(2, pay[i]);
					break;
				}
				case 3:
				{
					dfs(4, pay[i]);
					break;
				}
				case 4:
				{
					dfs(13, pay[i]);
					break;
				}
			}
		}
		cout << "#" << a << " " << total << '\n';
		init();
	}
}

// 나올수 있는 모든 경우의수를 구하여 코드를 작성하였다. 
