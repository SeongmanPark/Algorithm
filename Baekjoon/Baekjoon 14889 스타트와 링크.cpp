#include <iostream>
//#include <fstream>
using namespace std;

int N;
int map[21][21];
bool visit[21] = { false };
int answer = 1000000000;

void dfs(int depth, int start_index)
{
	if (depth > N / 2)	// 이제 계산하기
	{
		int start_team = 0;
		int link_team = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j) continue;
				if (visit[i] && visit[j])
				{
					start_team += map[i][j];
				}
				else if (!visit[i] && !visit[j])
				{
					link_team += map[i][j];
				}
			}
		}
		int temp_answer = 0;
		if (start_team - link_team < 0) {
			temp_answer = link_team - start_team;
		}
		else
		{
			temp_answer = start_team - link_team;
		}

		if (answer > temp_answer)
		{
			answer = temp_answer;
		}
		return;
	}

	for (int i = start_index + 1; i <= N; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			dfs(depth + 1, i);
			visit[i] = false;
		}
	}
}

int main()
{
	//ifstream input("input.txt");
	input >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			input >> map[i][j];
		}
	}
	// 배열 입력 완료

	int depth = 1;
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			// 숫자 i 고르고
			dfs(depth + 1, i);
			// depth 1 증가
			visit[i] = false;
		}
	}
	cout << answer << '\n';
}	
// 조합을 이용하여 간단하게 풀었다. 순열조합 재귀로 구현하는게 아직 서툴다.
