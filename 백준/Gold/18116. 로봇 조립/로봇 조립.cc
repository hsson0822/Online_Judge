#include <iostream>

using namespace std;

int parent[1000001];
int Size[1000001];

int getParent(int a)
{
	if (a == parent[a]) return a;
	return parent[a] = getParent(parent[a]);
}

void Union(int a, int b)
{
	int na = getParent(a);
	int nb = getParent(b);

	if (na < nb)
	{
		parent[nb] = na;
		Size[na] += Size[nb];
		Size[nb] = 0;

	}
	else
	{
		parent[na] = nb;
		Size[nb] += Size[na];
		Size[na] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 1000001; ++i)
	{
		parent[i] = i;
		Size[i] = 1;
	}

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		char ch;
		cin >> ch;

		if (ch == 'I')
		{
			int a;
			int b;
			cin >> a >> b;

			if(getParent(a) != getParent(b))
				Union(a, b);
			
		}
		else
		{
			int a;
			cin >> a;

			cout << Size[getParent(a)] << "\n";
		}
	}
	
	return 0;
}