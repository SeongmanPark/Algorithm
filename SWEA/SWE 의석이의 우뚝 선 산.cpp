#include <iostream>
//#include <fstream>
#include <cstring>

using namespace std;

int testCase, answer, N;
int mountain[50001] = { 0, };
bool visit[50001] = { false };
int a = 1;

void init()
{
	answer = 0;
	memset(mountain, 0, sizeof(mountain));
	a++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream input("input.txt");

	cin >> testCase;
	while (testCase-- > 0)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> mountain[i];
		}
		// 산 정보 입력 완료 !!
			
		for (int i = 2; i <= N - 1; i++)
		{
			if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1])
			{
				int left = i - 1;
				int right = i + 1;
				int left_count = 1;
				int right_count = 1;
				while (left != 1)
				{
					if (mountain[left] > mountain[left - 1])
					{
						left_count++;
						left--;
					}
					else
					{
						break;
					}
				}
				while (right != N)
				{
					if (mountain[right] > mountain[right + 1])
					{
						right_count++;
						right++;
					}
					else
					{
						break;
					}
				}
				answer += right_count * left_count;
			}
		}

		cout <<"#" << a << " " << answer << '\n';
		init();
	}
}

// 제일 우뚝 선 놈을 기준으로 m(i) > m(i-1) 의 개수와
// m(i) > m(i+1) 의 개수를 곱하는것만 알면 간단하게 풀 수 있다.
