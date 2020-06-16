#include <iostream>
#include <cstring>
#include <fstream>
#include <queue>
#include <algorithm>

using namespace std;

int testCase, N;
int cost[101][101];
int map[101][101];
int TC = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void init()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cost[i][j] = 0xFFFFFFF;
			map[i][j] = 0;
		}
	}
	TC++;
}

bool isWall(int x,int y)
{
	if (x < 1 || y < 1 || x > N || y > N)
		return true;
	else return false;
}

void bfs()
{
	queue <pair<int, int>> q;
	q.push(make_pair(1, 1));
	cost[1][1] = map[1][1];
	// start 설정
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if (isWall(new_x, new_y) || cost[new_x][new_y] <= cost[x][y] + map[new_x][new_y]) continue;
			else
			{
				cost[new_x][new_y] = cost[x][y] + map[new_x][new_y];
				q.push(make_pair(new_x, new_y));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream input("input.txt");

	input >> testCase;

	while (testCase-- > 0)
	{
		input >> N;
		char a;
		init();
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				input >> a;
				map[i][j] = a - '0';
			}
		}

		bfs();
		cout << "#" << TC << " " << cost[N][N] << '\n';
	}
}

// bfs 문제
// cost배열을 무한값으로 초기화 한 후, bfs를 실행하면서 cost[new_x][new_y] > cost[x][y] + map[new_x][new_y]
// 를 만족할 때만 방문해서 찾으면 된다.

#include <iostream>
#include <cstring>
//#include <fstream>
#define MIN(A,B) (A<B ? A:B)
 
using namespace std;
 
int testCase, N;
int temp_map[101][101];
int map[101][101];
int answer;
int TC = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
// 상 하 좌 우
 
void init()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            temp_map[i][j] = 0xFFFF;
            map[i][j] = 0;
        }
    }
    TC++;
}
 
bool isWall(int x, int y)
{
    if (x < 1 || y < 1 || x > N || y > N)
        return true;
    else return false;
}
 
void makeGreedy(int x, int y)
{
    int sum = map[1][1];
 
    while (x < N && y < N)
    {
        if (map[x + 1][y] > map[x][y + 1])   y++;
        else x++;
 
        sum += map[x][y];
    }
 
    while (x < N)
    {
        x++;
        sum += map[x][y];
    }
 
    while (y < N)
    {
        y++;
        sum += map[x][y];
    }
 
    answer = sum;
    return;
}
 
void dfs(int x, int y, int distance)
{
    if (distance >= answer)
        return;
     
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (isWall(new_x, new_y)) continue;
        // 벽이거나 방문했거나 1,1으로부터 거리가 더 크거나 같으면 해볼필요도 없음.
        // 모든 정점에 prunning 
        if (temp_map[new_x][new_y] > temp_map[x][y] + map[new_x][new_y])
        {
            temp_map[new_x][new_y] = temp_map[x][y] + map[new_x][new_y];
            dfs(new_x, new_y, distance + map[new_x][new_y]);
        }
 
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream input("input.txt");
 
    cin >> testCase;
 
    while (testCase-- > 0)
    {
        cin >> N;
        char a;
        init();
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cin >> a;
                map[i][j] = a - '0';
            }
        }
        temp_map[1][1] = map[1][1];
        makeGreedy(1, 1);
        dfs(1,1, map[1][1]);
        cout << "#" << TC << " " << temp_map[N][N] << '\n';
    }
}

// DFS 방법으로도 풀었다. 1,1 에서 최단거리를 갱신해나가기 위한 temp_map 2차원 배열을 활용하였다. -> prunning
// 그래도 시간초과가 나서 그리디를 써서 가지치기를 추가해서 통과하였다.
