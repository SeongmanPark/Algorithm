#include <iostream>
//#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int testCase, N, K;
string input, temp;
vector<int> v;
int a = 1;

bool cmp(const int a, const int b)
{
	return a > b;
}

void init()
{
	a++;
	v.clear();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");
	cin >> testCase;
	while (testCase-- > 0)
	{
		cin >> N >> K >> input;
		// 입력 완료
		for (int i = 0; i < N / 4; i++)
		{
			input += input[i];
			// concatination
		}

		int cnt = 0;
		long long sum = 0;
		long long hex = 1;
		temp = "";
		for (int start = 0; start < N / 4; start++)
		{
			temp = "";
			cnt = 0;
			for (int i = start; i < input.length(); i++)
			{
				cnt++;
				temp += input[i];
				if (cnt == N / 4) // N/4개 16진수 만들었으니 10진수로 변환해서 벡터에 넣기
				{
					sum = 0;
					hex = 1;
					for (int j = 1; j < N / 4; j++)
						hex *= 16;
					for (int j = 0; j < N / 4; j++)
					{

						if (temp[j] >= 'A')
						{
							sum += (temp[j] - 'A' + 10) * hex;
						}
						else
						{
							sum += (temp[j] - '0') * hex;
						}
						hex /= 16;
					}
					v.push_back(sum);
					cnt = 0;
					temp = "";
				}
			}
		}
		sort(v.begin(), v.end(), cmp);
		// 벡터 내림차순 정렬
		int max_num = 1;
		int dup = v[0];
		for (int i = 0; i < v.size(); i++)
		{
			if (dup > v[i])
			{
				dup = v[i];
				max_num++;
			}
			if (max_num == K)
			{
				cout << "#" << a << " " << dup << '\n';
				break;
			}
		}
		init();
	}
}

// 시뮬레이션 + 아이디어(concatination)
