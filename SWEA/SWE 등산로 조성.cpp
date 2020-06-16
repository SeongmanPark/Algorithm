#include <iostream>
//#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
 
using namespace std;
 
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int map[9][9];
bool visit[9][9] = { false };
int N, K, testCase, height, max_height;
queue<pair<int, int>> q;    // 가장 높은 봉우리의 좌표
int a = 1;
int max_length;
 
 
 
void init()
{
    a++;
    memset(map, 0, sizeof(map));
    memset(visit, 0, sizeof(visit));
    max_height = 0;
    max_length = 0;
}
 
bool isWall(int x, int y)
{
    if (x < 1 || y < 1 || x > N || y > N)
        return true;
    else return false;
}
 
void dfs(int depth, int x, int y)
{
    visit[x][y] = true;
    if (depth > max_length) max_length = depth;
 
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (isWall(new_x, new_y) || visit[new_x][new_y] || map[new_x][new_y] >= map[x][y]) continue;
        // 벽이거나 방문했거나 새로운 봉우리의 높이가 더높거나 같으면?
        else
        {
            dfs(depth + 1, new_x, new_y);
        }
    }
    visit[x][y] = false;
}
 
int main()
{
    //ifstream input("input.txt");
    cin >> testCase;
 
    while (testCase-- > 0)
    {
        cin >> N >> K;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cin >> height;
                map[i][j] = height;
                if (height > max_height) max_height = height;
            }
        }
        // map 입력 완료, 가장 높은 봉우리의 높이 = max_height
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (map[i][j] == max_height)
                {
                    q.push(make_pair(i, j));
                }
            }
        }
        // 가장 높은 봉우리의 좌표(시작점) 입력 완료 !!
        while (!q.empty())
        {
            for (int k = 0; k <= K; k++)
            {
                for (int i = 1; i <= N; i++)
                {
                    for (int j = 1; j <= N; j++)
                    {
                        map[i][j] -= k;
                        dfs(0 ,q.front().first, q.front().second);
                        map[i][j] += k;
                    }
                }
            }
            q.pop();
        }
        cout << "#" << a << " " << max_length + 1 << '\n';
        init();
    }
}
