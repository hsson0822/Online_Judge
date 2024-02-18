#include <iostream>

using namespace std;

int N;
int col[15];
int total = 0;

bool check(int level)
{
	for (int i = 0; i < level; ++i)
	{
		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)
			return false;
	}

	return true;
}

void queen(int x)
{
	if (x == N)
		++total;
	else
	{
		for (int i = 0; i < N ; ++i)
		{
			col[x] = i;
			if (check(x))
				queen(x + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	queen(0);
	cout << total;
	
	return 0;
}