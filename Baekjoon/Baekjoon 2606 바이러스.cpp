#include <iostream>
//#include <fstream>
#include <queue>
#include <vector>
using namespace std;
int N, E, start_x, end_x, v_size;

bool visit[101];
vector<pair<int, int>> v;
queue<int> q;
int answer = 0;

void bfs()
{
	int cur_x;
	while (!q.empty())
	{
		cur_x = q.front();
		q.pop();
		for (int i = 0; i < v_size; i++)
		{
			if (v[i].first == cur_x)
			{
				if (!visit[v[i].second])
				{
					answer++;
					visit[v[i].second] = true;
					q.push(v[i].second);
				}
			}
			else if (v[i].second == cur_x)
			{
				if (!visit[v[i].first])
				{
					answer++;
					visit[v[i].first] = true;
					q.push(v[i].first);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");
	cin >> N >> E;

	for (int i = 0; i < E; i++)
	{
		cin >> start_x >> end_x;
		v.push_back(make_pair(start_x, end_x));
	}
	visit[1] = true;
	q.push(1);
	v_size = v.size();
	bfs();
	cout << answer << '\n';
	return 0;
}

// BFS를 통해 간단하게 풀이했음
// 큐의 front와 연결된 node를 찾을때 first, second 다 찾아줘야 함 !!
