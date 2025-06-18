#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
#include <math.h>
#include <cstring>

using namespace std;

int N;
int X;
int present[100001];
int mid;
int answer = INT_MAX;

int calcu()
{
	priority_queue<int,vector<int>,greater<int>> Q;
	int index = 0;

	while (Q.size() != mid)
	{
		//cout << present[index] << endl;
		Q.push(present[index++]);
	}

	//cout << endl;
	int t{};
	while (!Q.empty())
	{
		int num = Q.top();
		

		if (Q.top() <= num)
		{
			while (!Q.empty() && Q.top() <= num)
			{
				//cout <<"Out : " << Q.top() << endl;;
				Q.pop();
			}
			while (Q.size() != mid && index < N)
			{
				//cout << "Input : " << present[index] << endl;
				Q.push(num+present[index++]);
			}
		}
		t = max(t, num);
	}

	//cout << "Time : " << t <<endl;

	return t;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> X;

	for (int i = 0; i < N; ++i)
		cin >> present[i];

	int left = 1;
	int right = N;
	mid = N / 2;
	
	while (left <= right)
	{
		//cout << "start : " << mid << endl;
		mid = (left + right) / 2;
//		cout << left << " " << right << " = " << mid << endl;


		int T = calcu();

		if (T <= X)
		{
			right = mid-1;
			answer = min(answer, mid);
		}
		else
		{
			left = mid + 1;
		}

	}

	cout << answer;

	return 0;
}
