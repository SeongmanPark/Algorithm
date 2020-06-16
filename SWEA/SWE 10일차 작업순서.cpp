#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int vertexCount[1001] = { 0 };
vector <pair<int, int>> v;
queue<int> Q;

int main() {
	ifstream input("input.txt");
	int testCase = 1;
	int V, E, E_Start, E_End;
	int n = 1;
	while (testCase > 0) {
		input >> V >> E;
		for (int i = 1; i <= E; i++) {
			input >> E_Start >> E_End;
			vertexCount[E_End]++;	// 나한테 몇개 연결되어있는지 ?
			v.push_back(make_pair(E_Start, E_End));	// 간선 정보 입력 (단방향)
		}



		int v_size = v.size();
		for (int i = 1; i <= V; i++) {
			if (vertexCount[i] == 0) {
				Q.push(i);
			}
		}
		cout << "#" << n << " ";

		while (!Q.empty())
		{
			int vertex = Q.front();
			cout << Q.front() << " ";
			Q.pop();
			for (int i = 0; i < v_size; i++)
			{
				if (vertex == v[i].first)
				{
					vertexCount[v[i].second]--;
					if (vertexCount[v[i].second] == 0)
					{
						Q.push(v[i].second);
					}

				}


			}
		}
		for (int i = 1; i <= 1000; i++) {
			vertexCount[i] = 0;
		}
		n++;
		cout << endl;
		v.clear();
		testCase--;
	}
}
// 문제를 똑바로 읽어야 함. Edge의 정보만 보고 Vertex 사용여부를 판단하지 말자.
