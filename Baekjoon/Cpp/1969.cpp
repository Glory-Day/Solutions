#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
	
    vector<string> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
	
    vector<char> ch;
    for(int i = 0; i < m; i++)
    {
        int arr[4] = { 0, };
        for(int j = 0; j < n; j++)
        {
            switch (v[j][i])
            {
                case 'A':
                    arr[0]++;
                    break;
                case 'C':
                    arr[1]++;
                    break;
                case 'G':
                    arr[2]++;
                    break;
                case 'T':
                    arr[3]++;
                    break;
            }
        }
		
        int idx;
        int mx = 0;
        for(int j = 0; j < 4; j++)
        {
            if(arr[j] > mx)
            {
                mx = arr[j];
                idx = j;
            }
        }
		
        switch (idx)
        {
            case 0:
                ch.push_back('A');
                break;
            case 1:
                ch.push_back('C');
                break;
            case 2:
                ch.push_back('G');
                break;
            case 3:
                ch.push_back('T');
                break;
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ch[j] != v[i][j])
            {
                cnt++;
            }
        }
    }
	
    for (int i = 0; i < (int)ch.size(); i++)
    {
        cout << ch[i];
    }
	
    cout << "\n";
    cout << cnt;
	
    return 0;
}