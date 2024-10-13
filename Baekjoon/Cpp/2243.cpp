#include <iostream>

#define MAX 1000001

using namespace std;

int matrix[MAX * 4];

void update(const int i, const int node, const int d, const int b, const int e)
{
	if (b > node || node > e)
    {
        return;
    }

    matrix[i] += d;

    if (b == e)
    {
        return;
    }

	int m = (b + e) / 2;
    update(i * 2, node, d, b, m);
    update(i * 2 + 1, node, d, m + 1, e);
}


const int query(const int i, const int node, const int b, const int e)
{	
    if (b == e)
    {
        return b;
    }

    int result;
    int m = (b + e) / 2;
    if (node <= matrix[i * 2])
    {
        result = query(i * 2, node, b, m);
    }
    else
    {
        result = query(i * 2 + 1, node - matrix[i * 2], m + 1, e);
    }

    return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
	cin >> n;

	for (int i = 0; i < n; i++) 
    {
		int a, b, c;
		cin >> a >> b;
		
		if (a == 1)
        {
			int result = query(1, b, 1, MAX);
			update(1, result, -1, 1, MAX);

            int answer = result;

            cout << answer << '\n';
		}
		else
        {
			cin >> c;

			update(1, b, c, 1, MAX);
		}
	}

	return 0;
}