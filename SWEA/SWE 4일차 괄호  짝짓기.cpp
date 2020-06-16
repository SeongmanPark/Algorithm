#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main() {
	ifstream input("input.txt");
	string inputString;
	int testCase = 10;
	int n = 1;
	int k;
	while(testCase >0){
		input >> k;
		input >> inputString;
		bool flag = true;
		int inputStringLength = inputString.length();
		stack <char> s;
		for (int i = 0; i < inputStringLength; i++) {
			if (inputString[i] == '(' || inputString[i] == '[' || inputString[i] == '{' || inputString[i] == '<') {
				s.push(inputString[i]);
			}
			else {
				char temp = s.top();
				if (inputString[i] == ']' && temp != '[') {
					flag = false;
					break;
				}
				else if (inputString[i] == '}' && temp != '{') {
					flag = false;
					break;
				}
				else if (inputString[i] == '>' && temp != '<') {
					flag = false;
					break;
				}
				else if (inputString[i] == ')' && temp != '(') {
					flag = false;
					break;
				}
				else {
					s.pop();
				}
			}
		}
		if (flag) {
			cout << "#" << n << " " << 1 << endl;
		}
		else cout << "#" << n << " " << 0 << endl;

		testCase--;
		n++;
	}

}

// map과 stack를 쓰려고 했지만 if/else 문으로 간단히 풀리는 문제.
