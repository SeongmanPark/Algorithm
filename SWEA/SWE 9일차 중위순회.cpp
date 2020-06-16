#include <iostream>
//#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

struct Node {
	char data = 0;
	int vertex;
};

struct Node *p = new Node[101];

bool visit[101] = { false };

void inorder(int x)
{
	if (!visit[x] && p[x].data != 0)
	{
		inorder(x * 2);
		cout << p[x].data;
		inorder(x * 2 + 1);
	}
	else return;
}

int main()
{
	//ifstream input("input.txt");
	int testCase = 10;
	int n = 1;
	while (testCase-- > 0)
	{
		for (int i = 0; i <= 100; i++)
		{
			p[i].data = 0;
			p[i].vertex = 0;
		}
		int vertexNum;
		int vertex;
		char c;
		int nothing;
		cin >> vertexNum;
			for (int i = 1; i <= vertexNum; i++)
			{
				cin >> vertex >> c;
				p[vertex].data = c;
				p[vertex].vertex = vertex;
				if (i * 2 < vertexNum)	// i = 1,2,3,4
				{
					cin >> nothing >> nothing;
				}
				else if (i * 2 == vertexNum)
				{
					cin >> nothing;
				}

			}
			printf("#%d ", n);
			inorder(1);
			printf("\n");
			n++;
	}
}
// 트리 구현해서 중위순회 하면 됨, 간단함, 파일 입력받을때 고민을 좀 했었다.
