#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int,int> A;
    map<int,int> B;
    
    for (int i = 0; i < topping.size(); ++i)
        B[topping[i]]++;
    
	for (int i = 0; i < topping.size(); ++i)
    {
		A[topping[i]]++;
        B[topping[i]]--;
        if(B[topping[i]] == 0)
            B.erase(topping[i]);

		if (A.size() == B.size())
			++answer;
	}
    return answer;
}