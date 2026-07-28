#include <string>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

set<int> solution(vector<int> array) {
    set<int> st;
    for(int i = 0 ; i < array.size(); i++)
    {
        st.insert(array[i]);
    }

    return st;
}