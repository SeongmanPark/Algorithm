#include <iostream>
//#include <fstream>
#include <queue>
#include <cstring>
#define MIN(A,B) (A<B ? A:B)
// 중복순열 + 시뮬레이션
using namespace std;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int N, W, H, testCase;
int a = 1;
int map[16][13];
bool visit[16][13];
int answer = 987654321;

void init()
{
	memset(map, 0, sizeof(map));
	answer = 987654321;
	a++;
}

bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > H || y > W) return true;
	else return false;
}

int countBrick()
{
	int cnt = 0;
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (map[i][j] != 0)
				cnt++;
		}
	}
	return cnt;

}
void drop(int cnt) // cnt는 떨어뜨린 횟수를 나타낸다.
{
	if (countBrick() == 0) answer = 0;
	// 벽돌이 0개가 되었을 때 예외처리 해주기 !!
	if (cnt == N)
	{
		answer = MIN(answer, countBrick());
		return;
	}

	for (int i = 1; i <= W; i++) // 열 고르는 부분....
	{
		int temp[16][13];
		for (int i = 1; i <= H; i++) for (int j = 1; j <= W; j++) temp[i][j] = map[i][j];
		// map 복사하기
		int j = 1;
		int cur_x, cur_y, new_x, new_y, power;
		while (j <= H)
		{
			if (map[j][i] != 0) break;
			j++;
		}
		// 공이 떨어졌을때 부딪히는 벽돌의 위치를 찾기 !!!
		if (j > H) continue;
		// 해당 라인에 벽돌이 없는 경우 ??

		memset(visit, 0, sizeof(visit));
		queue<pair<pair<int, int>, int>>q;
		q.push(make_pair(make_pair(j, i), map[j][i]));
		map[j][i] = 0;
		visit[j][i] = true;
		// 이제 시작 !!!
		while (!q.empty())
		{
			cur_x = q.front().first.first;
			cur_y = q.front().first.second;
			power = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++)
			{
				for (int j = 1; j <= power - 1; j++)
				{
					new_x = cur_x + j * dx[k];
					new_y = cur_y + j * dy[k];
					if (visit[new_x][new_y]) continue;
					if (isWall(new_x, new_y)) continue;
					if (map[new_x][new_y] == 0) continue;
					visit[new_x][new_y] = true;
					if (map[new_x][new_y] > 1)
					{
						q.push(make_pair(make_pair(new_x, new_y), map[new_x][new_y]));
						map[new_x][new_y] = 0;
					}
					else
					{
						map[new_x][new_y] = 0;
					}
				}
			}
		}
		// 공이 떨어져서 벽돌 다 깨짐.

		// 이제 줄 맞춰주기 !!!
		for (int j = 1; j <= W; j++)
		{
			for (int l = H; l >= 1; l--)
			{
				for (int k = H; k >= 2; k--)
				{
					if (map[k][j] == 0 && map[k - 1][j] != 0)
					{
						map[k][j] = map[k - 1][j];
						map[k - 1][j] = 0;
					}
				}
			}
		}
		drop(cnt + 1);
		// 열 하나 골라서 작업 완료 했으니 cnt++ 해주기 !!
		// 1 2 3 후 1 2 4 로 진행될 때 1 2 까지 진행되었던 값 다시 똑바로 해 놓기
		for (int i = 1; i <= H; i++) for (int j = 1; j <= W; j++) map[i][j] = temp[i][j];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("input.txt");
	cin >> testCase;
	while (testCase-- > 0)
	{
		cin >> N >> W >> H;
		// 벽돌깨는 횟수, 너비, 높이
		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				cin >> map[i][j];
			}
		}
		// 벽돌 입력 완료 !!!!
		// 원래 map 복사하기..
		drop(0);
		cout << "#" << a << " " << answer << '\n';
		init();
	}
}

// 중복순열 + 시뮬레이션
// 전형적인 삼성스러운 스타일 문제이다.
// 벽돌이 깨지기 전 배열을 지역변수로 선언하여 값을 복사하는데 시간을 많이 썼다.
