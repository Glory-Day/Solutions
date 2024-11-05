#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int to_integer(const string& s)
{
    int result = 0;
    for (int i = (int)s.length() - 1, j = 1; i >= 0; i--, j *= 10)
    {
        result += (s[i] - '0') * j;
    }
    
    return result;
}

int solution(vector<int> num_list) {
    int answer = 0;
    
    string a = "";
    string b = "";
    for (int i = 0; i < (int)num_list.size(); i++)
    {
        if (num_list[i] % 2 == 0)
        {
            a += to_string(num_list[i]);
        }
        else
        {
            b += to_string(num_list[i]);
        }
    }
    
    answer = to_integer(a) + to_integer(b);
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> num_list(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num_list[i];
    }

    int answer = solution(num_list);

    cout << answer;

    return 0;
}