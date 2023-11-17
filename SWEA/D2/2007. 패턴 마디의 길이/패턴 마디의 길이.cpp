#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
      	string str;
		cin >> str;
            
 
        int j;
        for(j = 2 ; j < str.size(); ++j)
        {
            string str1{str.begin() , str.begin()+j};
            string str2{str.begin()+j , str.begin()+j+j};
				
            if(str1 == str2)
                break;
        }
            
        cout << "#" << test_case << " " << j << "\n";
	}
	return 0;
}