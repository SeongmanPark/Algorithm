#include <iostream>
//#include <fstream>
#include <cstring>
#include <vector>
 
using namespace std;
int testCase, N;
int digit[10];
string str;
int a = 1;
 
void init()
{
    a++;
    memset(digit, 0, sizeof(digit));
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream input("input.txt");
    cin >> testCase;
    while (testCase-->0)
    {
        cin >> str;
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            cin >> str;
            if (str == "ZRO")   digit[0]++;
            else if (str == "ONE")  digit[1]++;
            else if (str == "TWO") digit[2]++;
            else if (str == "THR") digit[3]++;
            else if (str == "FOR") digit[4]++;
            else if (str == "FIV") digit[5]++;
            else if (str == "SIX") digit[6]++;
            else if (str == "SVN") digit[7]++;
            else if (str == "EGT") digit[8]++;
            else if (str == "NIN") digit[9]++;
        }
        cout << "#" << a << '\n';
        for (int i = 0; i < 10; i++)
        {
            for (int j = 1; j <= digit[i]; j++)
            {
                switch (i)
                {
                case 0: cout << "ZRO "; break;
                case 1: cout << "ONE "; break;
                case 2: cout << "TWO "; break;
                case 3: cout << "THR "; break;
                case 4: cout << "FOR "; break;
                case 5: cout << "FIV "; break;
                case 6: cout << "SIX "; break;
                case 7: cout << "SVN "; break;
                case 8: cout << "EGT "; break;
                case 9: cout << "NIN "; break;
                default: break;
                }
            }
        }
        cout << '\n';
        init();
 
    }
}

// 숫자 0~9를 string으로 입력받고 오름차순으로 sort해서 출력하는 문제
// 숫자를 받을때마다 해당 digit 인덱스 값 ++후 0부터 차례대로 출력하면
// sorting 할 필요도 없고 빠른 속도로 실행 가능.
