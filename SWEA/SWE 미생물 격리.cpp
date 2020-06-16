#include <iostream>
#include <fstream>
using namespace std;


int N, M, K;
int arr[100][100][2];	// 0은 미생물 수, 1은 구조체 번호
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };    // 상 하 좌 우
struct Node
{
    int currentX, currentY;
    int dir, bugs;
}p[1001];


int main()
{
	ifstream input("input.txt");
	int testCase;
	input >> testCase;
	int n = 1;
	while (testCase-- > 0)
	{
        input >> N >> M >> K;
        for (int i = 0; i < K; i++)
        {
            int x, y, n, d;
            input >> x >> y >> n >> d;
            p[i].currentX = x;
            p[i].currentY = y;
            p[i].bugs = n;
            p[i].dir = d;
        }
        // 미생물 방향정보 다 입력
        while(M-->0)
        {
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					for (int l = 0; l < 2; l++)
					{
						arr[i][j][l] = 0;
					}
				}
			}
			// 저장배열 초기화
			
			for (int i = 0; i < K; i++)
            {
                    int new_x, new_y;
					new_x = p[i].currentX + dx[p[i].dir - 1];
					new_y = p[i].currentY + dy[p[i].dir - 1];
                    if (p[i].bugs == 0) continue;

                        if (new_x == 0 || new_x == N - 1 || new_y == 0 || new_y == N - 1)   // 벽에 부딪힌 경우
                        {
                            p[i].bugs /= 2;
                            if (p[i].dir == 1) p[i].dir = 2;
                            else if (p[i].dir == 2) p[i].dir = 1;
                            else if (p[i].dir == 3) p[i].dir = 4;
                            else if (p[i].dir == 4) p[i].dir = 3;
                            arr[new_x][new_y][0] = p[i].bugs;
							arr[new_x][new_y][1] = i;
							p[i].currentX = new_x;
							p[i].currentY = new_y;
                        }

                        else    // 벽이 아니고
                        {
                            if (arr[new_x][new_y][0] == 0) // 누군가 없다.
                            {
                                p[i].currentX = new_x;
                                p[i].currentY = new_y;
                                arr[new_x][new_y][0] = p[i].bugs;	// 대표 미생물 군집 수
								arr[new_x][new_y][1] = i;	// 대표 구조체 번호
                            }
                            else		// 누군가있을때 ?
                            {
                                if (p[i].bugs > arr[new_x][new_y][0])  // 내가 더 큰경우 바꿔줘야지
                                {
									arr[new_x][new_y][0] = p[i].bugs;
									p[i].bugs += p[arr[new_x][new_y][1]].bugs;
									p[arr[new_x][new_y][1]].bugs = 0;
									arr[new_x][new_y][1] = i;
									p[i].currentX = new_x;
									p[i].currentY = new_y;
                                }
                                else        // 내가 작은 경우
                                {
									p[arr[new_x][new_y][1]].bugs += p[i].bugs;
									p[i].bugs = 0;
                                }
                            }
                       
                        }

            }
            
            /*for (int i = 0; i < K; i++)
            {
                cout << '(' << p[i].currentX << ',' << p[i].currentY << ')' << "   dir =" <<p[i].dir << " bugs = " <<p[i].bugs << endl;
            }
            cout << endl;
			*/



        }
        unsigned int answer = 0;
        for (int i = 0; i < K; i++)
        {
            if (p[i].bugs != 0)
            {
                answer += p[i].bugs;
            }
        }
		printf("#%d %d\n", n, answer);
		n++;
    }
}

// 예외 찾기를 잘 해야할것 같다. 그리고 코딩을 시작하기 전 자료구조 선택이 중요하다. 
