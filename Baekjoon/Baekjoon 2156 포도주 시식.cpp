#include <iostream>
//#include <fstream>
#define MAX(A,B) (A>B ? A:B)
using namespace std;

int N;
// 1 <= N <= 10000
int map[10001];
int dist[10001];
// 포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 마신 후에는 원래 위치에 다시 놓아야 한다.
// 연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> map[i];
	}
	dist[1] = map[1];
	dist[2] = map[1] + map[2];
	dist[3] = MAX(MAX(dist[2], map[2] + map[3]), map[3] + map[1]);
	// 1,2 // 1,3 // 2,3 중 최대값

	for (int i = 4; i <= N; i++)
	{
		dist[i] = MAX(MAX(dist[i - 1], dist[i - 2] + map[i]), map[i] + map[i - 1] + dist[i - 3]);
	}
	cout << dist[N] << '\n';
}

// dp 문제
// 점화식 잘 세우기 !! line : 29
