#include <string>
#include <iostream>

using namespace std;

bool visit[11][11][11][11] = { false };

int solution(string dirs)
{
	//string dirs = "ULURRDLLU";
	int answer = 0;
	int x = 5;
	int y = 5;
	int x1;
	int y1;

	for (int i = 0; i < dirs.length(); i++) {

		if (dirs[i] == 'U') { // Up이면
			x1 = x;
			y1 = y + 1;
            if(y1>10){
                y1 = y - 1;
                x=x1;
                continue;
            }
            
			if (visit[x][y][x1][y1] == true) {
				x = x1;
				y = y1;
			}
			else {
				visit[x][y][x1][y1] = true;
				visit[x1][y1][x][y] = true;
				x = x1;
				y = y1;
				answer++;
			}
		}

		else if (dirs[i] == 'D') { // down이면
			x1 = x;
			y1 = y - 1;
			if(y1<0){
                y1 = y+1;
                x=x1;
                continue;
            }
            
            if (visit[x][y][x1][y1] == true) {
				x = x1;
				y = y1;
			}

			else {
				visit[x][y][x1][y1] = true;
				visit[x1][y1][x][y] = true;
				x = x1;
				y = y1;
				answer++;
			}
		}

		else if (dirs[i] == 'R') { // right이면
			x1 = x + 1;
			y1 = y;
            if(x1>10){
                x = x1-1;
                y=y1;
                continue;
            }
            
			if (visit[x][y][x1][y1] == true) {
				x = x1;
				y = y1;
			}

			else {
				visit[x][y][x1][y1] = true;
				visit[x1][y1][x][y] = true;
				x = x1;
				y = y1;
				answer++;
			}
		}

		else if (dirs[i] == 'L') { // left이면
			x1 = x - 1;
			y1 = y;
                if(x1<0){
                    x = x1+1; 
                    y = y1; 
                    continue;
                }
            
                if (visit[x][y][x1][y1] == true) {
                    x = x1;
                    y = y1;
                }

                else {
                    visit[x][y][x1][y1] = true;
                    visit[x1][y1][x][y] = true;
                    x = x1;
                    y = y1;
                    answer++;
                }
		}
	}

	return answer;
}

// 4차원 방문 배열을 사용했던 신박한 문제.
