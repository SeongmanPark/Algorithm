#include <iostream>
//#include <fstream>
#include <queue>
#include <vector>
#define ABS(A,B) (A>B ? A-B:B-A)
#define MAX(A,B) (A>B ? A:B)
using namespace std;
int N, M, D;
int map[17][16];
int temp_map[16][16];
bool visit[16];
int answer, enemy_count;
// 행이 1개 더 많음 -> 성을 위해서

struct enemy
{
	int cur_x, cur_y, dist;
};

struct cmp
{
	bool operator()(const struct enemy &a, const struct enemy &b)
	{
		if (a.dist == b.dist)
		{
			return a.cur_y > b.cur_y;
		}
		else 
			return a.dist > b.dist;
	}
};

vector<pair<int, int>> v; // 궁수의 좌표를 저장할 벡터

void simulation()
{
	priority_queue<struct enemy, vector<struct enemy>, cmp> pq1; // 나중에 조건도 추가하기
	priority_queue<struct enemy, vector<struct enemy>, cmp> pq2; // 나중에 조건도 추가하기
	priority_queue<struct enemy, vector<struct enemy>, cmp> pq3; // 나중에 조건도 추가하기
	struct enemy now;
	int temp_answer = 0;
	int temp_enemy_count = enemy_count;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) temp_map[i][j] = map[i][j];
	// 맵 복사하기 !!
	while(temp_enemy_count > 0)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (temp_map[i][j] == 1) // 적이 있는 좌표이면 ??
				{
					// 적의 좌표를 구한 후
					now.dist = 0;
					now.dist = ABS(v[0].first, i) + ABS(v[0].second, j);
					if (now.dist <= D)
					{
						now.cur_x = i;
						now.cur_y = j;
						pq1.push(now);
					}
					now.dist = 0;
					now.dist = ABS(v[1].first, i) + ABS(v[1].second, j);
					if (now.dist <= D)
					{
						now.cur_x = i;
						now.cur_y = j;
						pq2.push(now);
					}
					now.dist = 0;
					now.dist = ABS(v[2].first, i) + ABS(v[2].second, j);
					if (now.dist <= D)
					{
						now.cur_x = i;
						now.cur_y = j;
						pq3.push(now);
					}
				}
			}
		}
		// 지울 수 있는 적 싹다 우선순위 큐에 저장해놈 !!
		if (!pq1.empty()) // 우선순위 큐가 비어있지 않고
		{
			if (temp_map[pq1.top().cur_x][pq1.top().cur_y] == 1) // 죽일 적이 있다면 ???? (아직 1이라면 ???)
			{
				temp_map[pq1.top().cur_x][pq1.top().cur_y] = 0;
				temp_answer++;
				temp_enemy_count--;
				// 죽였으니까 죽인 적 카운트 ++
			}
		}
		if (!pq2.empty()) // 우선순위 큐가 비어있지 않고
		{
			if (temp_map[pq2.top().cur_x][pq2.top().cur_y] == 1) // 죽일 적이 있다면 ???? (아직 1이라면 ???)
			{
				temp_map[pq2.top().cur_x][pq2.top().cur_y] = 0;
				temp_answer++;
				temp_enemy_count--;
				// 죽였으니까 죽인 적 카운트 ++
			}
		}
		if (!pq3.empty()) // 우선순위 큐가 비어있지 않고
		{
			if (temp_map[pq3.top().cur_x][pq3.top().cur_y] == 1) // 죽일 적이 있다면 ???? (아직 1이라면 ???)
			{
				temp_map[pq3.top().cur_x][pq3.top().cur_y] = 0;
				temp_answer++;
				temp_enemy_count--;
				// 죽였으니까 죽인 적 카운트 ++
			}
		}
		// 이제 적도 죽였으니까 우선순위 큐 비워야지
		while (!pq1.empty()) pq1.pop();
		while (!pq2.empty()) pq2.pop();
		while (!pq3.empty()) pq3.pop();
		// 우선순위 큐 다 비웠고 맵 한칸씩 아래로 이동
		for (int j = 1; j <= M; j++) 
		{
			if (temp_map[N][j] == 1)
			{
				temp_enemy_count--;
				temp_map[N][j] = 0;
			}
		}

		for (int j = 1; j <= M; j++)
		{
			for (int i = N-1; i >= 1; i--)
			{
				if (temp_map[i][j] == 1)
				{
					temp_map[i + 1][j] = 1;
					temp_map[i][j] = 0;
				}
			}
		}
		// 맵 한칸씩 아래로 이동 완료
	}
	answer = MAX(answer, temp_answer);
}

void makeCombination(int depth, int index)
{
	if (depth == 3)
	{
		// 궁수 세명 자리 배치가 완료되었으면 ??
		simulation();
	}
	
	for (int j = index; j <= M; j++)
	{
		if (!visit[j])
		{
			visit[j] = true;
			v.push_back(make_pair(N + 1, j));
			makeCombination(depth + 1, j + 1);
			// depth++ 후 index까지 같이 넘겨주기 -> 조합이기 때문
			v.pop_back();
			visit[j] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");
	cin >> N >> M >> D;
	struct enemy e;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1) enemy_count++;
		}
	}
	// N열까지 입력 받기
	// N+1은 궁수를 배치하기 위한 배열 !!!!
	makeCombination(0, 1);
	cout << answer << '\n';
}

// 조합 + 시뮬레이션 문제
// 적을 찾을때 for문을 돌리기 보다 처음부터 큐에 모든 적을 저장하면 시간이 덜 걸릴것 같다.
