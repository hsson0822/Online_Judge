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

typedef struct Line
{
	int a;
	int b;
} Line;

int Start, End, answer;
Line arr[1'000'001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;

		arr[i] = {a, b};
	}

	sort(arr, arr + N, [](auto &A, auto &B)
		 { return A.a < B.a; });

	Start = End = INT_MIN;

	for (int i = 0; i < N; i++)
	{
		if (End < arr[i].a)
		{
			answer += End - Start;
			Start = arr[i].a;
		}

		if (End < arr[i].b)
			End = arr[i].b;
	}
	answer += End - Start;
	cout << answer;

	return 0;
}