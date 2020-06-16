#include <iostream>
//#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#define MIN(A,B) (A<B ? A:B)
#define ABS(A,B) (A>B ? A-B:B-A)
bool chicken_visit[14] = { false };
int map[51][51];
int N, M, chicken_count, house_count;
int answer = 0x7FFFFFFF;



vector<pair<int, int>> chicken;
vector<pair<int, int>> person;

void calculate_distance()
{

	int temp_answer = 0;

	for (int i = 0; i < person.size(); i++)
	{
		int temp_distance = 0x7FFFFFFF;
		for (int j = 0; j < chicken.size(); j++)
		{
			if (!chicken_visit[j]) continue;
			temp_distance = MIN(ABS(chicken[j].first, person[i].first) + ABS(chicken[j].second, person[i].second), temp_distance);
		}
		temp_answer += temp_distance;
		if (temp_answer >= answer)
			return;
	}
	answer = MIN(temp_answer, answer);
}

void choice_chicken(int index, int depth)
{
	if (depth == M)
	{
		calculate_distance();
		return;
	}
	
	for (int i = index ; i < chicken.size(); i++)
	{
		if (chicken_visit[i]) continue;
		chicken_visit[i] = true;
		choice_chicken(i + 1 , depth + 1);
		chicken_visit[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("input.txt");

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				chicken.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 1)
			{
				person.push_back(make_pair(i, j));
			}
		}
	}


	// 입력 완료

	choice_chicken(0, 0);
	cout << answer << '\n';
	return 0;
}

// 조합 알고리즘 구현을 실수해서 하루를 날린 문제이다.
// 재귀 함수를 호출할 때 인자를 잘 보고 실수하지 말자.
