#include <iostream>
//#include <fstream>
#include <algorithm>
 
using namespace std;
 
int dfs(int N, int &MAdress, int &answerAddress) {
    answerAddress *= N;
    MAdress--;
    if (MAdress == 1) return answerAddress;
    else dfs(N, MAdress, answerAddress);
}
 
int main() {
    //ifstream input("input.txt");
    int N, M;
    int testCaseNum;
    int testCase = 10;
 
    while(testCase>0){
        cin >> testCaseNum;
        cin >> N >> M;
        int answer = N;
        int *answerAdress = &answer;
        int *MAdress = &M;
 
        cout << "#" << testCaseNum << " " << dfs(N, *MAdress, *answerAdress) << endl;
        testCase--;
    }
 
 
    return 0;
}
// 거듭제곱 수를 구하는 문제이다. 재귀함수 호출을 위해 값이 아닌 주소값을 인자로 넘겨야 한다. 포인터 공부를 제대로 해야할것 같다.
