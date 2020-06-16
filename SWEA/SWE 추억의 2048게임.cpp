#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int map[21][21];

int main()
{
	ifstream input("input.txt");
	int testCase;
	int n = 1;
	int dir, N, data;
	string d;
	input >> testCase;
	while (testCase-- > 0)
	{
		input >> N >> d;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				input >> data;
				map[i][j] = data;
			}
		}
		
		if (d == "up")
		{
			for (int j = 1; j <= N; j++)
			{
				for (int i = 1; i <= N-1;)
				{
					if (map[i][j] == 0)
					{
						i++;
						continue;
					}
					else
					{
						int new_i = i + 1;
						while (1)
						{
							if (new_i > N)
							{
								i = new_i;
								break;
							}
							else if (map[new_i][j] == 0)
								new_i++;
							else if (map[new_i][j] == map[i][j])
							{
								map[i][j] += map[new_i][j];
								map[new_i][j] = 0;
								i = new_i + 1;
								break;
							}
							else
							{
								i = new_i;
								break;
							}
						}
					}
				}
			}
			for (int j = 1; j <= N; j++)
			{
				for (int i = 1; i <= N-1; i++)
				{
					if (map[i][j] == 0)
					{
						int new_i = i+1;
						while (1)
						{
							if (new_i > N)
								break;
							if (map[new_i][j] != 0)
							{
								map[i][j] = map[new_i][j];
								map[new_i][j] = 0;
								break;
							}
							else
							{
								new_i++;
							}
						}
					}
				}
			}
		}
		else if (d == "down")
		{
			for (int j = 1; j <= N; j++)
			{
				for (int i = N; i >= 2;)
				{
					if (map[i][j] == 0)
					{
						i--;
						continue;
					}
					else
					{
						int new_i = i - 1;
						while (1)
						{
							if (new_i < 1)
							{
								i = new_i;
								break;
							}
							else if (map[new_i][j] == 0)
								new_i--;
							else if (map[new_i][j] == map[i][j])
							{
								map[i][j] += map[new_i][j];
								map[new_i][j] = 0;
								i = new_i - 1;
								break;
							}
							else
							{
								i = new_i;
								break;
							}
						}
					}
				}
			}
			for (int j = 1; j <= N; j++)
			{
				for (int i = N; i >= 2; i--)
				{
					if (map[i][j] == 0)
					{
						int new_i = i - 1;
						while (1)
						{
							if (new_i < 1)
								break;
							if (map[new_i][j] != 0)
							{
								map[i][j] = map[new_i][j];
								map[new_i][j] = 0;
								break;
							}
							else
							{
								new_i--;
							}
						}
					}
				}
			}
		}
		else if (d == "left")
		{
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= N - 1;)
				{
					if (map[i][j] == 0)
					{
						j++;
						continue;
					}
					else
					{
						int new_j = j + 1;
						while (1)
						{
							if (new_j > N)
							{
								j = new_j;
								break;
							}
							else if (map[i][new_j] == 0)
								new_j++;
							else if (map[i][new_j] == map[i][j])
							{
								map[i][j] += map[i][new_j];
								map[i][new_j] = 0;
								j = new_j + 1;
								break;
							}
							else
							{
								j = new_j;
								break;
							}
						}
					}
				}
			}
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= N - 1; j++)
				{
					if (map[i][j] == 0)
					{
						int new_j = j + 1;
						while (1)
						{
							if (new_j > N)
								break;
							if (map[i][new_j] != 0)
							{
								map[i][j] = map[i][new_j];
								map[i][new_j] = 0;
								break;
							}
							else
							{
								new_j++;
							}
						}
					}
				}
			}
		}
		else if (d == "right")
		{
			for (int i = 1; i <= N; i++)
			{
				for (int j = N; j >= 2;)
				{
					if (map[i][j] == 0)
					{
						j--;
						continue;
					}
					else
					{
						int new_j = j - 1;
						while (1)
						{
							if (new_j < 1)
							{
								j = new_j;
								break;
							}
							else if (map[i][new_j] == 0)
								new_j--;
							else if (map[i][new_j] == map[i][j])
							{
								map[i][j] += map[i][new_j];
								map[i][new_j] = 0;
								j = new_j - 1;
								break;
							}
							else
							{
								j = new_j;
								break;
							}
						}
					}
				}
			}
			for (int i = 1; i <= N; i++)
			{
				for (int j = N; j >= 2; j--)
				{
					if (map[i][j] == 0)
					{
						int new_j = j - 1;
						while (1)
						{
							if (new_j < 1)
								break;
							if (map[i][new_j] != 0)
							{
								map[i][j] = map[i][new_j];
								map[i][new_j] = 0;
								break;
							}
							else
							{
								new_j--;
							}
						}
					}
				}
			}
		}
		cout << "#" << n << endl;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << map[i][j] << "\t";
			}
			cout << endl;
		}
		n++;
		memset(map, 0, sizeof(map));
	}

}

// 배열 인덱스 잘 보기 !!!
