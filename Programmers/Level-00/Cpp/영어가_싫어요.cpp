#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long long to_number(const string& s)
{
    long long result = 0LL;
    
    long long j = 1LL;
    for (int i = (int)s.length() - 1; i >= 0; i--, j *= 10LL)
    {
        result += (long long)(s[i] - '0') * j;
    }

    return result;
}

long long solution(string numbers) {
    long long answer = 0;
    
    vector<string> caches = { "zero","one","two","three","four","five","six","seven","eight","nine" };
    for (int i = 0; i < 10; i++)
    {
        int index = numbers.find(caches[i]);
        while (index != string::npos)
        {
            numbers.replace(index, (int)caches[i].length(), to_string(i));
            
            index = numbers.find(caches[i]);
        }
    }
    
    answer = to_number(numbers);
    
    return answer;
}

int main()
{
    string numbers;
    cin >> numbers;

    long long answer = solution(numbers);

    cout << answer;   
}