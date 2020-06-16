#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string inputCode;
string searchCode;
int isCode, endIndex, startIndex;
string decode[10] = {
	{"0001101"},
	{"0011001"},
	{"0010011"},
	{"0111101"},
	{"0100011"},
	{"0110001"},
	{"0101111"},
	{"0111011"},
	{"0110111"},
	{"0001011"}
};

vector<int> v;

void init()
{
	v.clear();
	isCode = endIndex = startIndex = 0;
	inputCode = searchCode = "";
}

int main()
{
	ifstream input("input.txt");
	int testCase, N, M;
	int a = 1;
	input >> testCase;
	while (testCase-- > 0)
	{
		input >> N >> M;
		for (int i = 1; i <= N; i++) {
			input >> inputCode;
			for (int j = 0; j < inputCode.size(); j++)
			{
				if (inputCode[j] == '1')
				{
					searchCode = inputCode;
				}
			}
		}
		// 입력 완료 !!
		
		for (int i = searchCode.size(); i >= 0; i--)
		{
			if (searchCode[i] == '1')
			{
				endIndex = i;
				startIndex = i - 55;
				break;
			}
		}
		// endIndex 찾기 완료
		for (int i = startIndex; i <= endIndex; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				int k = 0;
				bool flag = false;
				while (1)
				{
					if (searchCode[i + k] != decode[j][k])
					{
						break;
					}

					if (k == 6)
					{
						v.push_back(j);
						i += 6;
						flag = true;
						break;
					}
					
					k++;
				}
				if (flag) break;
			}
		}
		// 해독 완료 이제 검사하기
		
		isCode = (v[0] + v[2] + v[4] + v[6]) * 3 + v[1] + v[3] + v[5] + v[7];
		if (isCode % 10 != 0) isCode = 0;
		else isCode = v[0] + v[2] + v[4] + v[6] + v[1] + v[3] + v[5] + v[7];

		cout << "#" << a << " " << isCode << '\n';
		a++;
		init();
	}
}

// 하라는 대로 하면 된다. 쉬운 문제. 암호 해독을 할 때 뒤에서부터 '1'을 찾는게 
