#include <iostream>
//#include <fstream>
#include <cstring>
#define MIN(A,B) (A<B ? A:B)
using namespace std;
int testCase, D, W, K;
int map[14][21];
int temp_map[14][21];
int answer;
int r[14];
int a = 1;

void init()
{
	a++;
}

bool check()
{
	// 0 은 A, 1은 B
	int A_cnt = 0;
	int B_cnt = 0;
	bool flag = false;

	for (int j = 1; j <= W; j++)
	{
		A_cnt = 0; B_cnt = 0;
		flag = false;
		for (int i = 1; i <= D; i++)
		{
			if (temp_map[i][j] == 0)
			{
				A_cnt++;
				B_cnt = 0;
			}
			else if (temp_map[i][j] == 1)
			{
				B_cnt++;
				A_cnt = 0;
			}

			if (A_cnt == K || B_cnt == K)
			{
				flag = true;
			}
		}
		if (!flag) return false;
	}
	return true;
}

void simulation(int depth, int cnt) // 세로의 index, 약품 투여 횟수 !!
{
	if (cnt > K || cnt >= answer) return;
	if (depth == D + 1)
	{
		for (int i = 1; i <= D; i++)
		{
			switch (r[i])
			{
				case -1:
				{
					for (int j = 1; j <= W; j++)
						temp_map[i][j] = map[i][j];
					continue;
				}
				case 0:
				{
					for (int j = 1; j <= W; j++)
						temp_map[i][j] = 0;
					continue;
				}
				case 1:
				{
					for (int j = 1; j <= W; j++)
						temp_map[i][j] = 1;
					continue;
				}
			}
		}
		if (check())
		{
			answer = MIN(answer, cnt);
		}
		return;
	}
	r[depth] = -1; // 그냥 냅두기
	simulation(depth + 1, cnt);
	r[depth] = 0; // A로 바꾸기
	simulation(depth + 1, cnt + 1);
	r[depth] = 1; // B로 바꾸기
	simulation(depth + 1, cnt + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");
	cin >> testCase;
	while (testCase-- > 0)
	{
		cin >> D >> W >> K;
		answer = K;
		for (int i = 1; i <= D; i++)
		{
			r[i] = -1;
			for (int j = 1; j <= W; j++)
			{
				cin >> map[i][j];
			}
		}
		// 입력완료
		simulation(1, 0);
		cout << "#" << a << " " << answer << '\n';
		init();
	}
}

// 조합을 구현할 때 for문을 쓰기보다 
//r[depth] = -1; // 그냥 냅두기
//simulation(depth + 1, cnt);
//r[depth] = 0; // A로 바꾸기
//simulation(depth + 1, cnt + 1);
//r[depth] = 1; // B로 바꾸기
//simulation(depth + 1, cnt + 1);
// 식으로 구현하는게 시간이 더 적게 걸린다. 왜 그런지 확인해봐야 할 것 같다.
