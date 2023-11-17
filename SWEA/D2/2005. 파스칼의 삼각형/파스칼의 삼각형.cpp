#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int size;
        cin >> size;
        
        vector<vector<int>> triangle;
        
        for(int i = 0 ; i < size ; ++i)
        {
            vector<int> v;
         	for(int j = 0 ; j < size ; ++j)
        		v.push_back(0);   
            triangle.push_back(v);
        }
        
        triangle[0][0] = 1;
        
        for(int i = 1 ; i < size ; ++i)
        {
            for(int j = 0 ; j <= i ; ++j)
            {
                if(j-1 >= 0)
                    triangle[i][j] += triangle[i-1][j-1];
                
                triangle[i][j] += triangle[i-1][j];
            }
        }

		cout << "#" << test_case << "\n";
        for(int i = 0 ; i < size ; ++i)
        {
            for(int j = 0 ; j <= i ; ++j)
            {
                cout << triangle[i][j] << " "; 
            }
            cout << "\n";
        }
	}
	return 0;
}