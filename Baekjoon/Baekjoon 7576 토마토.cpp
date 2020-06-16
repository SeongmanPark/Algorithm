#include <iostream>
//#include <fstream>
#include <queue>
using namespace std;
int N, M, ans, sum;
int map[1001][1001];
bool visit[1001][1001] = { false };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

queue<pair<int, int>> q;
#define MAX(A,B) (A>B ? A:B)
bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > M) return true;
	else return false;
}

int main()
{
	//ifstream cin("input.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	int a;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
			{
				sum++;
				// 토마토의 개수
			}
			else if (map[i][j] == 1)
			{
				q.push(make_pair(i, j));
				visit[i][j] = true;
				// 탐색해야 할 좌표 저장.
			}
		}
	}

	if (sum == 0)	// 제일 처음 익지 않은 토마토가 0개인 경우 !!
	{
		cout << 0 << '\n';
		return 0;
	}
	
		register int new_x, new_y, x, y;
		while (!q.empty())
		{
			x = q.front().first;
			y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				new_x = x + dx[i];
				new_y = y + dy[i];
				if (isWall(new_x, new_y) || visit[new_x][new_y]
					|| map[new_x][new_y] == -1)
					continue;
				// 벽이거나 방문했거나 토마토가 없다면 ?
				else if (map[new_x][new_y] == 0)
				// 익지 않는 토마토가 있다면 ?
				{
					visit[new_x][new_y] = true;
					// 토마토가 익을 차례니까 visit = true로 하여 q에 중복으로 삽입하는것을 방지
					map[new_x][new_y] = map[x][y] + 1;
					// map[new_x][new_y] 에 있는 토마토가 익는데 걸린 시간은 map[x][y] + 1 초 입니다.
					ans = MAX(ans, map[new_x][new_y]);
					// map배열 내 최대 값 저장하기 -> 이게 바로 다 익은 시간이니까
					q.push(make_pair(new_x, new_y));
					sum--;
				}
			}
		}

		if (sum == 0)	// 토마토가 다 익은 경우 시간 출력
		{
			cout << ans - 1 << '\n';
		}
		else cout << -1 << '\n';	// 토마토가 절때로 다 익을 수 없는 경우
}

// BFS를 이용하여 풀었다. 배열을 돌면서 넣을 좌표를 찾는게 아니라, bfs돌면서 넣을 좌표를 찾는게 핵심
// 배열을 돌면서 좌표를 넣으려다가 시간초과가 계속 났다.
