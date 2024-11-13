#include <iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    int count_zero = 0;
    int cnt = 0;
    vector<int> answer;
    while(s != "1") {
        int count_one = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0')
                count_zero++;
            else
                count_one++;
        }
        
        int length = count_one;
        
        string bit = "";
        while(length != 0) {
            bit += (length % 2 == 0 ? '0' : '1');
            length /= 2;
        }
        
        s = bit;
        cnt++;
    }
    
    answer.push_back(cnt);
    answer.push_back(count_zero);
    
    return answer;
}

int main()
{
    string s;
    cin >> s;

    vector<int> answer = solution(s);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}