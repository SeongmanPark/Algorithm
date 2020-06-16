#include <iostream>
#include <algorithm>
#include <string>
//#include <fstream>
using namespace std;

string searchString, inputString;

int main() {
	//ifstream input("input.txt");

	int testCase = 10;
	int n;

	while (testCase-- > 0) {
		cin >> n;
		cin >> searchString >> inputString;
		
		register int searchSize = searchString.length();
		register int inputStringSize = inputString.length();
		//	각각 문자열의 길이를 저장.
		int stringCount = 0;
		for (int i = 0; i < inputStringSize; i++) {
			if (inputString[i] == searchString[0]) {	// 첫 단어가 같으면 비교 시작.
				register int new_i = i;
				for (int j = 1; j < searchSize; j++) {
					new_i++;
					if (inputString[new_i] != searchString[j]) {
						break;
					}
					if (j == searchSize - 1) {
						stringCount++;
					}

				}
			}
		}
		// 비교 끝

		printf("#%d %d\n", n, stringCount);
		stringCount = 0;
	}

}
// 쉬운 문제, 간단하게 풀었다.
