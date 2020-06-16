#include <iostream>
//#include <fstream>
#include <algorithm>
 
#define MAX 8
using namespace std;
char arr[9][9];
 
int main() {
    //ifstream input("input.txt");
    int testCase = 10;
    int findLength;
    char inputChar;
    int answer = 0;
    int n = 1;
    while (testCase > 0) {
        cin >> findLength;
        for (int i = 1; i <= MAX; i++) for (int j = 1; j <= MAX; j++) cin >> arr[i][j];
        // 배열 입력 완료
         
        for (int i = 1; i <= MAX; i++) {
            for (int j = 1; j <= MAX - findLength + 1 ; j++) {
                // 기준점 설정 완료
                int start = 0;
                int end = findLength - 1;
                int flag = 0;
 
                while (start < end) {    // 비교
                    if (arr[i][j + start] != arr[i][j + end]) {
                        flag = 1;
                        break;
                    }
                    start++;
                    end--;
                }
                if (flag == 0) {
                    answer++;
                }
            }
        }
        for (int j = 1; j <= MAX; j++) {
            for (int i = 1; i <= MAX - findLength + 1 ; i++) {
                int start = 0;
                int end = findLength - 1;
                int flag = 0;
 
                while (start < end) {
                    if (arr[i + start][j] != arr[i + end][j]) {
                        flag = 1;
                        break;
                    }
                    start++;
                    end--;
                }
                if (flag == 0) {
                    answer++;
                }
            }
        }
        cout << "#" << n << " " << answer << endl;
        testCase--;
        n++;
        answer = 0;
    }
    return 0;
}

// 문자열을 비교할 때 제일 처음에 스택을 이용하려고 했다. 그럴 필요없이 start, end 변수 선언해서 비교하였다.
