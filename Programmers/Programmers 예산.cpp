#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    sort(budgets.begin(), budgets.end());
    int left = 0;
    int right = budgets[budgets.size()-1];
    int mid = (left + right) / 2;
    int total = M;
    while(left <= right)
    {
        for(int i=0; i<budgets.size(); i++)
        {
            if(budgets[i] < mid)
            {
                total -= budgets[i];
            }
            else
            {
                total -= mid;
            }
            
            if(total < 0) break;
        }
        // 예산분배 끝 !!
        if(total > 0)
        {
            left = mid + 1;
            mid = (right + left) / 2;
            total = M;
        }
        else if(total < 0)
        {
            right = mid - 1;
            mid = (right + left) / 2;
            total = M;
        }

    }
    answer = mid;
    return answer;
}

// 답을 예상하고 이분탐색으로 접근하는 방법이다.
// 이분탐색 !!
