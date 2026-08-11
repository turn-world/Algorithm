#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> nums;

void dfs(string cur,
         const string& numbers,
         vector<int>& visited)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        // 이미 사용한 숫자 조각이면 continue
        if(visited[i] == 1)
            continue;
        // 방문 처리
        visited[i] = 1;
        
        // cur 뒤에 numbers[i]를 붙인 새로운 문자열 생성
        string next = cur + numbers[i];
        
        // 정수로 변환해서 nums에 저장
        nums.insert(stoi(next));
        
        // DFS 진행
        dfs(next,numbers,visited);
        
        // 방문 취소
        visited[i] = 0;
    }
}

bool isPrime(int n)
{
    // 소수 판별
    if( n == 2)
        return true;
    if(n < 2 )
        return false;
    for(int i = 2 ; i < n ; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers)
{
    vector<int> visited(numbers.size(), 0);

    dfs("", numbers, visited);

    int answer = 0;

    // nums에 들어있는 숫자 중 소수 개수 계산
    for(int num : nums)
    {
        if(isPrime(num))
            answer++;
    }
    return answer;
}