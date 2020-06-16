#include <iostream>
//#include <fstream>


using namespace std;
int height[10];
bool visit[10] = { false };
bool finsh = false;

void dfs(int depth, int total, int index)
{
	if (depth == 7)
	{
		if (total == 100)
		{
			for (int i = 1; i <= 9; i++)
			{
				if (visit[i])
				{
					cout << height[i] << '\n';
				}
			}
			finsh = true;
			return;
		}
	}

	if (finsh)
		return;

	if (total > 100)
		return;

	for (int i = index; i <= 9; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			dfs(depth + 1, total + height[i], i + 1);
			visit[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");

	for (int i = 1; i <= 9; i++)
	{
		cin >> height[i];
	}

	int temp;
	for (int i = 8; i > 0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (height[j] > height[j + 1])
			{
				temp = height[j];
				height[j] = height[j + 1];
				height[j + 1] = temp;
			}
		}
	}
	// BUBBLE SORT

	dfs(0, 0, 1);
}

// 브루트 포스 문제
// 답을 찾고 다 리턴해야 통과하는 문제
