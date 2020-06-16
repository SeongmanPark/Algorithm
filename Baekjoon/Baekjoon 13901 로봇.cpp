#include <iostream>
//#include <fstream>

using namespace std;
int R, C, K;
int start_x, start_y;
int block_x, block_y;
int map[1001][1001];
bool visit[1001][1001];
int dir_array[4];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct robot
{
	int cur_x, cur_y;
	int miss_count;
};

bool isWall(int x, int y)
{
	if (x < 0 || y < 0 || x > R - 1 || y > C - 1) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");

	struct robot r;

	cin >> R >> C >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> block_x >> block_y;
		map[block_x][block_y] = -1;
		// 장애물 -1로 표시 !!!!!
	}
	cin >> r.cur_x >> r.cur_y;
	r.miss_count = 0;
	for (int i = 0; i < 4; i++)
		cin >> dir_array[i];

	int DIR = 0;
	visit[r.cur_x][r.cur_y] = true;
	int cur_x, cur_y, new_x, new_y;

	while (1)
	{
		if (r.miss_count == 4)
			break;

		cur_x = r.cur_x;
		cur_y = r.cur_y;
		new_x = cur_x + dx[dir_array[DIR] - 1];
		new_y = cur_y + dy[dir_array[DIR] - 1];
		// 새로운 좌표 설정

		if (isWall(new_x, new_y) || map[new_x][new_y] == -1 || visit[new_x][new_y])
			// 벽 이거나 장애물이 있거나 이미 방문한 좌표이면 ??? DIR ++후 miscount++
		{
			DIR = (DIR + 1) % 4;
			r.miss_count++;
		}
		else
		{
			visit[new_x][new_y] = true;
			r.cur_x = new_x;
			r.cur_y = new_y;
			r.miss_count = 0;
		}
	}
	cout << r.cur_x << " " << r.cur_y << '\n';
	return 0;
}

// 전형적인 시뮬레이션 문제 ( 쉬움 )
