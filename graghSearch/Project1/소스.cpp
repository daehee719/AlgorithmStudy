#include <iostream>
#include <vector>

using namespace std;

int testcase;
int m, n;


int isVisited[51][51];
int field[51][51];

int nx[4] = { 1,0,-1,0 };
int ny[4] = { 0,1,0,-1 };

void reset()
{
	for (int i = 0; i < 51; i++)
	{
		for (int j = 0; j < 51; j++)
		{
			isVisited[i][j] = 0;
		}
		for (int j = 0; j < 51; j++)
		{
			field[i][j] = 0;
		}
	}
}

void DFS(int x, int y)
{
	isVisited[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		if (isVisited[x+nx[i]][y+ny[i]] == 0 && field[x+nx[i]][y+ny[i]] == 1)
		{
			if (x + nx[i] < 0 || y + ny[i] < 0 || y + ny[i] >= n || x + nx[i] >= m)
			{
				continue;
			}
			DFS(x + nx[i], y + ny[i]);
		}
	}
}

int main()
{
	
	int num;
	cin >> testcase;
	
	int a, b;


	for (int i = 0; i < testcase; i++)
	{
		int cnt = 0;

		cin >> m >> n;
		cin >> num;

		for (int i = 0; i < num; i++)
		{
			cin >> a >> b;
			field[a][b] = 1;
		}

		for (int a = 0; a < m; a++)
		{
			for (int b = 0; b < n; b++)
			{
				if (field[a][b] == 1 && isVisited[a][b] == 0)
				{
					DFS(a,b);
					cnt++;
				}
			}
		}
		cout << cnt << endl;

		reset();
	}
	


}