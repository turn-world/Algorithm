#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> count;
    
    for(int i = 0 ; i < participant.size(); i ++)
    {
        count[participant[i]]++;
    }
    
    for(int i = 0 ; i < completion.size() ; i++)
    {
        count[completion[i]]--;
    }
    
    for( auto temp : count)
    {
        if ( temp.second > 0)
        {
            answer = temp.first;
        }
    }
    return answer;
}