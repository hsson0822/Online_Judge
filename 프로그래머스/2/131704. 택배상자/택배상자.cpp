#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> li) {
    int answer = 0;
    int last = 0;
    
    stack<int> order;
    stack<int> contain;
    
    for (int i = li.size()-1; i >=0; --i)
        order.push(i+1);

    while (true)
    {
        if (contain.size() != 0 && contain.top() == li[last])
        {
            int n = contain.top();
            contain.pop();
            ++last;
            ++answer;
            continue;
        }

        if (order.size() != 0)
        {
            if (order.top() == li[last])
            {
                int n = order.top();
                order.pop();
                ++last;
                ++answer;
                continue;
            }
            else
            {
                int n = order.top();
                order.pop();
                contain.push(n);
                continue;
            }
        }

        break;
    }
    
    return answer;
}