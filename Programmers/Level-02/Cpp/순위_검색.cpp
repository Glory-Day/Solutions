#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

vector<string> split(string line)
{
    vector<string> result;

    string buffer;
    istringstream stream(line);
    while (getline(stream, buffer, ' '))
    {
        result.push_back(buffer);
    }

    return result;
}

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
 
    map<string, string> table;
    table["cpp"] = "1";
    table["java"] = "2";
    table["python"] = "3";
    table["backend"] = "1";
    table["frontend"] = "2";
    table["junior"] = "1";
    table["senior"] = "2";
    table["chicken"] = "1";
    table["pizza"] = "2";
 
    map<string, vector<int>> infos;
    for (auto s : info)
    {
        vector<string> lines = split(s);

        string hash;
        for(int i = 0; i < 4; i++)
        {
            hash += table[lines[i]];
        }
        
        infos[hash].push_back(stoi(lines.back()));
    }

    for (auto& i: infos)
    {
        sort(i.second.begin(), i.second.end());
    }
 
    for (auto i: query)
    {
        vector<string> temp(5);
        vector<string> lines = split(i);
        for (int j = 0; j < 4; j++)
        {
            temp[j] = lines[j * 2];            
        }
        temp[4] = lines[7];
 
        vector<string> keys[4];
        for(int j = 0; j < 4; j++)
        {
            if(temp[j] != "-")
            {
                keys[j] = { table[temp[j]] };
            }
            else
            {
                keys[j] = ((j == 0) ? vector<string> { "1","2","3" } : vector<string> { "1","2" });
            }
        }
 
        int cnt=0;
        for(auto a: keys[0])
        {
            for(auto b: keys[1])
            {
                for(auto c: keys[2])
                {
                    for(auto d: keys[3])
                    {
                        string key = a + b + c + d;
                        int value = stoi(temp[4]);

                        auto iter = lower_bound(infos[key].begin(), infos[key].end(), value);
                        cnt += infos[key].end() - iter;
                    }
                }
            }
        }

        answer.push_back(cnt);
 
    }

    return answer;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    vector<string> info(n);
    for (int i = 0; i < n; i++)
    {
        getline(cin, info[i]);
    }

    cin >> n;
    cin.ignore();

    vector<string> query(n);
    for (int i = 0; i < n; i++)
    {
        getline(cin, query[i]);
    }

    vector<int> answer = solution(info, query);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}