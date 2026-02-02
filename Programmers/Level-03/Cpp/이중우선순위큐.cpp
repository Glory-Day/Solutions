#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;

    multiset<int> caches;
    
    for (const string& operation : operations)
    {
        char command = operation[0];
        int number = stoi(operation.substr(2));
        
        if (command == 'I')
        {
            caches.insert(number);
        }
        else if (command == 'D' && caches.empty() == false)
        {
            caches.erase(number == 1 ? prev(caches.end()) : caches.begin());
        }
    }
    
    if (caches.empty())
    {
        return { 0,0 };
    }
    
    answer = { *caches.rbegin(),*caches.begin() };

    return answer;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    vector<string> operations(n);
    for (int i = 0; i < n; i++)
    {
        getline(cin, operations[i]);
    }

    vector<int> answer = solution(operations);

    cout << answer[0] << ' ' << answer[1] << '\n';

    return 0;
}