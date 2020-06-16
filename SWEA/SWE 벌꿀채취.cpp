#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int testCase, N, M, C;
int map[11][11];
bool check[11][11] = { false };
bool v_check[5] = { false };
int a = 1;
int temp_answer1, temp_answer2, answer;
vector<int> v;

void middle_clear()
{
	v.clear();
	memset(v_check, 0, sizeof(v_check));
}

void init()
{
	a++;
	memset(map, 0, sizeof(map));
	memset(check, 0, sizeof(check));
	answer = 0;
}

void compute2(int depth, int weight, int honey, int start_index)	// 0~M 범위중 가장 큰 꿀 리턴하기 !!
{
	if (weight > C)
	{
		return;
	}

	if (depth == M)
	{
		temp_answer2 = max(temp_answer2, honey);
		return;
	}

	for (int i = start_index; i < v.size(); i++)
	{
		if (v_check[i]) continue;

		v_check[i] = true;
		compute2(depth + 1, weight + v[i], honey + (v[i] * v[i]), start_index + 1);	// 포함하고
		compute2(depth + 1, weight, honey, start_index + 1);	// 안하고
		v_check[i] = false;
	}
}

void compute1(int depth, int weight, int honey, int start_index)	// 0~M 범위중 가장 큰 꿀 리턴하기 !!
{
	if (weight > C)
	{
		return;
	}

	if (depth == M)
	{
		temp_answer1 = max(temp_answer1, honey);
		return;
	}
	
	for (int i = start_index; i < v.size(); i++)
	{
		if (v_check[i]) continue;

		v_check[i] = true;
		compute1(depth + 1, weight + v[i], honey + (v[i] * v[i]), start_index + 1);	// 포함하고
		compute1(depth + 1, weight, honey, start_index + 1);	// 안하고
		v_check[i] = false;
	}
}

void choice(int start_row, int start_colon)
{
	for (int i = start_row; i <= N; i++)
	{
		int j;
		if(i == start_row)
		{
			j = start_colon;
		}
		else
		{
			j = 1;
		}
		for (j ; j <= N - M + 1; j++)
		{
			if (check[i][j]) continue;
			for (int index = 0; index < M; index++)
			{
				check[i][j + index] = true;
				v.push_back(map[i][j + index]);
			}
			compute2(0, 0, 0, 0);
			middle_clear();
			answer = max(temp_answer1 + temp_answer2, answer);
			temp_answer2 = 0;
			for (int index = 0; index < M; index++)
			{
				check[i][j + index] = false;
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
		input >> N >> M >> C;
		for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) input >> map[i][j];
		// 벌꿀 정보 입력 완료

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N - M + 1; j++)
			{
				for (int index = 0; index < M; index++)
				{
					check[i][j + index] = true;
					v.push_back(map[i][j + index]);
				}
				compute1(0, 0, 0, 0);
				middle_clear();
				choice(i, j + M);
				temp_answer1 = 0;
				for (int index = 0; index < M; index++)
				{
					check[i][j + index] = false;
				}
			}
		}

		cout << "#" << a << " " << answer << '\n';
		init();
	}
}

// 코드를 지저분하게 짰다. 부분집합 생성하는 부분에서 고민을 하였다 (연습 더 필요)
// 꿀통을 정하고 부분집합 중 최대값을 구하는것 보다 배열에 대해 부분집합의 최대값을 다 구해논 다음 꿀통 2개를 고르면
// 시간이 더 빠르게 나올것이다.
