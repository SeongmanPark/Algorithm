#include <iostream>
//#include <fstream>

using namespace std;
int N;
int score[101];
int op[4];
int max_answer = -10000000000;
int min_answer = 100000000000;
void dfs(int index, int answer, int depth)
{
	if (depth == N - 1)
	{
		if (answer > max_answer)
		{
			max_answer = answer;
		}
		if (answer < min_answer)
		{
			min_answer = answer;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] != 0)
		{
			switch (i)
				{
				case 0:
				{
					op[i]--;
					dfs(index + 1, answer + score[index], depth + 1);
					op[i]++;
					break;
				}
				case 1:
				{
					op[i]--;
					dfs(index + 1, answer - score[index], depth + 1);
					op[i]++;
					break;
				}
				case 2:
				{
					op[i]--;
					dfs(index + 1, answer * score[index], depth + 1);
					op[i]++;
					break;
				}
				case 3:
				{
					op[i]--;
					if (answer < 0)	// 음수이면 ?
					{
						answer = ~answer + 1;
						answer /= score[index];
						answer = ~answer + 1;
					}
					else
					{
						answer /= score[index];
					}
					dfs(index + 1, answer, depth + 1);
					op[i]++;
					break;
				}
			}
		}
	}
}

int main()
{
	//ifstream input("input.txt");
	input >> N;
	for (int i = 1; i <= N; i++)
	{
		input >> score[i];
	}
	for (int i = 0; i < 4; i++)
	{
		input >> op[i];
	}
	// 입력 완료
	int answer = score[1];
	int depth = 0;
	dfs(2, answer, depth);
	cout << max_answer << '\n' << min_answer << '\n';
}

// 완탐 이용하여 모든 경우의 수를 다 따졌다.
