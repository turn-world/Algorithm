#include <vector>

using namespace std;

void dfs(int current,int n, vector<vector<int>>& computers,int visited[])
{
    visited[current] = 1;

    for (int next = 0; next < n; next++)
    {
        if (computers[current][next] == 1 && visited[next] == 0)
        {
            dfs(next, n, computers, visited);
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
            dfs(i, n, computers, visited);
            answer++;
        }
    }

    return answer;
}