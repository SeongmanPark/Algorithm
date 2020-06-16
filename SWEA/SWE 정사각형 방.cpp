#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int map[1001][1001];
bool visit[1001][1001] = { false };
int length, answer;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int minRoom = 1000000;

void init()
{
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));
	length = answer = 0;
	minRoom = 1000000;
}

bool isWall(int N, int x, int y)
{
	if (x < 1 || x > N || y < 1 || y > N)
	{
		return true;
	}
	else return false;
}

void dfs(int startRoom, int N, int x, int y, int length)
{
	if (answer == length)
	{
		answer = length;
		if (minRoom > startRoom)
		{
			minRoom = startRoom;
		}
	}
	if (answer < length)
	{
		answer = length;
		minRoom = startRoom;
	}
	for (int i = 0; i < 4; i++)
	{
		int new_X = x + dx[i];
		int new_Y = y + dy[i];
		if (isWall(N, new_X, new_Y) || map[new_X][new_Y] != map[x][y] + 1 || visit[new_X][new_Y])	// 이동 못 하면 ?
		{
			continue;
		}
		else
		{
			visit[new_X][new_Y] = true;
			length++;
			dfs(startRoom ,N, new_X, new_Y, length);
			length--;
			visit[new_X][new_Y] = false;
		}
	}
}

int main()
{
	ifstream input("input.txt");
	int testCase, N, data;
	input >> testCase;
	int a = 1;
	while (testCase-- > 0)
	{
		input >> N;
		for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) input >> map[i][j];
		// 배열 입력 완료
		
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (!visit[i][j])
				{
					length = 1;
					int startRoom = map[i][j];
					visit[i][j] = true;
					dfs(startRoom ,N, i, j, length);
					visit[i][j] = false;
				}
			}
		}
		cout << "#" << a << " "<<minRoom<<" "<<answer << '\n';
		a++;
		init();
	}
}
// if else 문 잘 쓰기 !!
