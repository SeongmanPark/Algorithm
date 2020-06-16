#include <iostream>
//#include <fstream>
#include <cstring>

using namespace std;
int testCase, N, X, M, l, r, s;
int max_ham = -1;
// N : 햄스터 우리의 개수, X : 0~X마리의 햄스터, M : 추측 개수
int ham_house[7] = { 0, };
int answer[7];
int a = 1;

struct ham
{
	int l, r, s;
};

struct ham ham_info[11];

void init()
{
	a++;
	memset(ham_house, 0, sizeof(ham_house));
	memset(answer, 0, sizeof(answer));
	memset(ham_info, 0, sizeof(ham_info));
	max_ham = -1;
}

bool check()
{
	int sum;
	for (int i = 1; i <= M; i++)
	{
		sum = 0;
		for (int j = ham_info[i].l; j <= ham_info[i].r; j++)
		{
			sum += ham_house[j];
		}
		if (sum != ham_info[i].s)
			return false;
	}
	return true;
}

void MakeHam(int index, int sum)
{
	if (index == N+1)
	{
		if (check() && max_ham < sum)
		{
			max_ham = sum;
			for (int i = 1; i <= N; i++)
			{
				answer[i] = ham_house[i];
			}
		}
	}
	else
	{
		for (int i = 0; i <= X; i++)
		{
			ham_house[index] = i;
			MakeHam(index + 1, sum + i);
		}
	}


}

int main()
{
	//ifstream input("input.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> testCase;
	while (testCase-- > 0)
	{
		cin >> N >> X >> M;
		for (int i = 1; i <= M; i++)
		{
			cin >> ham_info[i].l >> ham_info[i].r >> ham_info[i].s;
		}
		
		MakeHam(1, 0);
		cout << "#" << a << " ";
		
		if (max_ham == -1)
		{
			cout << -1 << '\n';
		}
		else
		{
			for (int i = 1; i <= N; i++)
			{
				cout << answer[i] << " ";
			}
			cout << '\n';
		}

		init();

	}
}

// 가능한 햄스터 경우의 수를 구하고 체크해주면 됨!!
// 중복순열 못 짜서 레퍼런스 참고했다.
