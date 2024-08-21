#include <iostream>

using namespace std;

int N;
int M;
int ground[100001];
int add[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		cin >> ground[i];
	}

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		int k;
		cin >> a >> b >> k;
        
		add[a] += k;
        add[b+1] -= k;
	}
    
	int sum{};
	for (int i = 1; i <= N; ++i)
	{
		sum += add[i];
		ground[i] += sum;
		cout << ground[i] << " ";
	}

	return 0;
}
