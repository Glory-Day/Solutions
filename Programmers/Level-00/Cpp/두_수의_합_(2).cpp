#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct BigInteger
{
    string number;
    
    BigInteger(const string number) : number(number) { }
    
    const BigInteger operator+(const BigInteger& other)
    {
        string result = "";
        
        string n = this->number;
        string m = other.number;
        
        int l = (int)max(n.length(), m.length());
        int d = l - (int)n.length();
        for (int i = 0; i < d; i++) 
        {
            n = "0" + n;
        }
        
        d = l - (int)m.size();
        for (int i = 0; i < d; i++)
        {
            m = "0" + m;
        }
        
        int carry = 0;
        for (int i = l - 1; i >= 0; i--)
        {
            int sum = (n[i] - '0') + (m[i] - '0') + carry;
            carry = sum / 10;
            
            result.push_back((sum % 10) + '0');
        }
        
        if (0 < carry)
        {
            result.push_back(carry + '0');
        }
        
        reverse(result.begin(), result.end());
        
        return BigInteger(result);
    }
};

string solution(string a, string b) {
    string answer = "";
    
    BigInteger n(a), m(b);
    
    answer = (n + m).number;
    
    return answer;
}

int main()
{
    string a, b;
    cin >> a >> b;

    string answer = solution(a, b);
    
    cout << answer;

    return 0;
}