#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string n_str) {
    string answer = "";
    
    reverse(n_str.begin(), n_str.end());
    
    while (n_str.back() == '0')
    {
        n_str.pop_back();
    }
    
    reverse(n_str.begin(), n_str.end());
    
    answer = n_str;
    
    return answer;
}

int main()
{
    string n_str;
    cin >> n_str;

    string answer = solution(n_str);
    
    cout << answer;

    return 0;
}