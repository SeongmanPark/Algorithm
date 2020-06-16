#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int vector_size = prices.size();
    
    for(int i=0; i<vector_size; i++)
    {
        int min=0;
        for(int j = i+1; j<vector_size; j++)
        {
            if(prices[i] <= prices[j])
                min++;
            else 
            {
                min++;
                break;
            }
        }
        answer.push_back(min);
    }
    return answer;


// 문제 지문의 설명이 완벽하지 않아서 당황했음.
