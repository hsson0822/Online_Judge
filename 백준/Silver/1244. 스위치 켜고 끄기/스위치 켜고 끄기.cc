#include <iostream>

using namespace std;

int leng;
int cnt;
int swit[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> leng;

	for (int i = 1; i <= leng; ++i)
	{
		int k;
		cin >> k;
		swit[i] = k;
	}

	cin >> cnt;

	for (int i = 0; i < cnt; ++i)
	{
		int a;
		int b;
		cin >> a >> b;

		if (a == 1)
		{
			for (int i = b; i <= leng; i += b)
			{
				if (swit[i])
					swit[i] = false;
				else
					swit[i] = true;
			}
		}
		else if (a == 2)
		{
			if (swit[b])
				swit[b] = false;
			else
				swit[b] = true;

			int j = b;
			int k = b;
			while (true)
			{

				--j;
				++k;

				if (j <= 0 || k > leng) break;
				
				if (swit[j] == swit[k])
				{
					if (swit[j])
					{
						swit[j] = false;
						swit[k] = false;
					}
					else
					{
						swit[j] = true;
						swit[k] = true;
					}
				}
				else
					break;
			}
		}
	}

	for (int i = 1; i <= leng; ++i)
    {
	    cout << swit[i] << " ";

	    if (i % 20 == 0)
		    cout << endl;
    }


	return 0;
}