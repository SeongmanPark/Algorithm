#include <iostream>
//#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int map[26][26];
bool visit[26][26] = { false };
vector<int> answer;
int house_count, house;

bool isWall(int x, int y, int N)
{
	if (x <1 || x > N || y < 1 || y > N)
	{
		return true;
	}
	else return false;
}

void dfs(int N, int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];

		if (!isWall(new_x, new_y, N) && !visit[new_x][new_y] && map[new_x][new_y] == 1)
		{
			house++;
			visit[new_x][new_y] = true;
			dfs(N, new_x, new_y);
		}
	}
}

int main()
{
	//ifstream input("input.txt");
	int N;
	char data;
	input >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			input >> data;
			map[i][j] = data - '0';
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!isWall(i, j, N) && !visit[i][j] && map[i][j] == 1)
			{
				visit[i][j] = true;
				house_count++;
				house = 1;
				dfs(N, i, j);
				answer.push_back(house);
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << house_count << '\n';
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << '\n';
	}
}

// dfs 이용해서 간단하게 품.
