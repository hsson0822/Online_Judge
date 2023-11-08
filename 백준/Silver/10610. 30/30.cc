#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string num;
	cin >> num;

	sort(num.rbegin(), num.rend());

	int sum{};

	for (char ch : num)
		sum += ch - '0';

	if (sum % 3 || num[num.size() - 1] != '0')
		cout << -1;
	else
		cout << num;
}