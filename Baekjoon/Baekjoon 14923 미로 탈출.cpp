#include <iostream>
//#include <fstream>
#include <queue>

using namespace std;
int N, M, start_x, start_y, end_x, end_y;
int map[1001][1001];
bool visit[1001][1001][2];
int answer = 0x7FFFFFFF;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
// 상, 하, 좌, 우

struct pos
{
	int cur_x, cur_y;
	int dist;
	bool block;
};

bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > M) return true;
	else return false;
}

void bfs()
{
	struct pos p;
	struct pos now;
	p.cur_x = start_x;
	p.cur_y = start_y;
	p.dist = 0;
	p.block = false;
	queue <struct pos> q;
	// 좌표와 벽 부순 여부
	int new_x, new_y, cur_x, cur_y, block, dist;
	q.push(p);
	visit[1][1][0] = true;

	while (!q.empty())
	{
		cur_x = q.front().cur_x;
		cur_y = q.front().cur_y;
		dist = q.front().dist;
		block = q.front().block;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			new_x = cur_x + dx[i];
			new_y = cur_y + dy[i];
			if (new_x == end_x && new_y == end_y)
			{
				answer = dist + 1;
				return;
			}

			// 새로운 좌표 설정
			if (isWall(new_x, new_y) || visit[new_x][new_y][block]) continue;
			// index를 넘어가거나 이미 방문한 노드라면 ??? continue
			if (map[new_x][new_y] == 1 && block) continue;
			// 벽인데 이미 한번 부순 경우 ?? continue
			if (map[new_x][new_y] == 1 && !block)
				// 벽인데 아직 부수지 않는 경우 ??? 부수기
			{
				visit[new_x][new_y][block + 1] = true;
				now.cur_x = new_x;
				now.cur_y = new_y;
				now.dist = dist + 1;
				now.block = true;
				q.push(now);
			}
			else
				// 벽이 아닌 경우 !!!
			{
				visit[new_x][new_y][block] = true;
				now.cur_x = new_x;
				now.cur_y = new_y;
				now.dist = dist + 1;
				now.block = block;
				q.push(now);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");
	
	cin >> N >> M;
	cin >> start_x >> start_y >> end_x >> end_y;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}
	// 입력 완료 !!

	bfs();

	if (answer == 0x7FFFFFFF)
	{
		cout << -1 << '\n';
		return 0;
	}
	cout << answer << '\n';
}

// 제일 처음 생각한 방법 : 이중포문으로 벽을 만날때마다 0으로 지우고 bfs 돌려주기 O(N^2M^2)로 시간초과
// 구글링도중 bfs를 한번만 써서 풀 수 있는 방법이 있었다. 코드 보며 참고했음.
