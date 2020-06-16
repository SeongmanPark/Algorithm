#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


bool visit[101] = { false };
int testCase, N, data1, data2;
int answer = 10000000;
vector<pair<int, int>> v;
vector<pair<int, int>> customer;

void init()
{
	memset(visit, 0, sizeof(visit));
	answer = 10000000;
	v.clear();
	customer.clear();
}

void dfs(int depth, int distance, int pre)
{
	if (distance >= answer)
	{
		return;	
	}
	
	if (depth == N)
	{	
		answer = min(answer, distance + abs(v[1].first - customer[pre].first) + abs(v[1].second - customer[pre].second));
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			dfs(depth + 1, distance + abs(customer[pre].first - customer[i].first) + abs(customer[pre].second - customer[i].second), i);	// i는 선택된놈
			visit[i] = false;
		}
	}
}

int main()
{
	ifstream input("input.txt");
	input >> testCase;
	int a = 1;
	while (testCase-- > 0)
	{
		input >> N;
		input >> data1 >> data2;
		v.push_back(make_pair(data1, data2));
		input >> data1 >> data2;
		v.push_back(make_pair(data1, data2));
		// 회사 v[0] , 집 v[1]

		for (int i = 1; i <= N; i++)
		{
			input >> data1 >> data2;
			customer.push_back(make_pair(data1, data2));
		}
		// 고객의 좌표 입력 완료
		for (int i = 0; i < N; i++)
		{
			if (!visit[i])
			{
				visit[i] = true;
				dfs(1, abs(v[0].first - customer[i].first) + abs(v[0].second - customer[i].second), i);	// i는 선택된놈
				visit[i] = false;
			}
		}

		cout <<"#" << a<< " "<< answer << '\n';
		a++;
		init();
	}
}

// dfs를 이용하여 순열을 구현하고 모든 경로를 탐색하였다. 가지치기 25번째 줄이 중요하다.
// 그래도 시간초과가 나서 visit을 2차원 배열이 아닌, 벡터로 구현하였다.
