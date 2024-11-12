#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int index;

bool compare(const string& a, const string& b) {
    if (a[index] == b[index])
    {
        return a < b;
    }

    return a[index] < b[index];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    index = n;
    
    sort(strings.begin(), strings.end(), compare);
    
    return strings;
}

int main()
{
    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; i++)
    {
        cin >> strings[i];
    }

    cin >> n;

    vector<string> answer = solution(strings, n);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}