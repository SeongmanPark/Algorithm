#include <iostream>
//#include <fstream>
#include <vector>
#include <algorithm>
#define MAX(A,B) (A>B ? A:B)
using namespace std;

int M, N, K, start_x, start_y, end_x, end_y, temp_max;
int map[100][100];
bool visit[100][100];
vector<int> v;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool isWall(int x, int y)
{
	if (x < 0 || y < 0 || x > N-1 || y > M-1) return true;
	else return false;
}

void dfs(int x, int y)
{
	temp_max++;
	int new_x, new_y;
	for (int i = 0; i < 4; i++)
	{
		new_x = x + dx[i]; 
		new_y = y + dy[i];
		if (isWall(new_x, new_y)) continue;
		if (visit[new_x][new_y]) continue;
		if (map[new_x][new_y] == 1) continue;
		visit[new_x][new_y] = true;
		dfs(new_x, new_y);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");
	
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> start_x >> start_y >> end_x >> end_y;

		for (int j = start_x; j < end_x; j++)
		{
			for (int m = start_y; m < end_y; m++)
			{
				map[j][m] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visit[i][j] && map[i][j] == 0)
			{
				visit[i][j] = true;
				dfs(i, j);
				v.push_back(temp_max);
				temp_max = 0;
			}
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << '\n';
	return 0;
}

// SK C&C 탈락 이후, 간만의 코딩 테스트 풀이
// 주어진 이차원 배열 x, y 좌표가 반대로 되어 있어서 좀 헤맸음... 문제 자체는 어려움 없음.
// 감이 떨어져서 좀 시간이 걸렸던 문제..
