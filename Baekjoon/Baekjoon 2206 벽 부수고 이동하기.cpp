#include <iostream>
//#include <fstream>
#include <queue>
using namespace std;

int N, M;
char map[1001][1001];
bool visit[1001][1001][2];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int answer = 987654321;

typedef struct pos
{
	int cur_x, cur_y, dist, break_count;
}p;

bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > M) return true;
	return false;
}

void bfs()
{
	p now;
	queue<p> q;
	int new_x, new_y, dist, break_count, cur_x, cur_y;
	now.cur_x = 1;
	now.cur_y = 1;
	now.dist = 1;
	now.break_count = 0;
	q.push(now);
	visit[1][1][0] = true;
	while (!q.empty())
	{
		cur_x = q.front().cur_x;
		cur_y = q.front().cur_y;
		dist = q.front().dist;
		break_count = q.front().break_count;
		q.pop();
		if (cur_x == N && cur_y == M)
		{
			answer = dist;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			new_x = cur_x + dx[i];
			new_y = cur_y + dy[i];
			

			if (isWall(new_x, new_y) || visit[new_x][new_y][break_count]) continue;
			if (map[new_x][new_y] == '1')
				// 벽인 경우 ????
			{
				if (break_count + 1 < 2)
					// 벽을 더 깰 수 있는 경우
				{
					visit[new_x][new_y][break_count + 1] = true;
					now.cur_x = new_x;
					now.cur_y = new_y;
					now.dist = dist + 1;
					now.break_count = break_count + 1;
					q.push(now);
				}
				else
					// 벽을 더 깰 수 없는 경우
				{
					continue;

				}
			}
			if (map[new_x][new_y] == '0')
			{
				visit[new_x][new_y][break_count] = true;
				now.cur_x = new_x;
				now.cur_y = new_y;
				now.dist = dist + 1;
				now.break_count = break_count;
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
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}
	bfs();
	if (answer == 987654321)
	{
		cout << -1 << '\n';
		return 0;
	}
	cout << answer << '\n';
	return 0;
}

// 비슷한 유형 푼 김에 이 문제도 풀었다.
// 벽 제거 (조합) + bfs가 아닌, bfs 한번에 푸는 스킬 익히기
