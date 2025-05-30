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

map<char, int> alpha;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		int answer = 0;
		int move = INT_MAX;
		int size = str.size();

		for (int i = 0; i < size; i++)
		{// 각 자리별로 단어 몇개 돌려야 하는지 계산
			answer += min(str[i] - 'A', 'Z' - str[i] + 1);
			if (str[i] != 'A') str[i] = 'B';
		}

		for (int i = 0, j; i < size; i++)
		{// 포인트 둘을 잡고 왔다 갔다 최소 계산
			j = find(str.begin() + i + 1, str.end(), 'B') - str.begin();
			int right = i * 2 + size - j;
			int left = i + (size - j) * 2;
			//cout << i << " " << j << ": " << right << " " << left << "\n";// 흐름이 잘 안보일때 추가해서 보면 이해하기 쉽다.
			move = min(move, min(left, right));
		}
		cout << answer + move << "\n";
		
	}

	return 0;
}
