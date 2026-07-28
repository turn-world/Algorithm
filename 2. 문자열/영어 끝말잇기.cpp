#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> storage;
    int cnt = 1;
    int turn = 1;
    bool accident = false;
    for(int i = 0; i < words.size() - 1; i++)
    {
        
        string word1 ="";
        string word2 ="";
        word1 = words[i];
        word2 = words[i+1];
        
        
        if(word1[word1.size()-1] != word2[0] || 
           find(storage.begin(), storage.end(), word2) != storage.end())
        {
            cnt++;
            if(cnt > n)
            {
                turn++;
                cnt = 1;
            }
            answer.push_back(cnt);
            answer.push_back(turn);
            
            accident = true;
            break;
        }
        else{
            cnt++;
            if(cnt > n)
            {
                turn++;
                cnt = 1;
            }
        }
        storage.push_back(word1);
        
    }
    
    if(accident == false)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}