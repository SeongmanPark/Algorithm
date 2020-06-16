#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

string PostFix(string inputString, int inputStringLength) 
{
	stack <char> s;
	string postFixString = "";
	for (int i = 0; i < inputStringLength; i++) 
	{
		char ch = inputString[i];
		switch (ch) 
		{
			case '(':
			{
				s.push(inputString[i]);
				break;
			}

			case ')':
			{
				while (s.top() != '(') 
				{
					char temp = s.top();
					postFixString += temp;
					s.pop();
				}
				s.pop();	// '(' pop
				break;
			}

			case '+':
			{
				if (s.empty())
				{
					s.push(inputString[i]);
					break;
				}
				
				else if(!s.empty())	// 스택이 비어있지 않으면 ?
				{
					if (s.top() == '*' || s.top() == '+')	// top의 우선순위가 token보다 높다면 ?
					{	
						while (s.top() == '+' || s.top() == '*') {
							char temp = s.top();
							postFixString += temp;
							s.pop();
							if (s.empty()) break;
						}
						s.push(inputString[i]);
						break;
					}
					else	// top = (
					{
						s.push(inputString[i]);
						break;
					}
				}
			}

			case '*':
			{
				if (s.empty())
				{
					s.push(inputString[i]);
					break;
				}
				else if (!s.empty())
				{
					if (s.top() == '*')
					{
						while (s.top() == '*')
						{
							char temp = s.top();
							postFixString += temp;
							s.pop();
							if (s.empty()) break;
						}
						s.push(inputString[i]);
						break;
					}
					else
					{
						s.push(inputString[i]);
						break;
					}
				}
			}

			default :
			{
				postFixString += inputString[i];
				break;
			}

		}
	}
	while (!s.empty()) 
	{
		char temp = s.top();
		postFixString += temp;
		s.pop();
	}

	return postFixString;

}

int ComputedPostFix(string postFixString) 
{
	stack <int> s;
	int left, right, answer;
	int postFixStringLength = postFixString.length();
	for (int i = 0; i < postFixStringLength; i++) 
	{
		char ch = postFixString[i];
		switch (ch)
		{
			case '+':
			{
				left = s.top();
				s.pop();
				right = s.top();
				s.pop();
				answer = right + left;
				s.push(answer);
				break;
			}
			case '*':
			{
				left = s.top();
				s.pop();
				right = s.top();
				s.pop();
				answer = right * left;
				s.push(answer);
				break;
			}
			default :
			{
				s.push(ch-'0');
				break;
			}
		}
	}
	return s.top();
}

int main() {
	ifstream input("input.txt");
	int testCase = 10;
	int n = 1;
	int inputStringLength;
	int answer;
	string inputString;
	string postFixString;
	while (testCase > 0) 
	{
		input >> inputStringLength >> inputString;
		postFixString = PostFix(inputString, inputStringLength);
		answer = ComputedPostFix(postFixString);
		cout << postFixString << endl;
		cout << "#" << n << " " << answer << endl;
		n++;
		testCase--;

	}
}
// 후위표기식을 확인하는 과정에서, 구글링해서 얻은 소스와 결과값이 달라서 헤맸지만 결국 내 코드가 맞았다......
