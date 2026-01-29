#include <iostream>
#include <vector>
#include <algorithm>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a, b;

    switch (n)
    {
        case 0:
        {
            cout << 0 << "\n\n" << 0 << "\n\n";
            
            break;
        }
        case 1:
        {
            a = {1};
            b = {2};

            break;
        }
        default:
        {
            int r = n % 3;

            switch (r)
            {
                case 0:
                {
                    for (int i = n; i >= 3; i -= 3)
                    {
                        b.push_back(i);
                        a.push_back(i - 1);
                        a.push_back(i - 2);
                    }

                    break;
                }
                case 1:
                {
                    for (int i = n; i >= 5; i -= 3)
                    {
                        b.push_back(i);
                        a.push_back(i - 1);
                        a.push_back(i - 2);
                    }

                    b.push_back(4);
                    a.push_back(1);
                    a.push_back(3);

                    break;
                }
                default:
                {
                    a.push_back(1);
                    b.push_back(2);
                    
                    for (int i = n; i >= 3; i -= 3)
                    {
                        b.push_back(i);
                        a.push_back(i - 1);
                        a.push_back(i - 2);
                    }

                    break;
                }
            }

            break;
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int size = (int)a.size();

    cout << size << "\n";

    for (int i = 0; i < size; i++)
    {
        cout << a[i] << (i + 1 == size ? '\n' : ' ');
    }
    
    if (a.empty())
    {
        cout << "\n";
    }

    size = (int)b.size();

    cout << size << "\n";

    for (int i = 0; i < size; i++)
    {
        cout << b[i] << (i + 1 == size ? '\n' : ' ');
    }
    
    if (b.empty())
    {
        cout << "\n";
    }

    return 0;
}