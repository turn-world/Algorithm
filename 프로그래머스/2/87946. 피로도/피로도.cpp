#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;

void dfs(int fatigue,
         int count,
         const vector<vector<int>>& dungeons,
         vector<int>& visited)
{
    answer = max(answer, count);

    for (int i = 0; i < dungeons.size(); i++)
    {
        // 이미 방문
        if (visited[i] == 1)
            continue;

        // 피로도 부족
        if (fatigue < dungeons[i][0])
            continue;

        // 선택
        visited[i] = 1;

        // 다음 경우 탐색
        dfs(
            fatigue - dungeons[i][1],
            count + 1,
            dungeons,
            visited
        );

        // 선택 취소
        visited[i] = 0;
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    answer = 0;

    vector<int> visited(dungeons.size(), 0);

    dfs(k, 0, dungeons, visited);

    return answer;
}