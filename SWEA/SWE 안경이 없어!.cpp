#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

bool Classify(char a, char b)
{
	int left, right;
	if (a == 'B')
	{
		left = 3;
	}
	else if (a == 'A' || a == 'D' || a == 'O' || a == 'P' || a == 'Q' || a == 'R')
	{
		left = 2;
	}
	else {
		left = 1;
	}

	if (b == 'B')
	{
		right = 3;
	}
	else if (b == 'A' || b == 'D' || b == 'O' || b == 'P' || b == 'Q' || b == 'R')
	{
		right = 2;
	}
	else {
		right = 1;
	}

	if (left == right) return true;
	else return false;
}

int main()
{
	//ifstream input("input.txt");
	string left, right;
	int testCase;
	int a = 1;
	cin >> testCase;
	
	while (testCase-- > 0)
	{
		cout << "#" << a << " ";
		a++;
		cin >> left >> right;
		int leftLength = left.size();
		int rightLength = right.size();

		if (leftLength != rightLength)
		{
			cout << "DIFF" << '\n';
			continue;
		}
		//ADOPQR
		//B
		bool flag = true;
		for (int i = 0; i < rightLength; i++)
		{
			if (!Classify(left[i], right[i])) flag = false;
		}

		if (flag) cout << "SAME" << '\n';
		else cout << "DIFF" << '\n';
		
	}
	
}
