#include <iostream>
//#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[101] = { 0 };



int main() {
	//ifstream input("input.txt");
	int testCase, dump, boxHeight, bigBoxNumber, smallBoxNumber;
	testCase = 1;
	while (testCase < 11) {
		cin >> dump;
		for (int i = 1; i <= 100; i++) {
			cin >> boxHeight;
			arr[boxHeight]++;
		}
		// 박스의 높이를 배열에 다 입력받음.

		for (int i = 0; i < dump; i++) {

			for (int j = 100;; j--) {
				if (arr[j] != 0) {
					arr[j]--;
					arr[j - 1]++;
					break;
				}
			}
			// 가장 큰 높이의 박스 하나 지우기

			for (int k = 1;; k++) {	
				if (arr[k] != 0) {
					arr[k]--;
					arr[k + 1]++;
					break;
				}
			}
			// 가장 낮은 높이의 박스 하나 지우고 그 다음 큰 박스 하나 늘리기
		}
		
		// dump 끝

		for (int i = 1 ; i <= 100 ; i++) {
			if (arr[i] != 0) {
				smallBoxNumber = i;
				break;
			}
		}
		for (int i = 100; i > 0 ; i--) {
			if (arr[i] != 0) {
				bigBoxNumber = i;
				break;
			}
		}
		// dump 후 큰 박스, 작은 박스 높이 구하기

		cout << "#" << testCase << " " << bigBoxNumber - smallBoxNumber << endl;
		testCase++;
		for (int i = 1; i <= 100; i++) {
			arr[i] = 0;
		}
	}

}
