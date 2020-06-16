#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;
int testCase = 10;
stack <char> s1;
stack <char> s2;
int n = 1;
int main() {
	ifstream input("input.txt");
	string inputString;
	int inputStringLength;
	while (testCase > 0) {
		input >> inputStringLength >> inputString;
		s1.push(inputString[0]);
		for (int i = 1; i < inputStringLength; i++) {
			if (s1.empty()) {
				s1.push(inputString[i]);
				continue;
			}
			if (inputString[i] == s1.top()) {
				s1.pop();
			}
			else {
				s1.push(inputString[i]);
			}
		}
		while (!s1.empty()) {
			char c = s1.top();
			s2.push(c);
			s1.pop();
		}
		cout << "#" << n << " ";
		while (!s2.empty()) {
			cout << s2.top();
			s2.pop();
		}
		cout << endl;
		n++;
		testCase--;
	}
}
// for문 도중 스택이 비었을때 예외처리를 생각 못했던 문제, 테스트 해보면서 고쳤다.
