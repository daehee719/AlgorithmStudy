#include <iostream>
#include <string>
#include <queue>

using namespace std;




const int MAX = 100;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, m, a[MAX][MAX], visited[MAX][MAX], y, x;
int main() 
{
    cin >> n >> m;
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = 0; j < m; j++) {
            a[i][j] = temp[j] - '0';
        }
            temp = "";
    }
    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({ 0, 0 });
    while (q.size()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];

            int nx = x + dx[i];

                // ä������ 
            if (ny < 0 || nx < 0 || nx >= m|| ny >= n || a[ny][nx] == 0)
                continue;
            if (visited[ny][nx] <= 0)
            {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ ny, nx });
            }
        }
    }
    cout << visited[n - 1][m - 1];
        return 0;
}