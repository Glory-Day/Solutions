#include <iostream>
#include <string>
#include <deque>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int cnt = 0;
    deque<char> Deque;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            Deque.push_back('(');
            cnt++;
        }
        else {
            if(Deque.empty() == true) return false;
            Deque.pop_back();
            cnt--;
        }
    }
    
    if(Deque.empty() == true && cnt == 0)
        return answer;
    return false;
}

int main()
{
    string s;
    cin >> s;

    bool answer = solution(s);

    cout << answer;

    return 0;
}