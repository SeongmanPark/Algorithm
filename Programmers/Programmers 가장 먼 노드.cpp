#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define MAX(A,B) (A>B ? A:B)
using namespace std;
bool visit[20001] = {false};
int node_length[20001];
queue<int> q;


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max_length=0;
    q.push(1);
    node_length[1] = 0;
    visit[1] = true;
    while(!q.empty())
    {
        int src = q.front();
        q.pop();
        
        for(int i=0; i<edge.size(); i++)
        {
            if(edge[i][0] == src)
            {
                if(!visit[edge[i][1]])
                {
                    visit[edge[i][1]] = true;
                    node_length[edge[i][1]] = node_length[edge[i][0]] + 1;
                    max_length = MAX(max_length, node_length[edge[i][1]]);
                    q.push(edge[i][1]);
                }
            }
            else if(edge[i][1] == src)
            {
                 if(!visit[edge[i][0]])
                {
                    visit[edge[i][0]] = true;
                    node_length[edge[i][0]] = node_length[edge[i][1]] + 1;
                    max_length = MAX(max_length, node_length[edge[i][0]]);
                    q.push(edge[i][0]);
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(node_length[i] == max_length) answer++;
    }

    return answer;
}

// BFS문제
// 프로그래머스는 입력을 벡터로 받아서 뭔가 적응이 안된다.
// 간단한 
