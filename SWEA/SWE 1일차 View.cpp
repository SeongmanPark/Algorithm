#include <iostream>
//#include <fstream>
#include <algorithm>

using namespace std;
int arr[1001] = { 0 };



int main() {
	//ifstream input("input.txt");
	int bulidingLength, bulidingHeight, viewCount, temp;
	int testCase = 1;
	while (testCase < 11) {
		cin >> bulidingLength;
		viewCount = 0;

		for (int i = 1; i <= bulidingLength; i++) {
			cin >> bulidingHeight;
			arr[i] = bulidingHeight;
		}
		// 빌딩 정보 입력 완료 !!

		for (int i = 3; i <= bulidingLength - 2; i++) {
			
			if (arr[i] <= arr[i - 2] || arr[i] <= arr[i + 2] || arr[i] <= arr[i - 1] || arr[i] <= arr[i + 1]) {
				continue;
			}
			// 양 옆, 옆옆 중 큰 빌딩이 있다면 continue

			// 여기서 부터 가운에 양 옆으로 내가 젤 큼.
			temp = arr[i] - arr[i - 2];
			temp = min(temp, arr[i] - arr[i - 1]);
			temp = min(temp, arr[i] - arr[i + 1]);
			temp = min(temp, arr[i] - arr[i + 2]);
			viewCount += temp;
		}

		cout << "#" << testCase << "	" << viewCount << endl;
		testCase++;
		for (int i = 1; i <= bulidingLength; i++) {
			arr[i] = 0;
		}
	}
}
