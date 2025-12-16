#include <iostream>
#include <vector>
#include <string>
#include <complex>
#include <algorithm>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

class BigInteger
{
private:
    const double PI = acos(-1);

    vector<int> _digits;

    const vector<int> ToVector(const string&) const;
    const string ToString(const vector<int>&) const;

    void Normalize();

    void FFT(vector<complex<double>>&, bool) const;
    const vector<int> multiply(vector<int>&, vector<int>&) const;

public:
    BigInteger() : _digits{0} {}
    BigInteger(const string& s) { _digits = ToVector(s); }
    BigInteger(const vector<int>& v) : _digits(v) { Normalize(); }

    const string ToString() const { return ToString(_digits); }

    BigInteger& operator=(const BigInteger&);

    const BigInteger operator+(const BigInteger&) const;
    const BigInteger operator-(const BigInteger&) const;
    const BigInteger operator*(const BigInteger&) const;
    const BigInteger operator/(const int&) const;

    bool operator==(const BigInteger&) const;
    bool operator<(const BigInteger&) const;
    bool operator>(const BigInteger&) const;
};

const vector<int> BigInteger::ToVector(const string& rhs) const
{
    int n = (int)rhs.size();
    vector<int> result(n);

    for (int i = 0; i < n; i++)
    {
        result[i] = rhs[i] - '0';
    }

    return result;
}

const string BigInteger::ToString(const vector<int>& rhs) const
{
    string result = "";

    bool checked = false;
    for (auto i: rhs)
    {
        if (i)
        {
            checked = true;
        }

        if (checked)
        {
            result += (i + '0');
        }
    }

    if (checked == false)
    {
        result += '0';
    }

    return result;
}

void BigInteger::Normalize()
{
    int index = 0;
    while (index + 1 < (int)_digits.size() && _digits[index] == 0)
    {
        index ++;
    }

    if (index > 0)
    {
        _digits.erase(_digits.begin(), _digits.begin() + index);
    }
}

void BigInteger::FFT(vector<complex<double>> &a, bool inversed) const
{
    int n = (int)a.size();
    for (int i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;
        while (((j ^= bit) & bit) == false)
        {
            bit >>= 1;
        }

        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }

    for (int i = 1; i < n; i <<= 1)
    {
        double x = (inversed ? 1 : -1) * PI / i;
        complex<double> w = { cos(x),sin(x) };

        for (int j = 0; j < n; j += i << 1)
        {
            complex<double> l(1);
            for (int k = 0; k < i; k++)
            {
                complex<double> cache = a[i + j + k] * l;
                a[i + j + k] = a[j + k] - cache;
                a[j + k] += cache;
                l *= w;
            }
        }
    }

    if (inversed)
    {
        for (int i = 0; i < n; i++)
        {
            a[i] /= n;
        }
    }
}

const vector<int> BigInteger::multiply(vector<int>& a, vector<int>& b) const
{
    vector<complex<double>> ca(a.begin(), a.end());
    vector<complex<double>> cb(b.begin(), b.end());

    int size = (int)max(ca.size(), cb.size());
    int n = 1;
    while (size > n)
    {
        n <<= 1;
    }
    n *= 2;

    ca.resize(n);
    cb.resize(n);

    FFT(ca, false);
    FFT(cb, false);

    for (int i = 0; i < n; i++)
    {
        ca[i] *= cb[i];
    }

    FFT(ca, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        result[i] = (int)round(ca[i].real());
    }

    return result;
}

BigInteger& BigInteger::operator=(const BigInteger& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    _digits = rhs._digits;

    return *this;
}

const BigInteger BigInteger::operator*(const BigInteger& rhs) const
{
    vector<int> va = _digits;
    vector<int> vb = rhs._digits;
    
    reverse(va.begin(), va.end());
    reverse(vb.begin(), vb.end());

    vector<int> result = multiply(va, vb);
    
    for (int i = 0; i < (int)result.size(); i++)
    {
        if (result[i] >= 10)
        {
            if (i == (int)result.size() - 1)
            {
                result.push_back(result[i] / 10);
            }
            else
            {
                result[i + 1] += result[i] / 10;
            }

            result[i] %= 10;
        }
    }

    reverse(result.begin(), result.end());

    return BigInteger(result);
}

const BigInteger BigInteger::operator+(const BigInteger& rhs) const
{
    vector<int> result;

    int i = _digits.size() - 1;
    int j = rhs._digits.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += _digits[i--];
        }
        
        if (j >= 0)
        {
            sum += rhs._digits[j--];
        }
        
        result.push_back(sum % 10);
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    
    return BigInteger(result);
}

const BigInteger BigInteger::operator-(const BigInteger& rhs) const
{
    vector<int> result = _digits;
    
    int i = result.size() - 1;
    int j = rhs._digits.size() - 1;
    int borrow = 0;

    while (i >= 0)
    {
        int cache = result[i] - borrow;
        if (j >= 0)
        {
            cache -= rhs._digits[j];
        }

        if (cache < 0)
        {
            cache += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result[i] = cache;
        i--;
        j--;
    }

    return BigInteger(result);
}

const BigInteger BigInteger::operator/(const int& rhs) const
{
    vector<int> result;
    int remainder = 0;

    for (int digit : _digits)
    {
        int x = remainder * 10 + digit;
        result.push_back(x / rhs);
        remainder = x % rhs;
    }

    return BigInteger(result);
}

bool BigInteger::operator==(const BigInteger& rhs) const
{
    return _digits == rhs._digits;
}

bool BigInteger::operator<(const BigInteger& rhs) const
{
    int a = (int)_digits.size();
    int b = (int)rhs._digits.size();

    if (a != b)
    {
        return a < b;
    }
    
    return _digits < rhs._digits;
}

bool BigInteger::operator>(const BigInteger& rhs) const
{
    return rhs < *this;
}

const string Binary_Search(const string& a, const string& b)
{
    auto n = BigInteger(b);

    auto l = BigInteger(a);
    auto r = n;
    auto cache = BigInteger("1");

    while (true)
    {
        auto middle = (l + r) / 2;
        auto p = middle * middle;

        if (p == n)
        {
            return middle.ToString();
        }
        else if (p > n)
        {
            r = middle - cache;
        }
        else
        {
            l = middle + cache;
        }
    }
}

int main()
{
    FAST_IO;

    string n;
    cin >> n;

    string answer = Binary_Search("1", n);

    cout << answer;

    return 0;
}