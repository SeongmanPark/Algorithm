#include <iostream>
//#include <fstream>
#include <cstring>

using namespace std;
#define MIN(a,b) (a<b ? a:b)

int testCase, target;
int digit[10];
int a = 1;
int total_number[1000001] = { 0 };
int answer = 1000000;

void init()
{
	a++;
	memset(digit, 0, sizeof(digit));
	memset(total_number, 0, sizeof(total_number));
	answer = 1000000;
}

void dfs(int target ,int cnt)
{
	if (target == 1)
	{
		answer = MIN(cnt, answer);
	}
	if (cnt >= answer)
		return;

	for (int i = target; i > 1; i--)
	{
		if (total_number[i])
		{
			if (target % i == 0)
			{
				dfs(target / i ,cnt + total_number[i] + 1);
			}
		}
	}
}

void MakeNumber(int push_count, int number)
{
	if (push_count > 7)
		return;
	if (number > target)
		return;

	if(push_count>0) 
		total_number[number] = push_count;

	for (int i = 0; i < 10; i++)
	{
		if (digit[i])
		{
			MakeNumber(push_count +1, number * 10 + i);
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
		for (int i = 0; i < 10; i++)
		{
			cin >> digit[i];
		}

		cin >> target;
        if(target == 1 &&  digit[1])
        {
            cout << "#" << a << " " << 2 << '\n';
            init();
            continue;
        }
		MakeNumber(0, 0);
		dfs(target ,0);
		if (answer == 1000000) answer = -1;
		cout << "#" << a << " " << answer << '\n';
		init();
	}
}

// makeNumber 부분에서 애를먹었다. 부분집합을 구해서 push_count 만큼 표시해줘야하는데 digit[0]이 true경우
// 처리해주는데 어려움을 겪고 레퍼런스를 참고하였다. 
