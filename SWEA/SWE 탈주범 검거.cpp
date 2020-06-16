#include <iostream>
//#include <fstream>
#include <queue>
#include <cstring>
using namespace std;
int N, M, R, C, L, testCase;
int map[51][51];
bool visit[51][51];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int answer = 1;
int a = 1;
// 상 하 좌 우
struct pipe_info
{
	int cur_x, cur_y, dist, type;
};

struct pipe_info pipe;
queue<struct pipe_info> q;
// pipe의 정보를 담는 구조체

void init()
{
	a++;
	memset(visit, 0, sizeof(visit));
	memset(map, 0, sizeof(map));
	answer = 1;
	while (!q.empty())
		q.pop();
}

bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > M) return true;
	else return false;
}

bool isConnect(int type_src, int type_des, int dir)
{
	// input : 이전 파이프 모양, 이후 파이프 모양, 방향
	switch (dir)
	{
	case 0: // 위쪽으로 올라가는 방향
		switch (type_src)
		{
		case 1: case 2: case 4: case 7:
			if (type_des == 3 || type_des == 4 || type_des == 7)
				return false;
			else return true;
		case 3: case 5: case 6:
			return false;
		}
	case 1: // 밑으로 내려가는 방향
		switch (type_src)
		{
		case 1: case 2: case 5: case 6:
			if (type_des == 3 || type_des == 5 || type_des == 6)
				return false;
			else return true;
		case 3: case 4: case 7:
			return false;
		}
	case 2: // 동->서
		switch (type_src) // 왼쪽 방향 파이프가 src
		{
		case 1: case 3: case 6: case 7:
			if (type_des == 2 || type_des == 6 || type_des == 7)
				return false;
			else return true;
		case 2: case 4: case 5:
			return false;
		}
	case 3: // 서->동
		switch (type_src) // src는 오른쪽 방향 열려 있어야 함
		{
		case 1: case 3: case 4: case 5:
			if (type_des == 2 || type_des == 4 || type_des == 5)
				return false;
			else return true;
		case 2: case 6: case 7:
			return false;
		}
	}
}

void bfs()
{
	int cur_x, cur_y, new_x, new_y, cur_type, cur_dist;
	struct pipe_info p;
	while (!q.empty())
	{
		cur_x = q.front().cur_x;
		cur_y = q.front().cur_y;
		cur_type = q.front().type;
		cur_dist = q.front().dist;
		q.pop();
		if (cur_dist == L-1) continue;
		// 큐 앞에 있는 정보 저장하고 pop
		for (int i = 0; i < 4; i++)
		{
			new_x = cur_x + dx[i];
			new_y = cur_y + dy[i];
			// 기준점을 기준으로 상 하 좌 우 탐색 !!!
			if (isWall(new_x, new_y) || visit[new_x][new_y]) continue;
			if (map[new_x][new_y] == 0) continue;
			// 파이프가 없는 칸이면 continue
			if (!isConnect(cur_type, map[new_x][new_y], i)) continue;
			// 여기까지 통과하면 연결되어있고, 방문하지 않은 파이프
			visit[new_x][new_y] = true;
			answer++;
			p.cur_x = new_x;
			p.cur_y = new_y;
			p.dist = cur_dist + 1;
			p.type = map[new_x][new_y];
			q.push(p);
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
		cin >> N >> M >> R >> C >> L;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cin >> map[i][j];
			}
		}
		R++;
		C++;
		// 나는 1,1을 기준으로 삼았기 때문
		pipe.cur_x = R;
		pipe.cur_y = C;
		pipe.dist = 0;
		pipe.type = map[R][C];
		q.push(pipe);
		// pipe정보 입력하기
		visit[R][C] = true;
		bfs();
		cout << "#" << a << " " << answer << '\n';
		init();
	}
}

// 간단한 bfs문제
// 삼성 문제는 한번에 2가지 이상 테케를 돌리므로
// 변수 초기화가 중요하다 (특히 큐)
