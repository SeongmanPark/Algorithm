#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream input("input.txt");


	int testCase = 10;
	int n = 1;
	while (testCase-- > 0)
	{
		string s;
		int vertexSize, leftChild, rightChild, vertex;
		bool flag = true;
		input >> vertexSize;
		for (int i = 1; i <= vertexSize; i++)
		{
			if (vertexSize % 2 == 0)	// 전체 노드가 짝수개인 경우 ?
			{
				input >> vertex >> s;
				if (i < vertexSize / 2)	// leafnode가 아님, 연산자여야 함, 자식 2개
				{
					if (s == "+" || s == "-" || s == "*" || s == "/")
					{
						input >> leftChild >> rightChild;
					}
					else
					{
						flag = false;
						input >> leftChild >> rightChild;
					}
				}
				else if (i > vertexSize / 2)	// leafnode임, 숫자가 와야함
				{
					if (s == "+" || s == "-" || s == "*" || s == "/")
					{
						flag = false;
					}
				}
				else if (i == vertexSize / 2) // leafnode가 아님, 연산자여야 함, 자식 1개
				{
					if (s == "+" || s == "-" || s == "*" || s == "/")
					{
						input >> leftChild;
					}
					else
					{
						flag = false;
						input >> leftChild;
					}
				}
			}
			else if (vertexSize % 2 == 1)	// 전체 노드가 홀수개인 경우 ?
			{
				input >> vertex >> s;
				if (i <= vertexSize / 2)	// leafnode가 아님, 연산자여야 함, 자식 2개
				{
					if (s == "+" || s == "-" || s == "*" || s == "/")
					{
						input >> leftChild >> rightChild;
					}
					else
					{
						flag = false;
						input >> leftChild >> rightChild;
					}
				}
				else if (i > vertexSize / 2)	// leafnode임, 숫자가 와야함
				{
					if (s == "+" || s == "-" || s == "*" || s == "/")
					{
						flag = false;
					}
				}
			}
		}
		cout << "#" << n << " ";
		n++;
		if (flag) cout << 1 << endl;
		else cout << 0 << endl;
	}
	

}
// if else문 조건 범위 잘 지정하기, 처음에 짤 때 제대로 짜기
