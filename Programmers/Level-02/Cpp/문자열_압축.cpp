#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    for(int i = 1; i <= s.length() / 2; i++) {
        int count = 1;
        string cell = s.substr(0,i);
        string compare, temp;
        
        for(int j = i; j < s.length(); j += i) {
            compare = s.substr(j,i);
            
            if(!(cell.compare(compare))) {
                count++;
            }
            else {
                if(count == 1) {
                    temp += cell;
                    cell = compare;
                }
                else {
                    temp = temp + to_string(count) + cell;
                    cell = compare;
                    count = 1;
                }
            }
            
            if(i + j >= s.length()) {
                if(count != 1) {
                    temp = temp + to_string(count) + cell;
                    break;
                }
                else {
                    temp = temp + s.substr(j);
                    break;
                }
            }
        }
        answer = (answer > temp.length()) ? temp.length() : answer;
    }
    
    return answer;
}

int main()
{
    string s;
    cin >> s;

    int answer = solution(s);

    cout << answer;

    return 0;
}