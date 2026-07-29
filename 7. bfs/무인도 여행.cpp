#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps)
{
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    vector<int> answer;
    vector<vector<int>> visited(
        maps.size(),
        vector<int>(maps[0].size(), 0)
    );

    queue<pair<int, int>> q;

    for (int a = 0; a < maps.size(); a++)
    {
        for (int b = 0; b < maps[a].size(); b++)
        {
            if (visited[a][b] == 1 || maps[a][b] == 'X')
            {
                continue;
            }

            queue<pair<int, int>> q;

            q.push({a, b});
            visited[a][b] = 1;

            int cur = 0;

            while (!q.empty())
            {
                int cur_y = q.front().first;
                int cur_x = q.front().second;
                q.pop();

                cur += maps[cur_y][cur_x] - '0';

                for (int i = 0; i < 4; i++)
                {
                    if (cur_y + dy[i] < 0 ||
                        cur_y + dy[i] >= maps.size() ||
                        cur_x + dx[i] < 0 ||
                        cur_x + dx[i] >= maps[0].size())
                    {
                        continue;
                    }

                    if (visited[cur_y + dy[i]][cur_x + dx[i]] == 1)
                    {
                        continue;
                    }

                    if (maps[cur_y + dy[i]][cur_x + dx[i]] == 'X')
                    {
                        continue;
                    }

                    visited[cur_y + dy[i]][cur_x + dx[i]] = 1;
                    q.push({
                        cur_y + dy[i],
                        cur_x + dx[i]
                    });
                }
            }

            answer.push_back(cur);
        }
    }

    if (answer.empty())
    {
        return {-1};
    }

    sort(answer.begin(), answer.end());

    return answer;
}