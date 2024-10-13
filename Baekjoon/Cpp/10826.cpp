#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct BigInteger
{
    string number;

    const string operator+(const BigInteger& other)
    {
        string result;

        int n = this->number.length();
        int m = other.number.length();

        int mx = max(n, m);
        string a = string(mx - n, '0') + this->number;
        string b = string(mx - m, '0') + other.number;

        int carry = 0;
        for (int i = mx - 1; i >= 0; i--)
        {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            carry = sum / 10;
            result += (sum % 10) + '0';
        }

        if (carry > 0)
        {
            result += carry + '0';
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    int n;
    cin >> n;

    BigInteger caches[2] = { "0","1" };
    for (int i = 2; i <= n; i++)
    {
        string sum = caches[0] + caches[1];
        caches[0].number = caches[1].number;
        caches[1].number = sum;
    }

    string answer = n < 2 ? caches[n].number : caches[1].number;

    cout << answer;
}