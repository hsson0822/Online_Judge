#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int student[300001];

class Diff
{
public:
	int a;
	int b;
	int w;

	Diff(int a, int b, int w) : a(a), b(b), w(w)
	{

	}

	bool operator<(Diff& d)
	{
		return w < d.w;
	}
};

vector<Diff> dif;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int K;
	cin >> N >> K;

	for (int i = 0; i < N; ++i)
		cin >> student[i];

	for (int i = 0; i < N - 1; ++i)
	{
		dif.push_back(Diff{ student[i], student[i + 1], student[i + 1] - student[i] });
	}
	
	sort(dif.begin(), dif.end());

	int answer{};
	for (int i = 0; i < dif.size() - (K - 1); ++i)
		answer += dif[i].w;

	cout << answer;

	return 0;
}