#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool valid(const string& from, const string& to)
{
    int count = 0;
    for (int i = 0; i < (int)from.length(); i++)
    {
        if (from[i] != to[i])
        {
            count++;
        }
    }

    return count == 1;
}

int solution(string begin, string target, vector<string> words)
{
    bool existed = false;
    for (const string& word : words)
    {
        if (word == target)
        {
            existed = true;

            break;
        }
    }
    
    if (existed == false)
    {
        return 0;
    }
    
    int size = words.size();
    vector<int> visited(size, false);
    queue<pair<string, int>> q;
    
    q.push({ begin,0 });
    
    while (q.empty() == false)
    {
        auto node = q.front();
        q.pop();
        
        if (node.first == target)
        {
            return node.second;
        }
        
        for (int i = 0; i < size; i++)
        {
            if (visited[i] == false && valid(node.first, words[i]))
            {
                q.push({words[i], node.second + 1});

                visited[i] = true;
            }
        }
    }
    
    return 0;
}

int main() {
    string begin, target;
    cin >> begin >> target;

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    int answer = solution(begin, target, words);

    cout << answer << '\n';

    return 0;
}