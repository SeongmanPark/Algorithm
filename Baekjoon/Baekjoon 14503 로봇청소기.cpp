#include <iostream>
//#include <fstream>

using namespace std;
int N, M;
int map[51][51];
bool visit[51][51];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
// 북 동 남 서

struct robot
{
	int x, y, dir, clean_count, dir_miss;
};

struct robot r;

int calDir(int dir)
{
	switch (dir)
	{
	case 0: return 3;
	default: return dir - 1;
	}
}

void start()
{
	int new_x, new_y, new_dir;

	while (1)
	{
		if (r.dir_miss == 4)
		{
			new_x = r.x - dx[r.dir];
			new_y = r.y - dy[r.dir];
			// 방향 유지한 채로 한칸 후진한 좌표 구하기
			if (map[new_x][new_y] == 1)
				return;

			r.x = new_x;
			r.y = new_y;
			r.dir_miss = 0;
			// 한칸 뒤로 후진 후 2번으로 돌아가기
		}
		
		// 왼쪽 방향 구하기
		r.dir = calDir(r.dir);
		new_x = r.x + dx[r.dir];
		new_y = r.y + dy[r.dir];

		// 왼쪽 방향 좌표 구하기

		if (visit[new_x][new_y] || map[new_x][new_y] == 1) // 왼쪽 방향에 청소할 공간이 없음 (이미 한 곳이거나 벽이거나) pass
		{
			r.dir_miss++;
			continue;
		}

		visit[new_x][new_y] = true;
		r.clean_count++;
		r.x = new_x;
		r.y = new_y;
		// 왼쪽 방향으로 한칸 전진
		r.dir_miss = 0;
		// 한칸 전진해서 청소하기
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");

	cin >> N >> M >> r.x >> r.y >> r.dir;
	r.x++;
	r.y++;
	r.clean_count = 0;
	// 입력값이 0,0 기준이므로 좌표 ++해주기..

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];

	r.clean_count++;
	visit[r.x][r.y] = true;
	// 현재 위치 청소하기
	start();
	cout << r.clean_count << '\n';
}

// 말그대로 구현하기만 하면 되는 시뮬레이션 문제 + 실수하지 말기
