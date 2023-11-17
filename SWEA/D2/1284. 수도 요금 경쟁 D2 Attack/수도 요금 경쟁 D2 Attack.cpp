#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int AFee;
        int BFee;
        
        int AL;
        int BBase;
        int BLine;
        int BOver;
        int useWater;
        
        cin >> AL >> BBase >> BLine >> BOver>> useWater;
        
        AFee = AL * useWater;
        
        if(BLine >= useWater)
            BFee = BBase;
        else
            BFee = BBase + (BOver * (useWater - BLine));

        int min{};
        if(AFee < BFee)
            min = AFee;
        else
            min = BFee;
        
		cout << "#" << test_case << " " << min << "\n";
	}
	return 0;
}