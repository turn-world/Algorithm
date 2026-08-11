#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int year = stoi(today.substr(0,4));
    int month = stoi(today.substr(5,2));
    int day = stoi(today.substr(8,2));
    
    for(int i = 0 ; i < privacies.size() ; i ++)
    {
        for(int j = 0 ; j < terms.size(); j++)
        {
            if(privacies[i].substr(11,1) == terms[j].substr(0,1))
            {
                int cus_year = stoi(privacies[i].substr(0,4));
                int cus_month = stoi(privacies[i].substr(5,2));
                int cus_day = stoi(privacies[i].substr(8,2));
                
                int temp = stoi(terms[j].substr(2)) + cus_month;
                while(temp > 12)
                {
                    cus_year++;
                    temp -= 12;
                }
                cus_month = temp;
                
                if(cus_year < year)
                {
                    answer.push_back(i+1);
                }
                else if(cus_year == year)
                {
                    if(cus_month < month)
                    {
                        answer.push_back(i+1);
                    }
                    else if(cus_month == month)
                    {
                        if(cus_day <= day)
                        {
                            answer.push_back(i+1);
                        }
                    }
                }
                    
            }
        }
    }
    return answer;
}