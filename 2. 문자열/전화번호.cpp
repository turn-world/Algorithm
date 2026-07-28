#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> st;
    
    for(int i = 0 ; i < phone_book.size() ; i++)
    {
        st.insert(phone_book[i]);
        
    }
    
    for(auto &item : st)
    {
        string temp = "";
        
        for( int i = 0; i < item.size() - 1; i++)
        {
            temp += item[i];
            
            if(st.find(temp) != st.end())
            {
                return false;
            }
        }
    }
    return answer;
}