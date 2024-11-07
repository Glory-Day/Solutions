#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& s)
{
    vector<string> result;
    
    string cache = "";
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == ' ')
        {
            result.push_back(cache);
            cache.clear();
            
            continue;
        }
        
        cache.push_back(s[i]);
    }
    
    if (cache.empty() == false)
    {
        result.push_back(cache);
    }
    
    return result;
}

const int to_number(const string& s)
{
    int result = 0;
    for (int i = (int)s.length() - 1, j = 1; i >= 0; i--, j *= 10)
    {
        result += (s[i] - '0') * j;
    }
    
    return result;
}

int solution(string my_string) {
    int answer = 0;
    
    vector<string> caches = split(my_string);
    
    int sum = to_number(caches[0]);
    for (int i = 2; i < (int)caches.size(); i += 2)
    {
        if (caches[i - 1] == "-")
        {
            sum -= to_number(caches[i]);
        }
        else
        {
            sum += to_number(caches[i]);
        }
    }
    
    answer = sum;
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    int answer = solution(my_string);

    cout << answer;

    return 0;
}