#include <iostream>
//#include <fstream>
#include <queue>
#define MAX(A,B) (A>B ? A:B)

using namespace std;
int map[21][21];
bool visit[21][21];
int N, M, testCase, K, answer, temp_answer;
int a = 1;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void init()
{
	a++;
	answer = 0;
	temp_answer = 0;
}

bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > N) return true;
	else return false;
}

void bfs(int x, int y)
{
	int home = 0;
	int K = 1;
	int cur_x, cur_y, new_x, new_y, cur_dist;
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = true;
	if (map[x][y] == 1) home++;
	// 시작점 큐에 푸쉬, 거리는 0

	while (!q.empty())
	{
		if (K > N + 1) break;
		// service가 배열의 크기 + 1이 넘으면 ?? 더이상 해볼 필요 없음 !!
		if ((K * K + (K - 1)*(K - 1)) <= home * M)
		{
			answer = MAX(answer, home);
		}
		// 비용계산, 정답 초기화 부분 !!
		int s = q.size();
		// 현재 큐의 사이즈를 저장
		// 현재 큐의 사이즈만큼 for문 돈다 -> 기준점으로부터 똑같이 떨어진 노드의 개수만큼 돈다. !!!! 
		// 매우 중요함 .. !!!
		for (int Qs = 0; Qs < s; Qs++)
		{
			cur_x = q.front().first;
			cur_y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				new_x = cur_x + dx[i];
				new_y = cur_y + dy[i];
				if (visit[new_x][new_y] || isWall(new_x, new_y)) continue;
				visit[new_x][new_y] = true;
				if (map[new_x][new_y] == 1)
				{
					home++;
				}
				q.push(make_pair(new_x, new_y));
			}
		}
		
		K++;
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
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> map[i][j];
			}
		}
		// 입력 완료
		for (int i = 1;i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				bfs(i, j);
				// 모든 정점에 대해서 완전탐색 해야함
			}
		}
		cout << "#" << a << " " << answer << '\n';
		init();
	}
}

// 완전탐색 + 시뮬레이션 문제 !!!!
