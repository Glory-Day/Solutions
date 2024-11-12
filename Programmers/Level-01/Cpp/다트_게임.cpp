#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    vector<int> number;
    string temp = ""; 
    for (auto i: dartResult)
    {
        int temp2 = 0;
        vector<int> temp3;
        switch(i)
        {
            case 'S':
                temp2 = stoi(temp);
                number.push_back(temp2);
                temp = "";

                break;
            case 'D':
                temp2 = stoi(temp);
                number.push_back(temp2 * temp2);
                temp = "";

                break;
            case 'T':
                temp2 = stoi(temp);
                number.push_back(temp2 * temp2 * temp2);
                temp = "";
                
                break;
            case '*':
                for (int j = 0; j < 2 && number.empty() == false; j++)
                {
                    temp3.push_back(number.back() * 2);
                    number.pop_back();
                }
                
                reverse(temp3.begin(), temp3.end());
                
                for (auto j: temp3)
                {
                    number.push_back(j);
                }

                break;
            case '#':
                number[number.size() - 1] *= -1;
                
                break;
            default :
                temp += i;
                
                break;
        }
    }
    for (auto i: number)
    {
        answer += i;
        
        cout << i << ' ';
    }

    return answer;
}

int main()
{
    string dartResult;
    cin >> dartResult;

    int answer = solution(dartResult);

    cout << answer;

    return 0;
}