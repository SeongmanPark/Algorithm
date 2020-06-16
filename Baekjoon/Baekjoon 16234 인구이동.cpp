#include <iostream>
//#include <fstream>
#include <queue>
#include <cstring>
#define ABS(A,B) (A>B ? A-B:B-A)
using namespace std;

int map[51][51];
int N, L, R, cnt;
bool is_valid = false;
bool open[51][51] = { false };	// 인구이동 이미 한 국가 저장하는 배열
bool visit[51][51] = { false };	// 인구이동을 할 국가 저장하는 배열


int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > N) return true;
	else return false;
}

int bfs(int x, int y)
{
	queue<pair<int, int>> q;
	int new_x, new_y, old_x, old_y;
	q.push(make_pair(x,y));
	int people_count = map[x][y];
		
	while (!q.empty())
	{
		old_x = q.front().first;
		old_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			new_x = old_x + dx[i];
			new_y = old_y + dy[i];
			if (isWall(new_x, new_y)) continue;	// map의 범위를 벗어나면 안됨
			if (visit[new_x][new_y]) continue;	// 이미 연합된 국가이면 continue
			if (open[new_x][new_y]) continue;	// 이미 인구이동을 한 국가이면 continue
			if (ABS(map[new_x][new_y], map[old_x][old_y]) >= L && ABS(map[new_x][new_y], map[old_x][old_y]) <= R)
			{
				cnt++;	// 연합 국가 하나 증가
				people_count += map[new_x][new_y];	// 사람 총합 구하기
				is_valid = true;	// 인구이동이 일어났음을 표시
				visit[new_x][new_y] = true;
				q.push(make_pair(new_x, new_y));
			}
		}
	}

	return people_count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");

	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];

	int time = 0;
	while (1)
	{
		is_valid = false;	// 인구이동 발생 여부 저장 변수
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (!open[i][j])	// 인구이동이 발생하지 않는 나라가 있으면 그 나라 주변을 탐색해야 하기 때문에 bfs 시작 !!
				{
					memset(visit, 0, sizeof(visit));
					cnt = 1;	// 인구이동 발생 횟수 저장 변수
					int sum = 0;
					visit[i][j] = true;
					sum = bfs(i, j);	// 연합된 국가의 총 인원수 return
					sum /= cnt;	// 국가의 수로 나눈다. 나머지는 버림.
					if (cnt > 1)
					{
						for (int i = 1; i <= N; i++)
						{
							for (int j = 1; j <= N; j++)
							{
								if (visit[i][j])
								{
									open[i][j] = true; // 이번 턴에 인구이동 했으니 표시해야지 왜 ? map 의 데이터가 바뀌니까
									map[i][j] = sum;	// 이동한 인구 표시
								}
							}
						}
						//for (int i = 1; i <= N; i++)
						//{
						//	for (int j = 1; j <= N; j++)
						//	{
						//		cout << map[i][j] << '\t';
						//	}
						//	cout << endl;
						//}
						//cout << endl;
					}
				}
			}
		}
		memset(open, 0, sizeof(open));

		if (!is_valid)
		{
			cout << time << '\n';
			return 0;
		}
		time++;
		if (time >= 2000)
		{
			cout << time << '\n';
			return 0;
		}
	}
}

// BFS문제, 생각외로 쉬운 문제, 그렇다고 구현하기 간단하진 않았다.
// bool 배열 2개를 써야하는 문제이다.
