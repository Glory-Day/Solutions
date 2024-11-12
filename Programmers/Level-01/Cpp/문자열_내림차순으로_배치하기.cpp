#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<char> sequence;
    for(auto i: s)
    {
        sequence.push_back(i);
    }
    
    sort(sequence.begin(), sequence.end(), greater<char>());
    
    for(auto i: sequence)
    {
        answer += i;
    }
    
    return answer;
}

int main()
{
    string s;
    cin >> s;

    string answer = solution(s);

    cout << answer;

    return 0;
}