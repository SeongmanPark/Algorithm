#include <iostream>
#include <cstring>
//#include <fstream>
#include <vector>
#define MAX(A,B) (A>B?A:B)
using namespace std;

int T, P, N;
vector<pair<int, int>> v;
int answer;

void dfs(int index, int cost)
{
	
	answer = MAX(cost, answer);

	for (int i = index ; i <= N; i++)
	{
		if (v[i].first + i > N + 1) continue;
		else
		{
			dfs(i + v[i].first, cost + v[i].second);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream input("input.txt");

	input >> N;
	v.push_back(make_pair(0, 0));
	for (int i = 0; i < N; i++)
	{
		input >> T >> P;
		v.push_back(make_pair(T, P));
	}

	for (int i = 1; i <= N; i++)
	{
		if (v[i].first + i > N + 1) continue;
		dfs(i + v[i].first, v[i].second);
	}

	cout << answer << '\n';
}

// 간단한 
