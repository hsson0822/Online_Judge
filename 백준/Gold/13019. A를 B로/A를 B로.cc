#include <iostream>
#include <algorithm>

using namespace std;

bool checkString(string A, string B)
{
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	if (A != B) return true;
	
	return false;

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string A;
	string B;
	cin >> A >> B;

	int answer{};

	if (A == B)
	{
		cout << 0;
		return 0;
	}

	if (checkString(A, B))
	{
		cout << -1;
		return 0;
	}

	int idx = A.size() - 1;

	for (int i = A.length() - 1; i >= 0; i--) {
		if (A[i] == B[idx]) idx--; // 두 문자가 같으면 문자열 B 인덱스 낮춤
		else answer++; // 다르면 앞으로 보내는 작용(문자열 B 인덱스 가만히 있음)
	}

	cout << answer;

	return 0;
}
