#include <iostream>

using namespace std;

int N;
bool light[100002];
bool light2[100002];
bool want[100002];
int answer=-1;

void push(bool light[], int idx)
{
	light[idx-1] = !light[idx-1];
	light[idx] = !light[idx];
	light[idx+1] = !light[idx+1];
}

bool run(bool light[], int &temp)
{
	int ans = 0;

	for (int i = 2; i <= N; i++)
	{
		if (light[i - 1] != want[i - 1])
		{
			push(light, i);
			ans++;
		}
	}

	temp = ans;

	for (int i = 1; i <= N; i++)
	{
		if (light[i] != want[i])
		{
			return false;
		}
	}

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		char ch;
		cin >> ch;
		if (ch == '1')
			light2[i] = light[i] = true;
		else
			light2[i] = light[i] = false;
	}

	for (int i = 1; i <= N; ++i)
	{
		char ch;
		cin >> ch;
		if (ch == '1')
			want[i] = true;
		else
			want[i] = false;
	}

	int temp{};
	if (run(light, temp))
	{
		if (answer == -1)
			answer = temp;
		else
			answer = min(answer, temp);
	}

	push(light2, 1);
	temp = 1;

	if (run(light2, temp))
	{
		++temp;
		if (answer == -1)
			answer = temp;
		else
			answer = min(answer, temp);
	}
	
	cout << answer;

	return 0;
}
