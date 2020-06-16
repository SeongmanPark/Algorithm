#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int maze[16][16];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
bool visit[16][16] = { false };
vector <string> v;
bool flag = false;

void dfs(int x, int y)
{

	for (int i = 0; i < 4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		// 다음에 이동할 방향 설정

		if (!visit[new_x][new_y] && maze[new_x][new_y] != 1)
		{
			visit[new_x][new_y] = true;
			if (maze[new_x][new_y] == 3)
			{
				flag = true;
			}
			else dfs(new_x, new_y);
		}
	}

}

int main() {
	ifstream input("input.txt");
	int n;
	int testCase = 10;
	string s;
	while(testCase-- > 0)
	{
		input >> n;
		for (int i = 0; i < 16; i++)
		{
			input >> s;
			v.push_back(s);

		}
		// string 입력 완료..
		for (int i = 0; i < 16; i++) 
		{
			for (int j = 0; j < 16; j++) 
			{
				int data = v[i][j] - '0';
				maze[i][j] = data;
			}
		}
		// data 입력 완료..

		cout << "#" << n << " ";
		visit[1][1] = true;
		dfs(1, 1);
		if (flag)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
		n++;

		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				maze[i][j] = 0;
				visit[i][j] = false;
			}
		}
		v.clear();
		flag = false;

	}

}
// 전형적인 탐색문제, dfs를 이용하여 해결하였다. 재귀함수 탈출조건으로 리턴값 받아서 처리하는 법 배우기, 나는 flag로 처리함.
