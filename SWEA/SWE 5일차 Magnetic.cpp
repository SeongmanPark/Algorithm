#include <iostream>
#include <fstream>
#define MAX 100
using namespace std;
// 1은 N극 2는 S극

// N
//
// S
int arr[101][101] = { 0 };

int main() {
    ifstream input("input.txt");
    int N;
    int testCase = 10;
    int DeadLock = 0;
    int n = 1;

    while(testCase>0){
    input >> N;

    for (int i = 1; i <= MAX; i++) {
        for (int j = 1; j <= MAX; j++) {
            input >> arr[i][j];
        }
    }

    for (int k = 1; k <= MAX; k++) {    // 1초에 1칸씩 이동
        for (int i = 1; i <= MAX; i++) {
            for (int j = 1; j <= MAX; j++) {
                if (arr[i][j] == 1) {   // N(1) 을 찾으면 밑으로 한칸.
                    if (i + 1 == 101) {
                        arr[i][j] = 0;
                    }
                    if (arr[i + 1][j] == 0) {
                        arr[i][j] = 0;
                        arr[i + 1][j] = 1;
                    }
                }
                else if (arr[i][j] == 2) {
                    if (i - 1 == 0) {
                        arr[i][j] = 0;
                    }
                    if (arr[i - 1][j] == 0) {
                        arr[i][j] = 0;
                        arr[i - 1][j] = 2;
                    }
                }
            }
        }
    }
    // 자석이동 완료 !!!!
    for (int j = 1; j <= MAX; j++) {
        int currentMag = 0;
        for (int i = 1; i <= MAX; i++) {
            if (arr[i][j] == 0)
                continue;
            
            if (arr[i][j] == 1) {
                    if (currentMag == 0) {
                        currentMag = 1;
                        continue;
                    }
            }
            else if (arr[i][j] == 2) {
                if (currentMag == 1) {
                    DeadLock++;
                    currentMag = 0;
                }
            }

            
        }
    }
    // 위에서 내려오면 무조껀 N(1)극만 만남
    testCase--;
    cout << "#" << n << " " << DeadLock << endl;
    DeadLock = 0;
    n++;
    }


}


// for문 3번 중첩에서 마음이 걸리긴 하다. 시뮬레이션이 아니라 논리적으로 한 번 생각해볼것 !
