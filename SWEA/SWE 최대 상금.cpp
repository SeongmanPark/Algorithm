#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int score[7];
int N, testCase;
int answer;
bool visit[1000000][11] = { false };

void init()
{
	answer = 0;
	memset(score, 0, sizeof(score));
	memset(visit, 0, sizeof(visit));
}

void dfs(int depth, int left_index, int right_index, int score[], int index)
{
	int temp_arr[7] = { 0 };
	for (int i = 1; i <= index; i++)
	{
		temp_arr[i] = score[i];
	}

	// 값 복사 후
	int temp = temp_arr[left_index];
	temp_arr[left_index] = temp_arr[right_index];
	temp_arr[right_index] = temp;
	// swap

	int value = 0;
	int digit = 1;
	for (int i = index; i >= 1; i--)
	{
		value += temp_arr[i] * digit;
		digit *= 10;
	}

	if (visit[value][depth]) return;
	else visit[value][depth] = true;
	
	if (depth == N)
	{	
		
		if (answer < value)
		{
			answer = value;
			visit[answer][depth] = true;
		}
		return;
	}
	
	for (int i = 1; i <= index - 1; i++)
	{
		for (int j = i+1; j <= index; j++)
		{
			dfs(++depth, i, j, temp_arr, index);
			depth--;
		}
	}

}

int main()
{
	ifstream input("input.txt");
	string data;
	int a = 1;
	// score 배열의 크기
	input >> testCase;
	while (testCase-- > 0)
	{
		input >> data >> N;
		int index = 1;
		for (int i = 0; i < data.size(); i++)
		{
			score[index] = data[i] - '0';
			index++;
		}
		// 입력 완료 !!!!
		index--;
		int depth = 0;

		for (int i = 1; i <= index-1; i++)
		{
			for (int j = i + 1; j <= index; j++)
			{
				dfs(++depth, i, j, score, index);
				depth--;
			}
		}
		cout <<"#" << a << " " << answer << '\n';
		a++;
		init();
	}
}

// 가지치기 잘 생각하기, 결과를 계산하는 과정에서 나온 중간값으로도 가지치기를 할 수 있다.
// visit[answer][depth] -> 가지치기
