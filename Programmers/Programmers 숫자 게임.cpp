#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int A_size = A.size();
    int B_size = A_size;
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    int A_index = 0;
    int B_index = 0;
    while(A_index < A_size){
        if(A[A_index] < B[B_index]){
            answer++;
            A_index++;
            B_index++;
        }
        else {
            A_index++;
        }
    }
    
    return answer;
}
