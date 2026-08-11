#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> maps)
{
    int n = maps.size();       // 세로: 행 개수
    int m = maps[0].size();    // 가로: 열 개수

    int visited[101][101] = {};

    queue<pair<int, int>> q;

    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty())
    {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int new_x = now_x + dx[i];
            int new_y = now_y + dy[i];

            // 맵 범위 검사
            if (new_x < 0 || new_x >= m ||
                new_y < 0 || new_y >= n)
            {
                continue;
            }

            // 벽이면 이동 불가
            if (maps[new_y][new_x] == 0)
            {
                continue;
            }

            // 이미 방문한 칸
            if (visited[new_y][new_x] != 0)
            {
                continue;
            }

            q.push({new_x, new_y});

            visited[new_y][new_x]
                = visited[now_y][now_x] + 1;
        }
    }

    int result = visited[n - 1][m - 1];

    if (result == 0)
    {
        return -1;
    }

    return result;
}