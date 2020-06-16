// 준환이의 양팔 저울
#include <iostream>
//#include <fstream>
#include <cstring>

using namespace std;
int weight[10];
int N, testCase;
bool visit[10] = { false };
int factorial[10];
// 추 순열을 위한 배열
int answer, total_weight;
int a = 1;

void compute()
{
	factorial[0] = 1;
	for (int i = 1; i < 10; i++)
	{
		factorial[i] = factorial[i - 1] * i;
	}
}

void init()
{
	memset(visit, 0, sizeof(visit));
	memset(weight, 0, sizeof(weight));
	total_weight = answer = 0;
	a++;
}

void dfs(int depth, int left_weight, int right_weight)	// depth는 고른 추의 개수
{
	if (right_weight > left_weight)
		return;

	if (left_weight > total_weight / 2)
	{
		// 남은 추의 개수 N - depth
		answer += (1 << N - depth) * factorial[N - depth];
		return;
	}
	// 왼쪽 무게가 전체무게의 반이 넘으면 ??? 아무리 조합해도 왼쪽이 더 크니까 
	// 더 재귀함수 호출할 필요없이 남은 2^N * N! 값 구하면 됨.

	if (depth == N)
	{
		//cout << left_weight << " " << right_weight << '\n';
		answer++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			// 아직 올리지 않는 추가 있다면?
			visit[i] = true;
			dfs(depth + 1, left_weight + weight[i], right_weight);	// 그놈을 왼쪽에다 올려보고
			dfs(depth + 1, left_weight, right_weight + weight[i]);	// 왼쪽에다 올려보고
			visit[i] = false;
		}
	}
}


int main()
{
	//ifstream cin("input.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> testCase;
	while (testCase-- > 0)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> weight[i];
			total_weight += weight[i];
		}
		// 무게 입력 완료
		compute();
		// 팩토리얼의 값 구하기
		dfs(0, 0, 0);
		cout << "#" << a << " " << answer << '\n';
		init();
	}
}

// 완탐으로 구현했지만 시간초과 났다.
// 가지치기를 통해 시간을 줄여보려고 했으나 내가 생각한 방법과 다른 방식의 가지치기였다.
// 전체 추의 무게를 구하고, 왼쪽 무게의 합이 전체 추 무게 합의 절반 이상이면 남은 추 가지고 2^N * N! 구하면 됨 
// 만약 시험장이였으면 생각 못할것 같다.. 
