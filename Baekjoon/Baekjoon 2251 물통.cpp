#include <iostream>
#include <vector>
//#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;
int A, B, C;
bool visit[201][201][201];
bool check[201];
vector<int> v;

void bfs()
{
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), C));
	visit[0][0][C] = true;
	
	while (!q.empty())
	{
		int now_A = q.front().first.first;
		int now_B = q.front().first.second;
		int now_C = q.front().second;
		q.pop();
		// 현재 물통의 상태 출력하기
		if (now_A == 0 && !check[now_C])
		{
			check[now_C] = true;
			v.push_back(now_C);
		}
		// A물통이 비었을때 C물통의 용량 구하기, 중복제거
		
		// A->B
		if (B > now_A + now_B)
		{
			if (!visit[0][now_A + now_B][now_C])
			{
				visit[0][now_A + now_B][now_C] = true;
				q.push(make_pair(make_pair(0, now_A + now_B), now_C));
			}
		}
		else
		{
			if (!visit[now_A + now_B - B][B][now_C])
			{
				visit[now_A + now_B - B][B][now_C] = true;
				q.push(make_pair(make_pair(now_A + now_B - B, B), now_C));
			}
		}
		// B->A
		if (A > now_A + now_B)
		{
			if (!visit[now_A + now_B][0][now_C])
			{
				visit[now_A + now_B][0][now_C] = true;
				q.push(make_pair(make_pair(now_A + now_B, 0), now_C));
			}
		}
		else
		{
			if (!visit[A][now_A + now_B - A][now_C])
			{
				visit[A][now_A + now_B - A][now_C] = true;
				q.push(make_pair(make_pair(A, now_A + now_B - A), now_C));
			}
		}
		// B->C
		if (C > now_B + now_C)
		{
			if (!visit[now_A][0][now_B + now_C])
			{
				visit[now_A][0][now_B + now_C] = true;
				q.push(make_pair(make_pair(now_A, 0), now_B + now_C));
			}
		}
		else
		{
			if (!visit[now_A][now_B + now_C - C][C])
			{
				visit[now_A][now_B + now_C - C][C] = true;
				q.push(make_pair(make_pair(now_A, now_B + now_C - C), C));
			}
		}
		// C->B
		if (B > now_B + now_C)
		{
			if (!visit[now_A][now_B + now_C][0])
			{
				visit[now_A][now_B + now_C][0] = true;
				q.push(make_pair(make_pair(now_A, now_B + now_C), 0));
			}
		}
		else
		{
			if (!visit[now_A][B][now_B + now_C - B])
			{
				visit[now_A][B][now_B + now_C - B] = true;
				q.push(make_pair(make_pair(now_A, B), now_B + now_C - B));
			}
		}
		// A->C
		if (C > now_A + now_C)
		{
			if (!visit[0][now_B][now_A + now_C])
			{
				visit[0][now_B][now_A + now_C] = true;
				q.push(make_pair(make_pair(0, now_B), now_A + now_C));
			}
		}
		else
		{
			if (!visit[now_A + now_C - C][now_B][C])
			{
				visit[now_A + now_C - C][now_B][C] = true;
				q.push(make_pair(make_pair(now_A + now_C - C, now_B), C));
			}
		}
		// C->A
		if (A > now_A + now_C)
		{
			if (!visit[now_A + now_C][now_B][0])
			{
				visit[now_A + now_C][now_B][0] = true;
				q.push(make_pair(make_pair(now_A + now_C, now_B), 0));
			}
		}
		else
		{
			if (!visit[A][now_B][now_A + now_C - A])
			{
				visit[A][now_B][now_A + now_C - A] = true;
				q.push(make_pair(make_pair(A, now_B), now_A + now_C - A));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");
	cin >> A >> B >> C;
	bfs();

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}

// 제일 처음 모든 경우의 수를 따지려다가 완전탐색이란것을 깨닫고 BFS로 풀었다.
// if else 구문이 많아 실수하기 쉽다.
