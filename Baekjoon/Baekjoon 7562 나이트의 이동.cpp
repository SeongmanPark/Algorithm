#include <iostream>
//#include <fstream>
#include <queue>
#include <cstring>
using namespace std;
int map[301][301];
bool visit[301][301];
int N, testCase, start_x, start_y, end_x, end_y;
int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[] = { -2,-1,1,2,2,1,-1,-2 };
// nigth의 이동경로

struct pos
{
	int x, y;
	int dist;
};

void init()
{
	memset(visit, 0, sizeof(visit));
}

bool isWall(int x, int y)
{
	if (x < 0 || y < 0 || x > N - 1 || y > N - 1) return true;
	else return false;
}

void bfs()
{
	queue<struct pos> q;
	int cur_x, cur_y, new_x, new_y, cur_dist;
	struct pos p, new_p;
	p.x = start_x;
	p.y = start_y;
	p.dist = 0;

	q.push(p);
	while (!q.empty())
	{
		cur_x = q.front().x;
		cur_y = q.front().y;
		cur_dist = q.front().dist;
		q.pop();

		if (cur_x == end_x && cur_y == end_y)
		{
			cout << cur_dist << '\n';
			return;
		}

		for (int i = 0; i < 8; i++)
		{
			new_x = cur_x + dx[i];
			new_y = cur_y + dy[i];
			
			if (isWall(new_x, new_y) || visit[new_x][new_y]) continue;
			// 벽이거나 이미 방문한 노드라면 ??
			visit[new_x][new_y] = true;
			new_p.x = new_x;
			new_p.y = new_y;
			new_p.dist = cur_dist + 1;
			q.push(new_p);
		}
	}
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
		cin >> start_x >> start_y >> end_x >> end_y;
		// 입력 완료
		bfs();
		init();
	}
	return 0;
}

//BFS, 머리 식힐겸 풀었다.
