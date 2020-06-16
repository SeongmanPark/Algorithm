#include <iostream>
//#include <fstream>
#include <queue>
using namespace std;
int N, start_x, end_x, M;
int answer = -1;
int map[101][2];
bool visit[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");
	cin >> N >> start_x >> end_x;
	cin >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> map[i][0] >> map[i][1];
	}
	// 입력 완료 !!

	queue<pair<int, int>> q;
	q.push(make_pair(start_x, 0));
	// 시작점과 촌수 삽입
	visit[start_x] = true;
	while (!q.empty())
	{
		int now = q.front().first;
		int dist = q.front().second;
		q.pop();
		if (now == end_x)
		{
			answer = dist;
			break;
		}
		for (int i = 1; i <= M; i++)
		{
			if (map[i][0] == now)
			{
				if (visit[map[i][1]]) continue;
				q.push(make_pair(map[i][1], dist + 1));
				visit[map[i][1]] = true;
			}
			else if (map[i][1] == now)
			{
				if (visit[map[i][0]]) continue;
				q.push(make_pair(map[i][0], dist + 1));
				visit[map[i][0]] = true;
			}
		}
	}
	cout << answer << '\n';
	return 0;
}

// BFS 구현 간단.
