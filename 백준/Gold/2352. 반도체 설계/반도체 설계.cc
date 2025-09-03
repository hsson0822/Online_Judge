#include <bits/stdc++.h>

using namespace std;

vector<int> port;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for(int i = 0 ; i < N ; ++i)
	{
		int n;
		cin >> n;

		port.push_back(n);
	}

	int cnt = 1;
	vector<int> connect;
	connect.push_back(port[0]);

	for(int i = 1; i < N ; ++i)
	{
		if(connect.back() < port[i])
		{
			++cnt;
			connect.push_back(port[i]);
		}
		else
		{
			int temp = lower_bound(connect.begin(), connect.end(), port[i]) - connect.begin();
			connect[temp] = port[i];
		}
	}

	cout <<connect.size();

	return 0;
}