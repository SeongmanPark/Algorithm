#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
bool visit[100001];

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> v[500];
    memset(visit, 0, sizeof(visit));
    string temp = "";
    int idx=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '{') continue;
        else if(s[i] == '}')
        {
            if(s[i-1] != '}')
            {
                v[idx++].push_back(temp);
                temp = "";
            }
        }
        else if(s[i] == ',')
        {
            if(s[i-1] != '}')
            {
                v[idx].push_back(temp);
                temp = "";
            }
        }
        else
        {
            temp += s[i];
        }
    }
    // parsing 완료 !!
    int k = 1;
    // idx = v.size()
    while(k <= idx)
    {
        for(int i=0; i<idx; i++)
        {
            if(v[i].size() == k)
            {
                for(int j=0; j<k; j++)
                {
                    int tmp = stoi(v[i][j]);
                    if(!visit[tmp])
                    {
                        answer.push_back(tmp);
                        visit[tmp] = true;
                    }
                }
            }
        }
        k++;
    }
    return answer;
}

// 어떻게 풀지 구상을 잘 해야한다.
// 원소의 개수가 작은것부터 순서대로 정렬하여 추가가 된 원소를 붙여주면 된다.
