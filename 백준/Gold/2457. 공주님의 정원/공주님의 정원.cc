#include <bits/stdc++.h>

using namespace std;

int monthDay[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int calcuDay(int m, int d)
{
	int num{};

	for (int i = 1; i < m; ++i)
		num += monthDay[i];

	num += d;

	return num;
}

struct Flower
{
	int sday{};
	int eday{};
};

int N;
int cur;
int target;

vector<Flower> flowers;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{

		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;

		// cout <<sm << " " << sd << " " << em << " " << ed << endl;

		int sday = calcuDay(sm, sd);
		int eday = calcuDay(em, ed);

		flowers.push_back({sday, eday});
	}

	sort(flowers.begin(), flowers.end(), [](Flower &a, Flower &b)
		 {
        if (a.sday == b.sday)
			return a.eday > b.eday;
		
        return a.sday < b.sday; 
	});

	cur = calcuDay(3, 1);
	target = calcuDay(11, 30);
	int idx{};
	int answer{};

	while (cur <= target)
	{
		int maxEnd = cur;

		while (idx < N && flowers[idx].sday <= cur)
		{
			maxEnd = max(maxEnd, flowers[idx].eday);
			++idx;
		}

		if (maxEnd == cur)
		{
			cout << 0;
			return 0;
		}

		cur = maxEnd;
		++answer;
		if (cur > target)
			break;
	}

	cout << answer;

	return 0;
}