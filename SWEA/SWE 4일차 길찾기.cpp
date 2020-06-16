#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;
bool arr[100][100] = { false };
bool visit[100] = { false };

int main() {
	ifstream input("input.txt");
	int testCaseNum, arrLength;
	int a, b;
	int testCase = 10;
	while (testCase > 0) {
		input >> testCaseNum >> arrLength;
		queue<int> Q;

		for (int i = 0; i < arrLength; i++) {
			input >> a >> b;
			arr[a][b] = true;
		}
		// 배열 입력 완료
		Q.push(0);
		while (!Q.empty()) {
			int vertex = Q.front();
			Q.pop();
			for (int i = 0; i < 100; i++) {
				if (arr[vertex][i] && !visit[i]) {
					visit[i] = true;
					Q.push(i);
				}
			}
		}
		if (visit[99]) cout << "#" << testCaseNum << " " << 1 << endl;
		else cout << "#" << testCaseNum << " " << 0 << endl;
		testCase--;
		for (int i = 0; i < 100; i++) {
			visit[i] = false;
			for (int j = 0; j < 100; j++) arr[i][j] = false;
		}
	}
}

// arr[100][100]을 쓰지 않고 bfs돌릴순 없을까 생각해보기, 메모리 아끼기.
