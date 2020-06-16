#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	queue<int> Q;
	ifstream input("input.txt");
	int testCase = 1;
	int n, data;
	while (testCase-- > 0)
	{
		input >> n;
		for (int i = 0; i < 8; i++)
		{
			input >> data;
			Q.push(data);
		}
		while (1)
		{
			bool flag = false;
			register int temp;
			for (int i = 1; i <= 5; i++)
			{
				temp = Q.front();
				Q.pop();
				temp -= i;
				if (temp > 0)
				{
					Q.push(temp);
				}
				else
				{
					Q.push(0);
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		while (!Q.empty())
		{
			cout << Q.front() << " ";
			Q.pop();
		}
		cout << endl;
	}
}
// Queue를 이용한 간단한 문제 !
