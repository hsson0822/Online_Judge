#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int hour1;
        int hour2;
        int min1;
        int min2;
        
        cin >> hour1 >> min1 >> hour2 >> min2;
        
        int hour = hour1 + hour2;
        int min = min1 + min2;
		
        if(min >= 60)
        {
            hour += min/60;
            min %= 60;
        }
        
        if(hour > 12)
        {
            hour -= 12;
        }

		cout << "#" << test_case << " " << hour << " " << min << "\n";
	}
	return 0;
}