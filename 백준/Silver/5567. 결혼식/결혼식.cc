#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> fr[500];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int M;
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		cin >> a >> b;
		fr[a].push_back(b);
		fr[b].push_back(a);
	}

	set<int> invite;

	for (int i = 0; i < fr[1].size(); ++i)
	{
		int k = fr[1][i];
		invite.insert(k);

		for (int j = 0; j < fr[k].size(); ++j)
			invite.insert(fr[k][j]);
	}
	
	invite.erase(1);

	cout << invite.size();

	return 0;
}