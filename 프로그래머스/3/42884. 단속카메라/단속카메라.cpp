#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes)
{
    // 진출 지점 기준 정렬
    sort(routes.begin(), routes.end(), 
         [](const vector<int>& a, const vector<int>& b) {return a[1] < b[1];});
    
    int answer = 0;

    // 현재 카메라 위치
    int camera = -30001;

    for (int i = 0; i < routes.size(); i++)
    {
        // 현재 카메라가 이 차량을 잡을 수 없는 경우
        if(camera < routes[i][0] || camera > routes[i][1])
        {
            answer++;
        }else{
            continue;
        }
        // 새 카메라를 차량의 진출 지점에 설치
        camera = routes[i][1];
    }

    return answer;
}