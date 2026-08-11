#include <string>

using namespace std;

string solution(string number, int k)
{
    string answer = "";

    for (char num : number)
    {
        while (k > 0 &&
               !answer.empty() &&
               answer.back() < num)
        {
            answer.pop_back();
            k--;
        }

        answer.push_back(num);
    }

    while (k > 0)
    {
        answer.pop_back();
        k--;
    }

    return answer;
}