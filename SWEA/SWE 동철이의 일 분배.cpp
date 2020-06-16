#include <iostream>
//#include <fstream>
#include <math.h>
#include <cstring>
using namespace std;

int task[17][17];
double answer = 0;

void dfs(int N, int depth, bool *colon, double sucess)
{

	if (depth == N && sucess >= answer)
	{
		answer = sucess;
		return;
	}

	if (sucess <= answer)	// 가지치기
	{
		return;
	}

	else
	{
		for (int i = 1; i <= N; i++)
		{
			if (!colon[i])
			{
				colon[i] = true;
				depth++;
				dfs(N, depth, colon, sucess * task[depth][i] * 0.01);
				depth--;
				colon[i] = false;
			}
		}
	}
}

int main()
{
	//ifstream input("input.txt");
	int testCase, N, data;
	cin >> testCase;
	int a = 1;
	while (testCase-- > 0)
	{
		cin >> N;
		for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> task[i][j];

		bool colon[17] = { false };
		double sucess = 1;

		int depth = 0;
		for (int i = 1; i <= N; i++)
		{
			if (!colon[i])
			{
				colon[i] = true;
				depth++;
				dfs(N, depth, colon, sucess * task[depth][i] * 0.01);
				depth--;
				colon[i] = false;
			}
		}
		cout << "#" << a << " ";
		answer *= 100;
		cout << fixed;
		cout.precision(6);
		cout << round(answer * 1000000) / 1000000 << '\n';
		a++;
		memset(task, 0, sizeof(task));
		answer = 0;
	}
}

// 가지치기 조건 잘 세우기, 조건검사 방법 잘 정하기 -> 
