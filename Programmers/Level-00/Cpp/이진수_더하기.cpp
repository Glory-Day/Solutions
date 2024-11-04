#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    
    int l = (int)max(bin1.length(), bin2.length());
    
    int size = (int)bin1.length();
    for (int i = 0; i < l - size; i++)
    {
        bin1 = "0" + bin1;
    }
    
    size = (int)bin2.length();
    for (int i = 0; i < l - size; i++)
    {
        bin2 = "0" + bin2;
    }
    
    int carry = 0;
    for (int i = l - 1; i >= 0; i--)
    {
        int sum = (bin1[i] - '0') + (bin2[i] - '0') + carry;
        carry = sum / 2;
        
        answer.push_back((sum % 2) + '0');
    }
    
    if (0 < carry)
    {
        answer.push_back(carry + '0');
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}

int main()
{
    string bin1, bin2;
    cin >> bin1 >> bin2;

    string answer = solution(bin1, bin2);

    cout << answer;
}