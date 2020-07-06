#include <iostream>
//#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
#define ABS(A,B) (A>B ? A-B:B-A)
using namespace std;

int testCase, N, start_x, start_y, end_x, end_y, store_x, store_y;
bool visit[100];
// 편의점 방문 여부
bool isHappy = false;
vector<pair<int, int>> v;
queue<pair<int, int>> q;

void init()
{
	v.clear();
	while (!q.empty())
		q.pop();
	memset(visit, 0, sizeof(visit));
	isHappy = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");
	cin >> testCase;
	while (testCase-- > 0)
	{
		cin >> N;
		cin >> start_x >> start_y;
		for (int i = 1; i <= N; i++)
		{
			cin >> store_x >> store_y;
			v.push_back(make_pair(store_x, store_y));
		}
		// 편의점 좌표 다 떄려넣기
		cin >> end_x >> end_y;
		q.push(make_pair(start_x, start_y));
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (ABS(x, end_x) + ABS(y, end_y) <= 1000)
			{
				isHappy = true;
				break;
			}

			for (int i = 0; i < v.size(); i++)
			{
				if (visit[i]) continue;
				int dist = ABS(x, v[i].first) + ABS(y, v[i].second);
				// 거리구해서 1000이하면 큐에 넣고 방문체크 해주기
				if (dist <= 1000)
				{
					q.push(make_pair(v[i].first, v[i].second));
					visit[i] = true;
				}
			}
		}
		if (isHappy)
		{
			cout << "happy" << '\n';
		}
		else cout << "sad" << '\n';
		init();
	}
}

// BFS로 풀었다.
// 갈 수 있는 편의점을 차례대로 방문하면서 end point 까지 거리 구해주면 됨.
