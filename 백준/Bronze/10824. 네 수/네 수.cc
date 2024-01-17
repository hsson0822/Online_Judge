#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long num{};

	for (int i = 0; i < 2; ++i)
	{
		string a;
		string b;
		cin >> a >> b;
		string n = a + b;

		num += stoll(n);
	} 

	cout << num;
}