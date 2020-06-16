#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int decode[5][5][5];
int map[2001][2001];
int answer;
int testCase, N, M;

void init()
{
	memset(map, 0, sizeof(map));
	answer = 0;
}

void Setting()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 1; k <= 4; k++)
			{
				decode[i][j][k] = -1;
			}
		}
	}
	decode[2][1][1] = 0;
	decode[2][2][1] = 1;
	decode[1][2][2] = 2;
	decode[4][1][1] = 3;
	decode[1][3][2] = 4;
	decode[2][3][1] = 5;
	decode[1][1][4] = 6;
	decode[3][1][2] = 7;
	decode[2][1][3] = 8;
	decode[1][1][2] = 9;
}

void Solve()
{
	int solve_arr[8] = { 0 };
	int solve_arr_index = 7;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = M * 4; j >= 1 ; j--)
		{
			if (map[i][j] == 1 && map[i - 1][j] == 0)	// 중복된 암호 제거하기 !!
			{
				int temp_decode[3] = { 0 };
				while (map[i][j] == 1)
				{
					temp_decode[2]++;
					j--;
				}
				while (map[i][j] == 0)
				{
					temp_decode[1]++;
					j--;
				}
				while (map[i][j] == 1)
				{
					temp_decode[0]++;
					j--;
				}
				// 암호 count 완료

				int min = temp_decode[0];
				if (min > temp_decode[1]) min = temp_decode[1];
				if (min > temp_decode[2]) min = temp_decode[2];
				// 나눌 최솟값 구하기 완료 
				for (int k = 0; k < 3; k++) temp_decode[k] /= min;
				// 비율 구함

				solve_arr[solve_arr_index--] = decode[temp_decode[0]][temp_decode[1]][temp_decode[2]];

				if (solve_arr[solve_arr_index + 1] == -1)	// 잘못된 데이터면 ???
				{
					memset(solve_arr, 0, sizeof(solve_arr));
					solve_arr_index = 7;
					continue;
				}
				if (solve_arr_index == -1)	// 배열 꽉 채웠으면 ?
				{
					int value = 0;
					value = (solve_arr[0] + solve_arr[2] + solve_arr[4] + solve_arr[6]) * 3 + (solve_arr[1] + solve_arr[3] + solve_arr[5]) + solve_arr[7];
					if (value % 10 == 0)
					{
						answer += solve_arr[0] + solve_arr[2] + solve_arr[4] + solve_arr[6] + solve_arr[1] + solve_arr[3] + solve_arr[5] + solve_arr[7];
					}
					memset(solve_arr, 0, sizeof(solve_arr));
					solve_arr_index = 7;
				}
			}
		}
	}
}

int main()
{
	ifstream input("input.txt");
	char data;
	int a = 1;
	input >> testCase;

	while (testCase-- > 0)
	{
		input >> N >> M;
		
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M*4;)
			{
				input >> data;
				switch (data)
				{
					case '0': {
						map[i][j++] = 0; map[i][j++] = 0; map[i][j++] = 0; map[i][j++] = 0;
						break;
					}
					case '1': {
						map[i][j++] = 0; map[i][j++] = 0; map[i][j++] = 0; map[i][j++] = 1;
						break;
					}
					case '2' : {
						map[i][j++] = 0; map[i][j++] = 0; map[i][j++] = 1; map[i][j++] = 0;
						break;
					}
					case '3': {
						map[i][j++] = 0; map[i][j++] = 0; map[i][j++] = 1; map[i][j++] = 1;
						break;
					}
					case '4': {
						map[i][j++] = 0; map[i][j++] = 1; map[i][j++] = 0; map[i][j++] = 0;
						break;
					}
					case '5': {
						map[i][j++] = 0; map[i][j++] = 1; map[i][j++] = 0; map[i][j++] = 1;
						break;
					}
					case '6': {
						map[i][j++] = 0; map[i][j++] = 1; map[i][j++] = 1; map[i][j++] = 0;
						break;
					}
					case '7': {
						map[i][j++] = 0; map[i][j++] = 1; map[i][j++] = 1; map[i][j++] = 1;
						break;
					}
					case '8': {
						map[i][j++] = 1; map[i][j++] = 0; map[i][j++] = 0; map[i][j++] = 0;
						break;
					}
					case '9': {
						map[i][j++] = 1; map[i][j++] = 0; map[i][j++] = 0; map[i][j++] = 1;
						break;
					}
					case 'A': {
						map[i][j++] = 1; map[i][j++] = 0; map[i][j++] = 1; map[i][j++] = 0;
						break;
					}
					case 'B': {
						map[i][j++] = 1; map[i][j++] = 0; map[i][j++] = 1; map[i][j++] = 1;
						break;
					}
					case 'C': {
						map[i][j++] = 1; map[i][j++] = 1; map[i][j++] = 0; map[i][j++] = 0;
						break;
					}
					case 'D': {
						map[i][j++] = 1; map[i][j++] = 1; map[i][j++] = 0; map[i][j++] = 1;
						break;
					}
					case 'E': {
						map[i][j++] = 1; map[i][j++] = 1; map[i][j++] = 1; map[i][j++] = 0;
						break;
					}
					case 'F': {
						map[i][j++] = 1; map[i][j++] = 1; map[i][j++] = 1; map[i][j++] = 1;
						break;
					}
				}
			}
		}
		// 입력 완료
		Setting();
		// decode 세팅 완료
		Solve();
		// 구현
		cout << "#" << a << " "<< answer << '\n';
		a++;
		init();
	}	
}
// 어렵다. 이전단계 문제를 풀었을때 보다 암호의 scale이 커져서 처리하는 방법이 까다로웠다. 여러모로 많은 생각을 하게 만드는 문제이다.
