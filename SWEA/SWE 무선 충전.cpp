#include <iostream>
#include <fstream>
#include <queue>
#define ABS(A,B) (A>B ? A-B:B-A)
#define MAX(A,B) (A>B ? A:B)
using namespace std;
int testCase, M, A;
// M : 이동시간
// A : 배터리 개수
int map[11][11];
int move_A[101];
int move_B[101];
int dx[] = { 0, -1, 0, 1, 0 };
int dy[] = { 0, 0, 1, 0, -1 };
bool choice[9];
//초기, 상 우 하 좌
int answer;
int a = 1;

typedef struct
{
	int cur_x, cur_y, dist, power, index;
}Battery;

typedef struct
{
	int cur_x, cur_y;
}User;

Battery Ba[9];
User UA;
User UB;

void init()
{
	a++;
	answer = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("input.txt");
	cin >> testCase;
	while (testCase-- > 0)
	{
		cin >> M >> A;
		for (int i = 1; i <= M; i++) cin >> move_A[i];
		for (int i = 1; i <= M; i++) cin >> move_B[i];
		for (int i = 1; i <= A; i++)
		{
			cin >> Ba[i].cur_y >> Ba[i].cur_x >> Ba[i].dist >> Ba[i].power;
			Ba[i].index = i;
		}
		// 입력완료 !!!!!
		UA.cur_x = 1; UA.cur_y = 1;
		UB.cur_x = 10; UB.cur_y = 10;
		// 출발지 설정 !!

		for (int i = 0; i <= M; i++)
		{
			// 1. 이동한 좌표 구하기
			UA.cur_x = UA.cur_x + dx[move_A[i]];
			UA.cur_y = UA.cur_y + dy[move_A[i]];
			UB.cur_x = UB.cur_x + dx[move_B[i]];
			UB.cur_y = UB.cur_y + dy[move_B[i]];
			// 2. 맨허턴 거리 이용해서 기지국 벡터에 넣어주기
			vector<int> vA;
			vector<int> vB;
			for (int j = 1; j <= A; j++)
			{
				if (Ba[j].dist >= ABS(Ba[j].cur_x, UA.cur_x) + ABS(Ba[j].cur_y, UA.cur_y))
				{
					vA.push_back(j);
				}
				if (Ba[j].dist >= ABS(Ba[j].cur_x, UB.cur_x) + ABS(Ba[j].cur_y, UB.cur_y))
				{
					vB.push_back(j);
				}
			}
			// 벡터에 거리가 되는 기지국 넣었음 !!! vector
			// 최대 충전량 구하기 -> 순열
			int total = 0; // 마지막으로 크기 비교할 total 변수 !!
			int total_1 = 0; // vA가 먼저인 for문 중 최대 충전량
			int total_2 = 0; // vB가 먼저인 for문 중 최대 충전량
			int temp_1 = 0;
			int temp_2 = 0;
			// 기지국 선택해서 최대값 구하는거, 
			// A B 기지국 선택 완료 !!
			for (int i = 0; i < vA.size(); i++)
			{
				temp_1 = Ba[vA[i]].power;
				total_1 = MAX(temp_1, total_1);
				choice[vA[i]] = true;
				for (int j = 0; j < vB.size(); j++)
				{
					if(!choice[vB[j]])
					{
						total_1 = MAX(temp_1 + Ba[vB[j]].power, total_1);
					}
				}
				choice[vA[i]] = false;
			}
			for (int i = 0; i < vB.size(); i++)
			{
				temp_2 = Ba[vB[i]].power;
				total_2 = MAX(temp_2, total_2);
				choice[vB[i]] = true;
				for (int j = 0; j < vA.size(); j++)
				{
					if(!choice[vA[j]])
					{
						total_2 = MAX(temp_2 + Ba[vA[j]].power, total_2);
					}
				}
				choice[vB[i]] = false;
			}
			// 충전량 최대값 구하는 부분 !!
			total = MAX(total_1, total_2);
			answer += total;
		}
		cout << "#" << a << " " << answer << '\n';
		init();
	}
	return 0;
}

// 두 벡터에서의 최대 충전량을 구하는 부분에서 시간을 꽤나 쏟았다.
// 처음 그리디한 방법으로 접근했지만 예외를 찾지 못해서 순열로 구하였다.
