#include <iostream>
//#include <fstream>
using namespace std;
int N;
int map[101][101];
char mv[51];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
// 북 동 남 서 !!!!


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> mv[i];
	}

	int cur_x = 50;
	int cur_y = 50;
	int DIR = 2;
	// 남쪽을 보고 있음.

	map[cur_x][cur_y] = 1;

	for (int i = 1; i <= N; i++)
	{
		if (mv[i] == 'R')
		{
			DIR = (DIR + 1) % 4;
		}
		else if (mv[i] == 'L')
		{
			DIR -= 1;
			if (DIR < 0)
				DIR = 3;
		}
		// 방향 전환 케이스 완료

		else if (mv[i] == 'F')
		{
			cur_x = cur_x + dx[DIR];
			cur_y = cur_y + dy[DIR];
			map[cur_x][cur_y] = 1;
		}
	}

	// map 표시 완료

	// 이제 사각형 구하기

	int start_x = 100;
	int end_x = 0;
	int start_y = 100;
	int end_y = 0;

	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (map[i][j] == 1)
			{
				if (start_x > i) start_x = i;
				if (start_y > j) start_y = j;
				if (end_x < i) end_x = i;
				if (end_y < j) end_y = j;
			}
		}
	}

	for (int i = start_x; i <= end_x; i++)
	{
		for (int j = start_y; j <= end_y; j++)
		{
			if (map[i][j] == 1)
			{
				cout << ".";
			}
			else cout << "#";
		}
		cout << '\n';
	}

	return 0;
}

// 그냥 방법론적으로 생각해서 구현하면 된다.
// 완전탐색보다 약간 이런 유형의 문제는 처음 마주했을때 당황스럽다.
// 하라는 데로 구현하면 풀리긴 풀리는데 겁 먹지 말자.
