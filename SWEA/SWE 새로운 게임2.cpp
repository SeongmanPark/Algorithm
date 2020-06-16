#include <iostream>
//#include <fstream>
#include <stack>
using namespace std;

int map[13][13];

int dx[] = { 0, 0,0,-1,1 };
int dy[] = { 0, 1,-1,0,0 };
int changeDir[5] = {0 ,2, 1,4, 3 };

struct horse
{
	int currentX, currentY, currentDir;
};

struct mapInfo
{
	stack<int> s;
	int horesSize;
};

struct mapInfo m[13][13];
struct horse h[11];

int main()
{
	//ifstream input("input.txt");
	int N, K, x, y, dir;
	int time = 0;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}
	// map 입력
	for (int i = 1; i <= K; i++)
	{
		cin >> x >> y >> dir;
		h[i].currentX = x;
		h[i].currentY = y;
		h[i].currentDir = dir;
		m[x][y].horesSize = 1;
		m[x][y].s.push(i);
	}
	// 구조체에 방향정보 입력 완료

	while (1)
	{
		time++;
		if (time > 1000)
		{
			cout << -1 << endl;
			break;
		}

		for (int i = 1; i <= K; i++)
		{
			x = h[i].currentX;
			y = h[i].currentY;
			int new_x = h[i].currentX + dx[h[i].currentDir];
			int new_y = h[i].currentY + dy[h[i].currentDir];
			
			if (new_x <= 0 || new_y <= 0 || new_x >= N + 1 || new_y >= N + 1 || map[new_x][new_y] == 2)	// 경계를 벗어날 경우 ?, 파란색인 경우 ? 한칸 이동
			{
				h[i].currentDir = changeDir[h[i].currentDir];
				new_x = h[i].currentX + dx[h[i].currentDir];
				new_y = h[i].currentY + dy[h[i].currentDir];
				// 방향 바꿔주고 new_ 변경 후 이제 이동하기
			}
			//cout << "time: " << time << "    " << "i: " << i << "    " << new_x << ',' << new_y << endl;
			if (map[new_x][new_y] == 0 && new_x != 0 && new_y != 0 && new_x != N+1 && new_y != N+1)	// 칸이 흰 색인 경우 !!!!
			{
				
				stack <int> s1;
				// i번 말과 위에있는 말이 전부 다 이동해야함.
				while (m[x][y].s.top() != i)	// i번 말이 나올때까지 팝
				{
					s1.push(m[x][y].s.top());	// s1스택에 푸쉬
					m[x][y].s.pop();
					m[x][y].horesSize--;
				}
				s1.push(m[x][y].s.top());
				m[x][y].s.pop();
				m[x][y].horesSize--;
				// i번 말 pop
				while (!s1.empty())
				{
					h[s1.top()].currentX = new_x;
					h[s1.top()].currentY = new_y;
					m[new_x][new_y].s.push(s1.top());
					m[new_x][new_y].horesSize++;
					s1.pop();
				}
				if (m[new_x][new_y].horesSize >= 4)
				{
					cout << time << endl;
					return 0;
				}
			}
			// 흰칸
			else if (map[new_x][new_y] == 1 && new_x != 0 && new_y != 0 && new_x != N + 1 && new_y != N + 1)	// 칸이 빨간 색인 경우?
			{
				while (m[x][y].s.top() != i)
				{
					h[m[x][y].s.top()].currentX = new_x;
					h[m[x][y].s.top()].currentY = new_y;
					m[new_x][new_y].s.push(m[x][y].s.top());
					m[new_x][new_y].horesSize++;
					m[x][y].s.pop();
					m[x][y].horesSize--;
				}
				h[m[x][y].s.top()].currentX = new_x;
				h[m[x][y].s.top()].currentY = new_y;
				m[new_x][new_y].s.push(m[x][y].s.top());
				m[new_x][new_y].horesSize++;
				m[x][y].s.pop();
				m[x][y].horesSize--;
				// i번 말이 나올때까지 pop후 map[new_x][new_y]에 push
				
				if (m[new_x][new_y].horesSize >= 4)
				{
					cout << time << endl;
					return 0;
				}
			}

			/*
			for (int i = 1; i <= K; i++)
			{
				cout << h[i].currentX << ',' << h[i].currentY << endl;
			}
			cout << endl;
			*/
			
		}
	}

}
// 2시간 30분만에 풀었습니다. 계속 런타임 에러가 떠서 확인해보니 세그먼트 폴트 문제였고 강제로 조건문에 인덱스 조건 추가해서 pass는 했지만
// 나중에 
