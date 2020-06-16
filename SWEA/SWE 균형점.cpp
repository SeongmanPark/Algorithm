#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int testCase, N;

double x[11];
double w[11];
int depth = 0;
bool find_middle = false;
double middle_x;
double answer;

void init()
{
	depth = 0;
	find_middle = false;
	answer = 0;
}

void Solve(int target, double middle_x, double start, double end)
{

	if (find_middle)
	{
		return;
	}

	long double sum_left_power = 0;
	long double sum_right_power = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i <= target)
		{
			sum_left_power = sum_left_power + w[i] / ((middle_x - x[i]) * (middle_x - x[i]));
		}
		// 왼쪽 애들의 인력 합
		else if (i > target)
		{
			sum_right_power = sum_right_power + w[i] / ((middle_x - x[i]) * (middle_x - x[i]));
		}
		// 오른쪽 애들의 인력 합
	}

	if (sum_left_power > sum_right_power)    // 왼쪽이 파워가 더 쎄면 ?
	{
		double new_start = middle_x;
		long double new_middle = (new_start + end) / 2;
		if (fabs(new_middle - middle_x) < 1e-12)
		{
			find_middle = true;
			answer = new_middle;
			return;
		}
		middle_x = new_start + end;
		middle_x /= 2;
		depth++;
		Solve(target, middle_x, new_start, end);
	}
	else if (sum_left_power < sum_right_power)
	{
		double new_end = middle_x;
		long double new_middle = (start + new_end) / 2;
		if (fabs(new_middle - middle_x) < 1e-12)
		{
			find_middle = true;
			answer = new_middle;
			return;
		}
		middle_x = start + new_end;
		middle_x /= 2;
		depth++;
		Solve(target, middle_x, start, new_end);
	}
	else if (sum_left_power == sum_right_power)
	{
		find_middle = true;
		answer = middle_x;
	}
}

int main()
{
	ifstream input("input.txt");
	int a = 1;
	input >> testCase;
	while (testCase-- > 0)
	{
		input >> N;
		for (int i = 1; i <= N; i++)
		{
			input >> x[i];
		}
		// x좌표 다 입력
		for (int i = 1; i <= N; i++)
		{
			input >> w[i];
		}
		// 무게 다 입력
		cout << "#" << a << " ";
		a++;
		for (int i = 1; i < N; i++)
		{
			middle_x = x[i] + x[i + 1];
			middle_x /= 2;
			Solve(i, middle_x, x[i], x[i + 1]);
			cout << fixed;
			cout.precision(10);
			cout << answer << " ";
			init();
		}
		cout << '\n';
	}
}

// 재귀를 이용해서, middle_x의 값과 오차를 비교해나갔다.
// 연산자 우선순위 신경쓰기, 삽질을 너무 많이 했다. 
