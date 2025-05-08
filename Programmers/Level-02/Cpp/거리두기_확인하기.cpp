#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <utility>

using namespace std;

const pair<int, int> directions[4] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

bool check(int y, int x)
{
    return 0 <= y && y < 5 && 0 <= x && x < 5;
}

int bfs(vector<string> place)
{
    vector<bitset<5>> visited(5, bitset<5>(0));

    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (place[i][j] == 'P')
            {
                q.push({ { i,j },0 });
                visited[i][j] = true;

                while (q.empty() == false)
                {
                    auto nd = q.front();
                    q.pop();

                    for (const auto& d: directions)
                    {
                        int ny = nd.first.first + d.first;
                        int nx = nd.first.second + d.second;
                        int ncst = nd.second + 1;

                        if (check(ny, nx) == false || place[ny][nx] == 'X')
                        {
                            continue;
                        }

                        if (place[ny][nx] == 'P' && visited[ny][nx] == false)
                        {
                            if (ncst <= 2)
                            {
                                return 0;
                            }

                            visited[ny][nx] = true;

                            continue;
                        }


                        if (place[ny][nx] == 'O' && visited[ny][nx] == false)
                        {
                            q.push({ { ny,nx },ncst });
                            visited[ny][nx] = true;
                        }
                    }
                }

                for (int k = 0; k < 5; k++)
                {
                    visited[k].reset();
                }
            }
        }
    }

    return 1;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (int i = 0; i < (int)places.size(); i++)
    {
        answer.push_back(bfs(places[i]));
    }

    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<string>> places(n, vector<string>(5));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> places[i][j];
        }
    }

    vector<int> answer = solution(places);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}