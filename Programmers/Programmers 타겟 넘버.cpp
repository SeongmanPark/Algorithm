#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

int N;
bool visit[21];
int temp_answer;

void dfs(vector<int> numbers, int target, int depth, int total)
{
    if(depth == N)
    {
        if(target == total)
        {
            temp_answer++;
        }
        return;
    }
    dfs(numbers, target, depth + 1, total + numbers[depth]);
    dfs(numbers, target, depth + 1, total - numbers[depth]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    N = numbers.size();
    memset(visit, 0, sizeof(visit));
    temp_answer = 0;
    
    dfs(numbers, target, 1, numbers[0]);
    dfs(numbers, target, 1, -numbers[0]);
    answer = temp_answer;
    return answer;
}

// 조합을 사용하여 간단하게 풀었다.
