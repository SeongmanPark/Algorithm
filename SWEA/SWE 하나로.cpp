#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
long long map_x[1001];
long long map_y[1001];
int p[1001];
double answer;
int testCase, N;
double E;
int a = 1;

struct edge
{
	int start, end;
	long long cost;
};

vector<edge> v;	// 모든 간선을 저장하는 벡터 !!

void init()
{
	answer = 0;
	memset(map_x, 0, sizeof(map_x));
	memset(map_y, 0, sizeof(map_y));
	v.clear();
	a++;
}

bool cmp(const edge& a, const edge& b)
{
	return a.cost < b.cost;
}

int Find_set(int x)
{
	if (x != p[x])
		p[x] = Find_set(p[x]);
	return p[x];
}
// Find_set(int x) 함수
// => 갱신할때 항상 루트부모를 가리키게 !!

void Make_set()
{
	for (int i = 1; i <= N; i++)
	{
		p[i] = i;
	}
}
// 초기상황으로 !!! 
// 각 노드의 루트는 자기 자신을 가리키게 !!!

void Union(int x, int y)
{
	p[Find_set(y)] = Find_set(x);
}
// x,y의 최상 루트 노드를 연결 !!!!!!

void Kruskal()
{
	int cnt = 0;
	int v_size = v.size();
	for (int i = 0; i < v_size; i++)
	{
		if (Find_set(v[i].start) == Find_set(v[i].end))	// 같은 union에 있다면 ? 이 간선은 안됨..
		{
			continue;
		}
		else
		{
			Union(v[i].start, v[i].end);	// disjoint하다면 포함시키기
			answer += v[i].cost;	// 간선의 비용 누적으로 저장하고
			cnt++;	// 연결시킨 간선의 개수 늘리기
		}

		if (cnt == N - 1)	// 간선을 N-1개 선택 했으니까 끝!!!!
			return;
	}
}

int main()
{
	ifstream cin("input.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> testCase;

	while (testCase-- > 0)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> map_x[i];
		for (int i = 1; i <= N; i++)
			cin >> map_y[i];

		cin >> E;
		// 입력 완료 !!!!!!
		// 크루스칼 알고리즘을 위한 간선 구하기 !!!!
		edge e;
		for (int i = 1; i <= N; i++)
		{
			for (int j = i + 1; j <= N; j++)
				// nC2 !!!!!!
			{
				e.cost = ((map_x[i] - map_x[j]) * (map_x[i] - map_x[j]) + (map_y[i] - map_y[j]) * (map_y[i] - map_y[j]));
				e.start = i;
				e.end = j;
				v.push_back(e);
			}
		}
		// 인접 행렬 완성
		sort(v.begin(), v.end(), cmp);
		Make_set();
		Kruskal();
		answer *= E;
		answer = round(answer);
		// 소수점 첫째 자리에서 반올림
		cout << "#" << a << " " << (long long)answer << '\n';
		init();
	}
}

// 크루스칼 알고리즘을 이용한 대표적인 MST 문제
// Union(int x, int y) 부분에서 합쳐줄 때 꼭 최상 루트 노드끼리 합쳐야 한다.
// 왜 ? Disjoint 검사를 최상 루트 노드끼리 했으

#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

long long Adj[1001][1001];
long long map_x[1001];
long long map_y[1001];
long long key[1001];
// Key 배열이 하는 역할
// 현재 선택집합에서 갈 수 있는 정점들의 최소 비용이 담겨 있는 배열 !!!!
bool visit[1001] = { false };
int testCase, N;
double answer, E;
int a = 1;

void init()
{
	memset(map_x, 0, sizeof(map_x));
	memset(map_y, 0, sizeof(map_y));
	memset(Adj, 0, sizeof(Adj));
	memset(visit, 0, sizeof(visit));
	answer = 0;
	a++;
}

typedef struct Vertex
{
	int des;
	long long cost;
	bool operator >(const Vertex a) const
	{
		return cost > a.cost;
	}
}V;

//struct cmp
//{
//	bool operator()(V a, V b)
//	{
//		return a.cost > b.cost;
//	}
//};

void Key_set()
{
	for (int i = 1; i <= N; i++) key[i] = 0xFFFFFFFFFFFF;
}

void Prim()
{
	priority_queue <V, vector<V>, greater<V>> pq;
	//priority_queue <V, vector<V>, cmp> pq;
	V v;
	int u;
	long long u_cost;
	// 우선순위 큐
	// 정점 u가 선택되면 u의 인접한 노드 des중 비용이 가장 낮은 놈 넣기
	v.cost = 0;
	v.des = 1;
	key[1] = 0;
	// 1번째 vertex 삽입하기
	pq.push(v);

	while (!pq.empty())
	{
		u = pq.top().des;
		u_cost = pq.top().cost;
		pq.pop();
		// 우선순위 큐의 젤 앞 놈을 꺼냄 (우선순위 큐 안에 들어있는 노드중 가장 비용이 쌈
		if (visit[u]) continue;
		// 젤 앞 놈이 Union에 포함된 놈이라면 pass
		visit[u] = true;
		answer += u_cost;
		for (int i = 1; i <= N; i++)
		{
			if (visit[i]) continue;
			// 이미 선택집합에 포함된 놈이라면 ? pass
			if (key[i] > Adj[u][i])
			{
				key[i] = Adj[u][i];
				// Key값 갱신 필요 !!!
				// 최소비용 갱신 해야함 !!
				// 갱신 했으니까 최신 데이터를 PQ에 넣어야겠지 ?
				v.des = i;
				v.cost = Adj[u][i];
				pq.push(v);
			}
			// 만약 key값을 더 최소비용으로 갱신할 수 있다면 갱신하기
		}
	}

	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("input.txt");
	
	cin >> testCase;
	while (testCase-- > 0)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> map_x[i];
		}
		for (int i = 1; i <= N; i++)
		{
			cin >> map_y[i];
		}
		cin >> E;
		// 입력 완료

		for (int i = 1; i <= N; i++)
		{
			for (int j = i+1; j <= N; j++)
			{
				if (i == j) Adj[i][j] = 0xFFFFF;
				else
				{
					Adj[i][j] = Adj[j][i] = (map_x[i] - map_x[j]) * (map_x[i] - map_x[j]) + (map_y[i] - map_y[j]) * (map_y[i] - map_y[j]);
				}
			}
		}
		// 인접 행렬 입력 완료..
		Key_set();
		Prim();
		answer *= E;
		cout << "#" << a << " " << (long long)round(answer) << "\n";
		init();
	}
}

// Prim 알고리즘을 이용해서 구현해 보았다.
// Key배열을 통해 현재 선택집합에서 갈 수 있는 최소 가중치를 업데이트 해 주고 PQ에 삽입
// PQ에는 같은 dst를 가진 구조체가 있을지라도 최소 비용이 앞에 오기 때문에 꺼낼때 중복으로 꺼내진 않는다.
// visit배열을 쓰기 때문에 
