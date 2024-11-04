#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
   int answer = 0;
    
    vector<vector<pair<int, int>>> paths(101, vector<pair<int, int>>());

    int index = 0;
    int length = 0;
    pair<int, int> path;
    for (int i = 0; i < (int)routes.size(); i++)
    {
        for (int j = 1; j < (int)routes[i].size(); j++)
        {
            int b = routes[i][j - 1];
            int e = routes[i][j];
            path = { points[b - 1][0],points[b - 1][1] };

            while (points[e - 1][0] != path.first)
            {
                paths[index].push_back(path);
                points[e - 1][0] > path.first ? path.first++ : path.first--;
            }

            while (points[e - 1][1] != path.second)
            {
                paths[index].push_back(path);
                points[e - 1][1] > path.second ? path.second++ : path.second--;
            }      
        }

        paths[index].push_back(path);
        
        if (length < (int)paths[index].size())
        {
            length = (int)paths[index].size();
        }
        
        index++;
    }

    int size = (int)routes.size();
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if ((int)paths[j].size() <= i)
            {
                continue;
            }
            
            if (paths[j][i].first == -1)
            {
                continue;
            }
            
            path = paths[j][i];
            for (int k = j + 1; k < size; k++)
            {
                if ((int)paths[k].size() <= i)
                {
                    continue;
                }
            
                if (paths[k][i].first == -1)
                {
                    continue;
                }
                
                if (path == paths[k][i])
                {
                    if (paths[j][i].first != -1)
                    {
                        paths[j][i] = { -1,-1 };
                    }
                    
                    paths[k][i] = { -1,-1 };
                }
            }

            if (paths[j][i].first == -1)
            {
                answer++;
            }
        }
    }

    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }

    int m;
    cin >> m;

    vector<vector<int>> routes(m);
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;

        vector<int> route(k);
        for (int j = 0; j < k; j++)
        {
            cin >> route[j];
        }

        routes.push_back(route);
    }

    int answer = solution(points, routes);

    cout << answer;
}