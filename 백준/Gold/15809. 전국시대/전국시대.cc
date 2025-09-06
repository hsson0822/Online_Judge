#include <bits/stdc++.h>

using namespace std;

int N, M;
int warrior[100001];
int parent[100001];

int Find(int a)
{
	if (a == parent[a])
		return a;

	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	if (warrior[pa] >= warrior[pb])
	{
		parent[pb] = pa;
		warrior[pa] += warrior[pb];
		warrior[pb] = 0;
	}
	else
	{
		parent[pa] = pb;
		warrior[pb] += warrior[pa];
		warrior[pa] = 0;
	}
}

void War(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	if(warrior[pa] > warrior[pb])
	{
		parent[pb] = pa;
		warrior[pa] -= warrior[pb];
		warrior[pb] = 0;
	}
	else if(warrior[pa] < warrior[pb])
	{
		parent[pa] = pb;
		warrior[pb] -= warrior[pa];
		warrior[pa] = 0;
	}
	else
	{
		parent[pa] = -1;
		parent[pb] = -1;
		warrior[pa] = 0;
		warrior[pb] = 0;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		cin >> warrior[i];
		parent[i] = i;
	}

	for (int i = 0; i < M; ++i)
	{
		int o, p, q;
		cin >> o >> p >> q;

		if (o == 1)
		{
			Union(p, q);
		}
		else
		{
			War(p, q);
		}
	}

	int answer{};
	vector<int> warriors;

	for(int i = 1 ; i <= N ; ++i)
	{
		int cur = Find(i);
		if(i == cur)
		{
			++answer;
			warriors.push_back(warrior[i]);
		}
	}

	sort(warriors.begin(), warriors.end());

	cout <<answer << "\n";
	for(int i = 0 ; i < warriors.size() ; ++i)
	{
		if(warriors.size() != 0)
			cout << warriors[i] << " ";
	}


	return 0;
}