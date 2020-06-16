#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
bool visit[10000];
vector<string> temp_answer;
void dfs(vector<vector<string>> tickets, int depth, string start, vector<string> v)
{
    if(depth == tickets.size())
    {
        v.push_back(start);
        // 티켓 배열 완성 !! 이제 알파벳 비교하기
        if(temp_answer.size() == 0)
        {
            for(int i=0; i<v.size(); i++)
            {
                temp_answer.push_back(v[i]);
            }
            return;
        }
        else
        {
            for(int i=0; i<v.size(); i++)
            {
                if(v[i] == temp_answer[i]) continue;
                else if(v[i] > temp_answer[i]) return;
                if(v[i] < temp_answer[i])
                {
                    //cout << "change index : "<<i<<endl;
                    for(int j=0; j<v.size(); j++)
                    {
                        temp_answer[j] = v[j];
                    }
                    return;
                }
            }
            return;
        }
    }
    
    for(int i=0; i<tickets.size(); i++)
    {
        if(visit[i]) continue;
        if(tickets[i][0] == start)
        {
            visit[i] = true;
            v.push_back(tickets[i][0]);
            dfs(tickets, depth + 1, tickets[i][1], v);
            v.pop_back();
            visit[i] = false;
        }
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<string> v;
    memset(visit, 0, sizeof(visit));
    for(int i=0; i<tickets.size(); i++)
    {
        if(tickets[i][0] == "ICN")
        {
            visit[i] = true;
            v.push_back("ICN");
            dfs(tickets, 1, tickets[i][1], v);
            v.pop_back();
            visit[i] = false;
        }
    }
    
    return temp_answer;
}

// dfs으로 경로를 벡터에 담고 알파벳 순으로 비교한다.
// 이미 경로가 정해졌으면 가지치기도 가능 !!
