#include <iostream>
//#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[101] = { 0 };



int main() {
	//ifstream input("input.txt");
	int testCase, testCaseNum;
	int grade;

	cin >> testCase;
	while (testCase > 0) {
		cin >> testCaseNum;
		int maxGrade = 0;
		for (int i = 0; i < 1000; i++) {
			cin >> grade;
			arr[grade]++;
		}
		// 점수 입력 완료
		
		for (int i = 1; i <= 100; i++) {
			maxGrade = max(maxGrade, arr[i]);
		}
		// 최고점수 찾기

		for (int i = 100;; i--) {
			if (arr[i] == maxGrade) {
				cout << "#" << testCaseNum << " " << i << endl;
				break;
			}
		}
		// 출력

		for (int i = 1; i <= 100; i++) {
			arr[i] = 0;
		}
		// 배열 초기화
		testCase--;
	}
}
