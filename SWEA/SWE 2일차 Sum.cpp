#include <iostream>
//#include <fstream>
#include <algorithm>

using namespace std;

int arr[101][101];


int main() {
	//ifstream input("input.txt");
	int testCase = 1;
	int maxValue, tempValue;
	int hi;
	while (testCase < 11) {
		cin >> hi;
		maxValue = 0;
		tempValue = 0;

		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				cin >> arr[i][j];
			}
		}
		// 배열 입력 완료

		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				tempValue += arr[i][j];
			}
			maxValue = max(maxValue, tempValue);
			tempValue = 0;
		}
		// 가로 덧셈 완료

		for (int j = 1; j <= 100; j++) {
			for (int i = 1; i <= 100; i++) {
				tempValue += arr[i][j];
			}
			maxValue = max(maxValue, tempValue);
			tempValue = 0;
		}
		// 세로 덧셈 완료
		for (int i = 1; i <= 100; i++) {
			tempValue += arr[i][i];
		}
		maxValue = max(maxValue, tempValue);
		tempValue = 0;
		//대각선 덧셈 완료
		int i, j;
		for ( i = 1, j = 100; i <= 100, j >= 1; i++, j--) {
			tempValue += arr[i][j];
		}
		maxValue = max(maxValue, tempValue);
		// 반대 대각선 덧셈 완료

		cout << "#" << testCase << "	" << maxValue << endl;
		testCase++;
	}
}
