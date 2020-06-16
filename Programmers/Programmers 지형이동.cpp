#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#define ABS(A,B) (A>B ? A-B:B-A)
using namespace std;
bool visit[301][301];
int map[301][301];
int cnt, N;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int p[90001];
int temp_answer;
typedef struct
{
    int dist, src, des;
}edge;

struct cmp
{
    bool operator()(edge &a, edge &b)
    {
        return a.dist > b.dist;
    }
};

bool compare(const edge &a, const edge &b)
{
    return a.dist < b.dist;
}

priority_queue<edge, vector<edge>, cmp> pq;
vector<edge> v;

bool isWall(int x, int y)
{
    if(x < 0 || y < 0 || x > N-1 || y > N-1) return true;
    else return false;
}

void dfs(vector<vector<int>> land, int height, int x, int y)
    // 지형 Group화 방법 1. dfs
{
    int new_x, new_y;
    for(int i=0; i<4; i++)
    {
        new_x = x + dx[i];
        new_y = y + dy[i];
        if(isWall(new_x, new_y)) continue;
        if(visit[new_x][new_y]) continue;
        if(ABS(land[x][y], land[new_x][new_y]) > height) continue;
        visit[new_x][new_y] = true;
        map[new_x][new_y] = cnt;
        dfs(land, height, new_x, new_y);
    }
}

void bfs(vector<vector<int>> land, int height, int x, int y)
    // 지형 Group화 방법 2. bfs
{
    int cur_x, cur_y, new_x, new_y;
    queue<pair<int, int>> q;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        cur_x = q.front().first;
        cur_y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            new_x = cur_x + dx[i];
            new_y = cur_y + dy[i];
            if(isWall(new_x, new_y)) continue;
            if(visit[new_x][new_y]) continue;
            if(ABS(land[cur_x][cur_y], land[new_x][new_y]) > height) continue;
            visit[new_x][new_y] = true;
            map[new_x][new_y] = cnt;
            q.push(make_pair(new_x, new_y));
        }
    }
}

void FindEdge(vector<vector<int>> land, int x, int y, int src)
{
    int new_x, new_y;
    edge e;
    for(int i=1; i<=2; i++)
    {
        new_x = x + dx[i];
        new_y = y + dy[i];
        if(isWall(new_x, new_y)) continue;
        if(visit[new_x][new_y]) continue;
        if(src != map[new_x][new_y])
        {
            e.dist = ABS(land[x][y], land[new_x][new_y]);
            e.src = map[x][y];
            e.des = map[new_x][new_y];
            v.push_back(e);
        }
    }
}

int Find_set(int x)
{
    if(p[x] != x)
    {
        p[x] = Find_set(p[x]);
    }
    return p[x];
}

void Union(int x, int y)
{
    p[y] = x;
}

void Kruskal()
{
    for(int i=1; i<=cnt; i++)
    {
        p[i] = i;
    }
    // init 해주기 !!!!
    int edgeCount=0;
    edge e;
    sort(v.begin(), v.end(), compare);
    // vector정렬
    for(int i=0; i<v.size(); i++)
    {
        e.dist = v[i].dist;
        e.src = v[i].src;
        e.des = v[i].des;
        if(Find_set(e.src) == Find_set(e.des)) continue;
        // 같은 집합이면  ??? continue !!!
        Union(Find_set(e.src), Find_set(e.des));
        temp_answer += e.dist;
        edgeCount++;
        if(edgeCount == cnt -1) break;
    }
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    N = land.size();
    cnt = 0;
    memset(visit, 0, sizeof(visit));
    memset(map, 0, sizeof(map));
    while(!pq.empty()) pq.pop();
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(!visit[i][j])
            {
                visit[i][j] = true;
                cnt++;
                map[i][j] = cnt;
                bfs(land, height, i, j);
            }
        }
    }

    // 여기까지 맵 표시 완료 !!
    memset(visit, 0, sizeof(visit));
    // 이제부터는 edge를 우선순위 큐에 넣어야 함!!
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(!visit[i][j])
            {
                visit[i][j] = true;
                FindEdge(land, i, j, map[i][j]);
            }
        }
    }
    // 우선순위 큐에 edge 다 넣음 !!! 이제 크루스칼 알고리즘 돌리기 !!
    Kruskal();
    answer = temp_answer;
    return answer;
}

// 그룹화를 할 때에는 dfs보다 bfs가 더 빠르다. (이 부분에서 실수해서 시간을 날림)
// 그룹화를 한 후 크루스칼 알고리즘을 사용하여 MST 구현해주면 된다.
// 
