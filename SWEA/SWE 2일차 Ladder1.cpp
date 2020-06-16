#include <iostream>
//#include <fstream>
#include <algorithm>

using namespace std;

int arr[101][101];


int main() {
	//ifstream input("input.txt");
	int testCaseNum;
	int testCase = 1;

	while (testCase < 11) {
		cin >> testCaseNum;
		
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				cin >> arr[i][j];
			}
		}
		// 사다리 입력 완료

		for (int j = 1; j <= 100; j++) {
			int i = 1;
			if (arr[i][j] == 0)
				continue;
			// 0에서 출발 못하므로 continue
			int temp_j = j;
			int travel_j = j;
			// i = 1, j번째 열에서 출발
			while (1) {
				if (i == 100) break;

				if (travel_j - 1 != 0 && arr[i][travel_j - 1] == 1) {
					while (travel_j -1>= 1 && arr[i][travel_j - 1] == 1) {
						travel_j--;
					}
				}
				// 왼쪽 길이 있는 경우
				else if (travel_j + 1 <= 100 && arr[i][travel_j + 1] == 1) {
					while (travel_j +1 != 101 && arr[i][travel_j + 1] == 1) {
						travel_j++;
					}
				}
				// 오른 길이 있는 경우
				
				// 아무 길이 없는 경우
				i++;
			}
			// i==100 때 탈출
			if (arr[i][travel_j] == 2) {
				cout << "#"<<testCase <<" "<<temp_j - 1 << endl;
			}
		}
		
		testCase++;


	}
}
