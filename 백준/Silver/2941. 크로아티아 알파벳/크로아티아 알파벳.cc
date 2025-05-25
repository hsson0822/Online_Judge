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

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    vector<string> croatian = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
    int idx;
    string str;
    cin >> str;
    for (int i = 0; i < croatian.size(); i++)
    {
        while (1) {
            idx = str.find(croatian[i]);
            if (idx == string::npos)
                break;
            str.replace(idx, croatian[i].length(), "#");
        }
    }
    cout << str.length();

	return 0;
}
