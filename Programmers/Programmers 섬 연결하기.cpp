#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int parent[101];

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
// 간선을 비용순으로 정렬 !!!

void init(int n)
{
    for(int i=1; i<=n;i++)
    {
        parent[i] = i;
    }
}
// 노드 초기화 하기

int Find_set(int x)
{
    if(parent[x] != x)
    {
        parent[x] = Find_set(parent[x]);
    }
    return parent[x];
}

void Union(int x, int y)
{
    parent[y] = x;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int connect_edge = 0;
    sort(costs.begin(), costs.end(), cmp);
    // 간선 비용 정렬 완료
    init(n);
    
    int costs_size = costs.size();
    for(int i=0; i<costs_size; i++)
    {
        if(Find_set(costs[i][0]) == Find_set(costs[i][1])) continue;
        // 부모가 같다면 사이클이 형성되니까 pass
        
        Union(Find_set(costs[i][0]), Find_set(costs[i][1]));
        // 유니온 해주고
        answer += costs[i][2];
        // 가격 더해주고
        if(++connect_edge == n-1)
            break;
    }
    
    
    return answer;
}

// 최소비용신장트리(MST) 문제이다.
// 크루스칼 알고리즘을 이용하여 구현하였음
// vector에 간선정보 다 있어서 그냥 크루스칼로 풀었다.
