#include <iostream>
//#include <fstream>

using namespace std;
int N, M, start_x, start_y, K, dir;
int map[21][21];

int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };
// 1 동 2 서 3 북 4 남

struct dice_info
{
	int cur_x, cur_y;
	int arr[6];
	// index 0은 위, 1은 아래, 2는 앞, 3은 뒤, 4는 왼쪽, 5는 오른쪽
};

struct dice_info dice;

bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > M)
		return true;
	else return false;
}

void move(int dir)
{
	int d0, d1, d2, d3, d4, d5;
	d0 = dice.arr[0]; // 위
	d1 = dice.arr[1]; // 아래
	d2 = dice.arr[2]; // 앞
	d3 = dice.arr[3]; // 뒤
	d4 = dice.arr[4]; // 왼
	d5 = dice.arr[5]; // 오른
	switch (dir)
	{
	case 1: // 동쪽일때
		dice.arr[0] = d4;
		dice.arr[1] = d5;
		dice.arr[4] = d1;
		dice.arr[5] = d0;
		break;
	case 2: // 서쪽일때
		dice.arr[0] = d5;
		dice.arr[1] = d4;
		dice.arr[4] = d0;
		dice.arr[5] = d1;
		break;
	case 3: // 북쪽일때
		dice.arr[0] = d2;
		dice.arr[1] = d3;
		dice.arr[2] = d1;
		dice.arr[3] = d0;
		break;
	case 4:
		dice.arr[0] = d3;
		dice.arr[1] = d2;
		dice.arr[2] = d0;
		dice.arr[3] = d1;
		break;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");

	cin >> N >> M >> start_x >> start_y >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}
	start_x++;
	start_y++;
	dice.cur_x = start_x;
	dice.cur_y = start_y;
	for (int i = 0; i < 6; i++)
		dice.arr[i] = 0;
	// 초기화 완료

	while (K-->0)
	{
		cin >> dir;
		int new_x = dice.cur_x + dx[dir];
		int new_y = dice.cur_y + dy[dir];
		// 새로운 주사위 좌표 구하기
		if (isWall(new_x, new_y)) continue;
		// 범위를 벗어나면 ?? 해당 명령 무시하기
		move(dir);
		// 주사위 굴리기
		if (map[new_x][new_y] == 0) // 이동한 칸에 쓰인 수가 0이면 ?? 주사위 바닥면 -> 칸
		{
			map[new_x][new_y] = dice.arr[1];
		}
		else // 이동한 칸에 쓰인 수가 0이 아니면 ?? 칸 -> 주사위 바닥, 칸 = 0
		{
			dice.arr[1] = map[new_x][new_y];
			map[new_x][new_y] = 0;
		}
		// 칸 -> 주사위 or 주사위 -> 칸 수 복사 완료
		cout << dice.arr[0] << '\n';
		// 주사위 윗부분 값 출력하기
		dice.cur_x = new_x;
		dice.cur_y = new_y;
	}
	return 0;
}

// 시뮬레이션
