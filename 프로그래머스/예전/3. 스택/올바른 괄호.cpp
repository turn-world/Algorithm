#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> str;
    
    for(int i = 0; i < s.size() ; i++)
    {
        if(s[i] == '(')
        {
            str.push(s[i]);
        }else{
            if(str.empty())
            {
                answer = false;
                break;
            }
            if(str.top() != '(')
            {
                answer = false;
                break;
            }else{
                str.pop();
            }
        }
    }
    
    if(!str.empty())
    {
       answer = false; 
    }
    return answer;
}