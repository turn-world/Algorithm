#include <string>

using namespace std;

int count = 0;
int answer = 0;

void dfs(string cur, string target)
{
    // 길이가 5가 되면 더 이상 문자 추가 불가
    if( cur.size() == 5)
        return;
    
    string vowels = "AEIOU";

    for (int i = 0; i < 5; i++)
    {
        string next = cur + vowels[i];

        // 새로운 단어 하나 생성
        // 순번 증가
        count++;
        // target과 같은지 검사
        if(next == target)
        {
            answer = count;
            return;
        }
        // 다음 길이 탐색
        dfs(next,target);
        
        if(answer!=0)
            return;
    }
}

int solution(string word)
{
    count = 0;
    answer = 0;

    dfs("", word);

    return answer;
}