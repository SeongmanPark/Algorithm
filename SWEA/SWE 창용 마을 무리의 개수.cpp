#include <iostream>
//#include <fstream>
#include <cstring>
using namespace std;
int testCase, N, M, a, b;
int p[101];
int TC = 1;

void init()
{
	memset(p, 0, sizeof(p));
	TC++;
}

void Make_set(int N)
{
	for (int i = 1; i <= N; i++) p[i] = i;
}

int Find_set(int x)
{
	if (x != p[x])
	{
		p[x] = Find_set(p[x]);
	}
	return p[x];
}

void Union(int x, int y)
{
	p[Find_set(y)] = Find_set(x);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//ifstream cin("input.txt");
	cin >> testCase;
	while (testCase-- > 0)
	{
		cin >> N >> M;
		// N 은 사람의 수, M은 관계의 수
		Make_set(N);
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
			Union(a, b);
		}
		int ans = 0;
		for (int i = 1; i <= N; i++)
		{
			if (p[i] == i) ans++;
		}
		cout << "#" << TC << " " << ans << '\n';
		init();
	}
}

// Union Find를 사용하여 간단하게 풀었다.
