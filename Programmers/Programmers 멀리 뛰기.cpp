#include <string>
#include <vector>

using namespace std;
// 1 -> 1
// 2 -> 1,1 or 2
// 3 -> 1,1,1 or 1,2 or 2,1
// 4 -> 1,1,1,1 or 1,2,1 or 1,1,2 or 2,1,1 or 2,2
// 5 -> 1,1,1,1,1 or 1,2,1,1 or 1,1,2,1 or 2,1,1,1 or 1,1,1,2 or 1,2,2 or 2,1,2 or 2,2,1
long long arr[2001];
long long solution(int n) {
    long long answer = 0;
    arr[1] = 1; arr[2] = 2; arr[3] = 3; arr[4] = 5;
    if(n <= 4) return arr[n];
    else 
    {
        for(int i=4; i<=n; i++)
        {
            arr[i] = (arr[i-1] + arr[i-2]) % 1234567;
        }
    }
    return arr[n];
}

// dp
