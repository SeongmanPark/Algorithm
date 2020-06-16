#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
//13 12 8 13
//1 2 1 3 2 4 3 5 3 6 4 7 7 12 5 9 5 8 6 11 6 10 11 13
using namespace std;

int testCase;
int V, E, find_index1, find_index2, parent, child;
char map[10001][10001];
bool visit[10001] = { false };
queue<int> Q;

void init()
{
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));
}

void find_parent(int index)
{
	if (index == 1)
	{
		visit[index] = true;
		return;
	}
	for (int i = 1; i <= V; i++)
	{
		if (map[i][index])	// index를 자식으로 하는 부모가 있다면 ? 
		{
			visit[i] = true;	// 부모를 체크하고
			find_parent(i);	// index의 조부모 찾기
		}
	}
}

void find_same_parent(int index)
{
	if (index == 1) {
		Q.push(index);
		return;
	}

	for (int i = 1; i <= V; i++)
	{
		if (map[i][index]) // index를 자식으로 하는 부모가 있는데 ?
		{
			if (visit[i])	// 그 부모가 find_index1의 부모라면 ?
			{
				Q.push(i);	// 큐에 넣고
				return;
			}
			else
			{
				find_same_parent(i);
			}
		}
	}
}

int main()
{
	ifstream input("input.txt");
	input >> testCase;
	int a = 1;
	while (testCase-- > 0)
	{
		input >> V >> E >> find_index1 >> find_index2;
		for (int i = 1; i <= E; i++)
		{
			input >> parent >> child;
			map[parent][child] = 1;
		}
		// parent, child 입력 완료

		find_parent(find_index1);
		// find_index1 의 부모 다 check !!!!!!

		find_same_parent(find_index2);
		// 공통부모찾음	

		cout << "#" << a << " " << Q.front() << " ";
		a++;
		int Q_size = 1;
		while (!Q.empty())
		{
			int same_parent = Q.front();
			Q.pop();
			for (int i = 1; i <= V; i++)
			{
				if (map[same_parent][i] == 1)
				{
					Q.push(i);
					Q_size++;
				}
			}
		}
		cout << Q_size << '\n';
		init();	
	}
}

// map을 int로 선언하여 메모리 초과가 났다. char으로 바꿔서 해결 !!
