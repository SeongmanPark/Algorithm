#include <iostream>
//#include <fstream>
#include <queue>
using namespace std;
// 자신보다 큰 물고기는 지나갈 수 없음.
// 자신보다 작은 물고기만 먹을 수 있음.
// 크기가 같은 물고기는 먹을 수 없지만 지나갈수는 있음.
// 자신의 크기와 같은 수의 물고기를 먹으면 사이즈 1 증가.

int N;
int map[21][21];
bool visit[21][21];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool finsh = false;
struct shark_info
{
	int cur_x, cur_y, level, eat, move;
};

struct fish_info
{
	int cur_x, cur_y, shark_distance;
};

struct shark_info shark;
struct fish_info fish;

struct distcmp // 우선순위 1. 상어와의 거리 2. 거리가 같으면 가장 위에있는 물고기 3. 가장 왼쪽에 있는 물고기
{
	bool operator()(const struct fish_info a, const struct fish_info b)
	{
		if (a.shark_distance == b.shark_distance) // 상어와의 거리가 같으면 ? 
		{
			if (a.cur_x == b.cur_x) // 위에 있는 물고기가 여러마리라면 ?
			{
				return a.cur_y > b.cur_y;
			}
			else
				return a.cur_x > b.cur_x;
		}
		else
			return a.shark_distance > b.shark_distance;
	}
	// 레벨이 낮은 애부터 먼저 출력 !!!!
};

priority_queue<struct fish_info, vector<fish_info>, distcmp> distpq;

bool isWall(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > N) return true;
	else return false;
}

void pushFish()
{
	memset(visit, 0, sizeof(visit));
	struct fish_info fish;
	queue<pair<pair<int, int>, int>> q;
	// map을 돌면서 먹을수 있는 물고기가 있으면 distpq에 삽입.
	int new_x, new_y, cur_x, cur_y, cur_dist;
	q.push(make_pair(make_pair(shark.cur_x, shark.cur_y), 0));
	// 상어의 위치, 거리0을 큐에 삽입.
	visit[shark.cur_x][shark.cur_y] = true;
	// 자기 자신 위치 true,,,,, 젤 중요함..
	while (!q.empty())
	{
		cur_x = q.front().first.first;
		cur_y = q.front().first.second;
		cur_dist = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			new_x = cur_x + dx[i];
			new_y = cur_y + dy[i];
			if (isWall(new_x, new_y) || visit[new_x][new_y]) continue;
			// map의 범위를 넘어가거나 이미 방문한 노드이면 continue
			if (map[new_x][new_y] > shark.level) continue;
			// 탐색도중 자기보다 큰 물고기가 있는 경우 지나갈수 없으므로 continue
			if (map[new_x][new_y] == shark.level || map[new_x][new_y] == 0)
			{
				visit[new_x][new_y] = true;
				q.push(make_pair(make_pair(new_x, new_y), cur_dist + 1));
			}
			// 탐색도중 자기와 크기가 같은 물고기가 있는 경우 -> 지나갈 수는 있음.
			else if (map[new_x][new_y] < shark.level)
			{
				visit[new_x][new_y] = true;
				q.push(make_pair(make_pair(new_x, new_y), cur_dist + 1));
				// 큐에 넣고 ??
				fish.cur_x = new_x;
				fish.cur_y = new_y;
				fish.shark_distance = cur_dist + 1;
				distpq.push(fish);
			}
		}
		
	}
}

void eatFish()
{
	if (distpq.empty()) // 만약 거리순 우선순위 큐에 먹을 수 있는 물고기가 없다면 ?
	{
		finsh = true;
		return;
	}
	else // distpq 젤 앞에 있는 물고기를 먹고, 큐 비우기
	{
		map[shark.cur_x][shark.cur_y] = 0;
		shark.cur_x = distpq.top().cur_x;
		shark.cur_y = distpq.top().cur_y;
		map[shark.cur_x][shark.cur_y] = 9;
		shark.eat++;
		shark.move += distpq.top().shark_distance;
		if (shark.level == shark.eat)
		{
			shark.level++;
			shark.eat = 0;
		}

		while (!distpq.empty())
			distpq.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				shark.cur_x = i;
				shark.cur_y = j;
				shark.eat = 0;
				shark.level = 2;
				shark.move = 0;
			}
		}
	}
	// 입력 완료 !!
	while (1)
	{
		pushFish();
		eatFish();
		/*
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << "SHARK SIZE = " << shark.level << endl;
		*/
		if (finsh) break;
	}

	cout << shark.move << '\n';
	return 0;
}

// 각 물고기의 거리를 구할때, 상어 자기 자신의 위치를 visit 안해줘서 무한루프에 빠져버렸다.
// 우선순위 큐를 이용하면 참 간단한 문제... 레퍼런스를 보고 아이디어를 생각했다.
// 우선순위 큐의 비교함수 문법 잘 보기..
