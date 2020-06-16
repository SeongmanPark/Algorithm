#include <iostream>
//#include <fstream>
#include <cstring>
 
using namespace std;
#define MAX(a,b) (a>b?a:b)
 
int dx[] = { -1,-1,1,1 };
int dy[] = { -1,1,1,-1 };
// 이동경로 왼쪽위, 오른쪽 위, 오른쪽 아래, 왼쪽 아래
int testCase, N;
int map[21][21];
bool desert[101] = { false };
int answer;
int a = 1;
 
void init()
{
    a++;
    answer = 0;
    memset(map, 0, sizeof(map));
    memset(desert, 0, sizeof(desert));
}
 
bool isWall(int x, int y)
{
    if (x<1 || y<1 || x>N || y>N)
        return true;
    else return false;
}
 
void dfs(int depth, int start_x, int start_y, int pre_x, int pre_y, int DIR)
{
     
    for (int i = DIR; i < 4; i++)
    {
        int new_x = pre_x + dx[i];
        int new_y = pre_y + dy[i];
 
        if (pre_x == start_x - 1 && pre_y == start_y + 1)
        {
            if (DIR == 2 || DIR == 3)
            {
                answer = MAX(answer, depth);
                return;
            }
        }
 
        if (isWall(new_x, new_y) || desert[map[new_x][new_y]])  // 새로 방문하려고 하는곳이 벽이거나 ? 이미 지나온 디저트집이면 ?
        {
            continue;
        }
 
        else
        {
            desert[map[new_x][new_y]] = true;
            dfs(depth + 1, start_x, start_y, new_x, new_y, i);
            desert[map[new_x][new_y]] = false;
        }
    }
 
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    //ifstream input("input.txt");
    cin >> testCase;
    while (testCase-- > 0)
    {
        cin >> N;
        for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> map[i][j];
        // map 입력 완료
 
        for (int i = 3; i <= N; i++)
        {
            for (int j = 2; j <= N - 1; j++)
            {
                desert[map[i][j]] = true;
                dfs(1, i, j, i, j, 0);
                desert[map[i][j]] = false;
            }
        }
        if (answer == 0) answer = -1;
        cout << "#" << a << " " << answer << '\n';
        init();
    }
}

// 계속 안 풀리다가.. 5분 잠깐 봤는데 풀린문제.
// 재귀함수 들어가는 부분에서 실수하여 몇날 몇일을 고생하였다.
// 미리 내가 그릴 사각형을 그려서 시뮬레이션.
