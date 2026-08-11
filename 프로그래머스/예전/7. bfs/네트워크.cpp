#include <vector>
#include <queue>

using namespace std;

void bfs(int start, int n, vector<vector<int>>& computers, int visited[])
{
    queue<int> q;

    q.push(start);
    visited[start] = 1;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int next = 0; next < n; next++)
        {
            if (computers[current][next] == 1 && visited[next] == 0)
            {
                visited[next] = 1;
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    int visited[200] = {};

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            bfs(i, n, computers, visited);
            answer++;
        }
    }

    return answer;
}