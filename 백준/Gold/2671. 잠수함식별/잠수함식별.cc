#include <iostream>
#include <regex>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	cout << (regex_match(str, regex("(100+1+|01)+")) ? "SUBMARINE" : "NOISE") << endl;

	return 0;
}
