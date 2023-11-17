#include<iostream>
#include<map>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        map<int,int,greater<int>> moneyCount;
        moneyCount[50000] = 0;
		moneyCount[10000] = 0;
		moneyCount[5000] = 0;
		moneyCount[1000] = 0;
		moneyCount[500] = 0;
		moneyCount[100] = 0;
		moneyCount[50] = 0;
		moneyCount[10] = 0;
        
		int money;
        cin >> money;
        
        for(auto& m : moneyCount)
        {
            
            if( money < m.first) continue;
            
            m.second =  money / m.first;
            money %= m.first;
        }
        
        cout << "#" << test_case << "\n";
        for(auto m : moneyCount)
			cout << m.second << " ";
        cout << "\n";

	}
	return 0;
}