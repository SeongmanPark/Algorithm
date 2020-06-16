#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> A;
vector<int> B;
bool visit[51] = { false };
int N, answer, num;

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("input.txt");
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		A.push_back(num);
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		B.push_back(num);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), cmp);
	for (int i = 0; i < N; i++)
	{
		answer += A[i] * B[i];
	}
	cout << answer << '\n';
}

// 두 벡터를 각각 정렬하고 곱해주면 끝.
