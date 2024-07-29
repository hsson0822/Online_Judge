#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int small[500001];
int big[500001];
vector<int> l, r;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int a;
		int b;
		cin >> a >> b;
		small[i] = a - b;
		big[i] = a + b;

		l.push_back(a - b);
		r.push_back(a + b);
	}
	
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());

	for (int i = 0; i < N; ++i)
	{
		cout << lower_bound(r.begin(), r.end(), small[i]) - r.begin() +1;
		cout << " ";
		cout << upper_bound(l.begin(), l.end(), big[i]) - l.begin() << "\n";
	}

	return 0;
}