#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, less<int>> PQ;
priority_queue<int, vector<int>, greater<int>> MQ;
queue<int> ZQ;
queue<int> OQ;
vector<int> vec;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;

		if(num == 1)
			OQ.push(num);
		else if(num > 0)
			PQ.push(num);
		else if(num <0)
			MQ.push(num);
		else
			ZQ.push(num);
	}

	while(MQ.size() > 1)
	{
		int a = MQ.top();
		MQ.pop();
		int b = MQ.top();
		MQ.pop();

		vec.push_back(a*b);
	}

	if(!MQ.empty() && ZQ.size() > 0)
	{
		MQ.pop();
		ZQ.pop();
	}

	while(!MQ.empty())
	{
		int a= MQ.top();
		MQ.pop();

		vec.push_back(a);
	}

	while(PQ.size() >= 2)
	{
		int a = PQ.top();
		PQ.pop();
		int b = PQ.top();
		PQ.pop();

		vec.push_back(a*b);
	}

	while(!PQ.empty())
	{
		int a= PQ.top();
		PQ.pop();

		vec.push_back(a);
	}

	while(!OQ.empty())
	{
		OQ.pop();
		vec.push_back(1);
	}
	

	int sum{};
	for (int i = 0; i < vec.size(); ++i)
	{
		sum += vec[i];
	}
	cout << sum;

	return 0;
}