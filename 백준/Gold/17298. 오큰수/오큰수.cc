#include <iostream>
#include <stack>

using namespace std;

stack<int> sta;
int nums[1000001];
int ans[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
	}

	for (int i = 0; i < N; ++i)
	{
		if (sta.empty())
			sta.push(i);
		else
		{
			while(!sta.empty() && nums[i] > nums[sta.top()])
			{
				ans[sta.top()] = nums[i];
				sta.pop();
			}
			
			sta.push(i);
		}
	}

	for (int i = 0; i < N; ++i)
	{
		if (ans[i] == 0)
			cout << -1 << " ";
		else
			cout << ans[i] << " ";
	}

	return 0;
}