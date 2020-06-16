#include <iostream>
//#include <fstream>
#include <queue>
#define ABS(A,B) (A>B?A-B:B-A)
#define MIN(A,B) (A<B?A:B)
using namespace std;
int map[101][101];
bool visit[101][101][4];
int N, M, start_x, start_y, end_x, end_y, start_dir, end_dir;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
// 방향 : 동 서 남 북
int answer = 0x7ffff;
struct robot
{
	int x, y, dir, order_count;
};

queue<struct robot> q;

bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > M) return true;
	else return false;
}

void bfs()
{
	struct robot now;
	int new_x, new_y;
	int cur_x, cur_y, cur_dir, cur_order_count;
	while (!q.empty())
	{
		cur_x = q.front().x;
		cur_y = q.front().y;
		cur_dir = q.front().dir;
		cur_order_count = q.front().order_count;
		q.pop();

		if (cur_x == end_x && cur_y == end_y && cur_dir == end_dir - 1)
		{
			answer = MIN(answer, cur_order_count);
			// 최솟값 갱신
		}

		for (int i = 1; i <= 3; i++)
		{
			new_x = cur_x + i*dx[cur_dir];
			new_y = cur_y + i*dy[cur_dir];
			if (isWall(new_x, new_y)) break;
			if (map[new_x][new_y] == 1) break;
			if (visit[new_x][new_y][cur_dir]) continue;
			visit[new_x][new_y][cur_dir] = true;
			now.x = new_x;
			now.y = new_y;
			now.dir = cur_dir;
			now.order_count = cur_order_count + 1;
			q.push(now);
		}
		// 현재 위치, 현재 방향에서 1~3칸 이동할수 있으면 큐에 푸쉬하는 부분.
		now.x = cur_x;
		now.y = cur_y;
		now.order_count = cur_order_count + 1;
		now.dir = (cur_dir + 2) % 4;
		// 0 동 1 서 2 남 3 북
		if(!visit[cur_x][cur_y][now.dir])
		{
			visit[cur_x][cur_y][now.dir] = true;
			q.push(now);
		}
		
		now.dir = cur_dir - 2;

		if (now.dir == -1)
			now.dir = 2;
		else if (now.dir == -2)
			now.dir = 3;
		else if (now.dir == 0)
			now.dir = 1;
		else if (now.dir == 1)
			now.dir = 0;

		if (!visit[cur_x][cur_y][now.dir])
		{
			visit[cur_x][cur_y][now.dir] = true;
			q.push(now);
		}
		// 현재 위치에서 왼쪽으로 방향트는 경우, 오른쪽으로 방향 트는 경우 둘다 큐에 푸쉬
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}
	cin >> start_x >> start_y >> start_dir >> end_x >> end_y >> end_dir;
	struct robot r;
	r.x = start_x;
	r.y = start_y;
	r.dir = start_dir - 1;
	r.order_count = 0;
	q.push(r);

	bfs();
	cout << answer << '\n';
}

// 52번째 라인에서 break로 생각했다가 헤맸던 문제.
// 더 나은 경우가 있음에도 불구하고 큐에 넣지 못한다.
