#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	set<int> se;

	for (int i = 0; i < N; ++i)
	{
		int k;
		cin >> k;
		se.insert(k);
	}

	for (int s : se)
		cout << s << " ";

	return 0;
}
