#include <iostream>
//#include <fstream>
#include <cstring>
#define MIN(A,B) (A<B ? A:B)
 
using namespace std;
int testCase, N;
int map[1001][1001];
int a = 1;
int answer = 0x7FFFFFF;
 
void init()
{
    a++;
    memset(map, 0, sizeof(map));
    answer = 0x7FFFFFF;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input.txt");
 
    cin >> testCase;
    while (testCase-- > 0)
    {
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cin >> map[i][j];
                if (i == j) continue;
                if (map[i][j] == 0) map[i][j] = 0x7FFFFFF;
            }
        }
        // 입력 완료 !!
        for (int k = 1; k <= N; k++)
        {
            for (int i = 1; i <= N; i++)
            {
                if (i == k) continue;
                for (int j = 1; j <= N; j++)
                {
                    if (i == j || k == j) continue;
                    map[i][j] = MIN(map[i][j], map[i][k] + map[k][j]);
                }
            }
        }
        // 플로이드 워샬 알고리즘 적용
 
        int sum;
        for (int i = 1; i <= N; i++)
        {
            sum = 0;
            for (int j = 1; j <= N; j++)
            {
                sum += map[i][j];
            }
            answer = MIN(sum, answer);
        }
        cout << "#" << a << " " << answer << '\n';
        init();
    }
}

// 모든 정점에 대한 최단거리 구하는 문제
// 플로이드 워샬 알고리즘 써서 
