#include <iostream>
//#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

int address[101][101];
bool visit[101] = { false };
int t;
int timeCount[101];

void init()
{
	for (int i = 1; i <= 100; i++)
	{
		timeCount[i] = 0;
		visit[i] = false;
		for (int j = 1; j <= 100; j++)
		{
			address[i][j] = 0;
		}
	}
	t = 0;

}

void bfs(int startNode, int t)
{
	queue<int> Q;
	Q.push(startNode);
	visit[startNode] = true;
	while (!Q.empty())
	{
		int student = Q.front();
		Q.pop();
		for (int i = 1; i <= 100; i++)
		{
			if (address[student][i] == 1 && !visit[i])
			{
				Q.push(i);
				visit[i] = true;
				timeCount[i] = timeCount[student] + 1;
			}
		}
	}
}

int main() {
	//ifstream input("input.txt");
	int startNode, dataLength, start, end;
	int testCase = 10;
	int n = 1;
	while (testCase-- > 0)
	{
		cin >> dataLength >> startNode;
		dataLength = dataLength >> 1;
		for (int i = 0; i < dataLength ; i++)
		{
			cin >> start >> end;
			address[start][end] = 1;
		}
		// edge 정보 저장
		

		bfs(startNode, t);
		int maxTime = 0;
		
		for (int i = 1; i <= 100; i++)	// 가장 나중에 연락받은 사람들이 걸린 시간.
		{
			if (timeCount[i] > maxTime)
			{
				maxTime = timeCount[i];
			}
		}

		for (int i = 100; i >= 1; i--)
		{
			if (timeCount[i] == maxTime)
			{
				cout << "#" << n << " "<< i << endl;
				break;
			}
		}
		init();
		n++;
	}

}
// 처음에 bfs를 생각하였으나 t인자를 다룰줄 몰라서 dfs로 구현했다, 하지만 이 문제는 꼭 bfs로 풀어야 풀 수 있다. 뒤늦게 t인자 다루는법을 깨달음.
