#include <iostream>
//#include <fstream>
#include <queue>
#include <cstring>
#define MIN(A,B) (A<B ? A:B)
#define ABS(A,B) (A>B ? A-B:B-A)

using namespace std;
int N, node;
int people[11];
int adj[11][11] = { -1 };
// 각 노드간의 연결 관계를 나타내는 인접행렬
bool combination[11] = { false };
// 조합을 생성할 combination 배열
bool visit[11] = { false };
// 지역구 수를 구할때 노드 방문 여부를 판단하는 visit배열
int answer = 987654321;

void MakeCombination(int depth, int index)
{
	if (depth == N) return;
	// 조합이 N개 뽑힌 경우는 지역구 수가 1개밖에 안 나오므로 이 경우는 제외해도 무관.
	

	// 선거구의 개수를 구해야 한다. 3개이상이면 ㄴㄴ
	memset(visit, 0, sizeof(visit));
	queue<int> q;
	// 지역구 개수를 구하기 위해 사용하는 queue
	int vote_count = 0;
	// 지역구의 수를 카운트하는 변수
	bool isTwo = true;
	// 지역구의 수가 2개이면 인구차를 구해야 하므로 isTwo boolean 변수
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			q.push(i);
			visit[i] = true;
			vote_count++;
			if (vote_count >= 3)
			{
				isTwo = false;
				break;
			}

			while (!q.empty())
			{
				int src = q.front();
				q.pop();
				for (int i = 2; i <= adj[src][1] + 1; i++)
				{
					if (!visit[adj[src][i]] && combination[src] == combination[adj[src][i]]) // 아직 방문하지 않은 노드이고, 기준 노드랑 같은 조합인 경우 ??? 
					{
						visit[adj[src][i]] = true;
						q.push(adj[src][i]);
					}
				}

			}

		}
	}

	if (isTwo)
	{
		int false_sum = 0;
		int true_sum = 0;
		for (int i = 1; i <= N; i++)
		{
			if (combination[i])
				true_sum += people[i];
			else false_sum += people[i];
		}

		answer = MIN(answer, ABS(true_sum ,false_sum));
	}

	for (int i = index; i <= N; i++)
	{
		if (!combination[i])
		{
			combination[i] = true;
			MakeCombination(depth + 1, i);
			combination[i] = false;
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> people[i];
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> node;
		adj[i][1] = node;
		for (int j = 2; j <= node + 1; j++)
		{
			cin >> adj[i][j];
		}
	}
	// 인구수, 인접행렬 정보 입력 완료
	for (int i = 1; i <= N; i++)
	{
		if (!combination[i])
		{
			combination[i] = true;
			MakeCombination(1, i);
			combination[i] = false;
		}
	}
	if (answer == 987654321)
		cout << -1 << '\n';
	else cout << answer << '\n';
	return 0;
}

// 조합 + bfs로 풀었다.
// 지역구의 수를 구하기 위해 Union을 사용했지만 실패해서 BFS로 구했다.
