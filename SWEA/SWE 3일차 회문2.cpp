#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX 100
using namespace std;
char arr[101][101];

int main() {
	ifstream input("input.txt");
	int testCase = 10;
	int rowFindLength = 100;
	int colonFindLength = 100;
	char inputChar;
	int n;

	while (testCase > 0) {
		input >> n;
		for (int i = 1; i <= MAX; i++) for (int j = 1; j <= MAX; j++) input >> arr[i][j];
		// 배열 입력 완료

		while (rowFindLength > 0) {
			int flag;
			for (int i = 1; i <= MAX; i++) {
				for (int j = 1; j <= MAX - rowFindLength + 1; j++) {
					// 기준점 설정 완료
					flag = 1;
					int start = 0;
					int end = rowFindLength - 1;

					while (start < end) {	// 비교
						if (arr[i][j + start] != arr[i][j + end]) {
							flag = 0;
							break;
						}
						start++;
						end--;
					}
					if (flag == 1) break;
				}
				if (flag == 1) break;
			}
			if (flag == 1) break;
			rowFindLength--;
		}

		while (colonFindLength > 0) {
			int flag;

			for (int j = 1; j <= MAX; j++) {
				for (int i = 1; i <= MAX - colonFindLength + 1; i++) {
					flag = 1;
					int start = 0;
					int end = colonFindLength - 1;

					while (start < end) {
						if (arr[i + start][j] != arr[i + end][j]) {
							flag = 0;
							break;
						}
						start++;
						end--;
					}
					if (flag == 1) break;
				}
				if (flag == 1) break;
			}
			if (flag == 1) break;
			colonFindLength--;
		}

		cout << "#" << n << " " << max(rowFindLength, colonFindLength) << endl;
		rowFindLength = colonFindLength = 100;

		testCase--;
	}
	// 큰 testCase while문
	return 0;
}
// 회문1가 비슷한 문제이지만 최대 문자열의 길이를 구하는 문제이다. 배열의 인덱스가 100이기 때문에 100부터 차례대로 비교해서 가장 큰 문자열이 구해지면 바로 stop하고 출력해주면 된다.
