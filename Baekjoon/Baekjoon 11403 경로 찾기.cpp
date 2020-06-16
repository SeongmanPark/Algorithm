#include <iostream>
//#include <fstream>
#include <cstring>
#include <queue>
using namespace std;
int N;
int map[101][101];
bool visit[101] = { false };

queue<int> q;

void print()
{
	for (int i = 1; i <= N; i++)
	{
		if (visit[i])
		{
			cout << 1 << " ";
		}
		else
		{
			cout << 0 << " ";
		}
	}
	cout << '\n';
}

void bfs(int index)
{
	q.push(index);
	// 이번에 완성시킬 row는 index째 row
	int pre_node;

	while (!q.empty())
	{
		pre_node = q.front();
		q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (map[pre_node][i] == 1) // 만약 다음 노드로 갈 수 있다면 ???
			{
				if (visit[i]) continue; // 이미 큐에 넣었던 노드라면 ? continue
				else
				{
					visit[i] = true; // 아니면 방문하고 
					q.push(i);	// q에 넣어준다
				}
			}
		}
	}
	// 이 while문이 끝이나면 visit배열에 체크된 노드들은 index노드에서 갈 수 있는 노드들이므로 출력해주면 끝 !!!!!
	print();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];

	for (int i = 1; i <= N; i++)
	{
		memset(visit, 0, sizeof(visit));
		bfs(i);
		// 한줄 한줄씩 bfs 돌려보자 !!!!!!!!
	}
}

// bfs를 이용하여 인접 노드간의 관계를 잘 따지면 간단하게 풀리는 문제 !!!
