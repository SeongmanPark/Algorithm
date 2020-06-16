#include <iostream>
//#include <fstream>

using namespace std;
int testCase, N, M, a, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");

	cin >> testCase;
	while (testCase-- > 0)
	{
		cin >> N >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
		}
		cout << N - 1 << '\n';
	}
}
// MST의 간선의 개수는 N-1
