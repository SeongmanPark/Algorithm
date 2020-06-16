#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

int testCase, N;
int input_data[13];
int op[5];
int max_total = -100000001;
int min_total = 100000001;
int a = 1;
// 모든 인덱스 1부터 시작

void init()
{
	a++;
	memset(input_data, 0, sizeof(input_data));
	memset(op, 0, sizeof(op));
	max_total = -100000001;
	min_total = 100000001;
}

void dfs(int depth, int total)
{
	if (depth == N+1)
	{
		max_total = max(total, max_total);
		min_total = min(total, min_total);
		return;
	}

	for (int i = 1; i <= 4; i++)
	{
		switch (i)
		{
		case 1:
		{
			if (op[i] != 0)
			{
				op[i]--;
				dfs(depth + 1, total + input_data[depth]);
				op[i]++;
				break;
			}
		}
		case 2:
		{
			if (op[i] != 0)
			{
				op[i]--;
				dfs(depth + 1, total - input_data[depth]);
				op[i]++;
				break;
			}
		}
		case 3:
		{
			if (op[i] != 0)
			{
				op[i]--;
				dfs(depth + 1, total * input_data[depth]);
				op[i]++;
				break;
			}
		}
		case 4:
		{
			if (op[i] != 0)
			{
				op[i]--;
				dfs(depth + 1, total / input_data[depth]);
				op[i]++;
				break;
			}
		}
		}
	}
}

int main()
{
	ifstream input("input.txt");
	input >> testCase;

	while (testCase-- > 0)
	{
		input >> N;
		for (int i = 1; i <= 4; i++)
		{
			input >> op[i];
		}

		for (int i = 1; i <= N; i++)
		{
			input >> input_data[i];
		}
		
		for (int i = 1; i <= 4; i++)
		{
			switch(i)
			{
				case 1:
				{
					if (op[i] != 0)
					{
						op[i]--;
						dfs(3, input_data[1] + input_data[2]);
						op[i]++;
						break;
					}
				}
				case 2:
				{
					if (op[i] != 0)
					{
						op[i]--;
						dfs(3, input_data[1] - input_data[2]);
						op[i]++;
						break;
					}
				}
				case 3:
				{
					if (op[i] != 0)
					{
						op[i]--;
						dfs(3, input_data[1] * input_data[2]);
						op[i]++;
						break;
					}
				}
				case 4:
				{
					if (op[i] != 0)
					{
						op[i]--;
						dfs(3, input_data[1] / input_data[2]);
						op[i]++;
						break;
					}
				}
			}
		}

		cout << "#" << a << " " << max_total - min_total << '\n';
		init();
	}
}

// 순열을 이용하여 손 쉽게 풀어보았습니다.
