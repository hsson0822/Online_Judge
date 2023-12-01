#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    
    int i;
    for(i = 1 ; i <= n/2 ; ++i )
    {
        if(a%2 == 1) a+=1;
        if(b%2 == 1) b+=1;
        
        if(a/2 == b/2)
        {
            break;
        }
        else
        {
            a += 1;
            a /= 2;
            
            b /= 2;
        }

    }
    answer = i;
    return answer;
}