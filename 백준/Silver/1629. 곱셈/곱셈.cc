#include <iostream>

using namespace std;

long long A;
long long B;
long long C;

long long power(long long A, long long B, long long C)
{
	if (B == 0) return 1;
	long long half = power(A, B/2, C);
	half = (half * half) % C;
	if (B % 2 == 1)
		half = (half * A) % C;

	return half;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	cout << power(A, B, C) << "\n";
	
	return 0;
}