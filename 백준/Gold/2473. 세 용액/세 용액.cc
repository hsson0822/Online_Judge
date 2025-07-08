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

long long N;
long long nums[5001];

long long answerNum = LLONG_MAX;
vector<long long> answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0 ; i < N ; ++i)
    {
        long long n;
        cin >> n;

        nums[i] = n;
    }
    
    sort(nums, nums+N);
    
    // int left = 0;
    // int right = 2;
    
    // while(left < right)
    // {
    //     //cout << "left: " << nums[left] << " right: " << nums[right] <<endl;
    //     int l = left+1;
    //     int r = right-1;
    //     int m = (l + r) / 2;
    //     while(l <= r)
    //     {
    //         long long sum = nums[left] + nums[right] + nums[m];
    //         //cout << "mid : " << nums[m] << endl;
    //         if(answerNum > abs(sum))
    //         {
    //             answerNum = abs(sum);
    //             answer.clear();
    //             answer.push_back(nums[left]);
    //             answer.push_back(nums[m]);
    //             answer.push_back(nums[right]);
    //         }
            
            
    //         if(sum < 0)
    //             l = m +1;
    //         else if(sum > 0)
    //             r = m- 1;
    //         else
    //         break;
            
    //         m = (l+r) /2;
    //     }

    //     long long sum = nums[left] + nums[right];

    //     if(sum <= 0)
    //         ++right;
    //     else if (sum > 0)
    //         ++left;
    //     //cout <<endl;

    // }

    for(int i = 0 ; i < N-2 ; ++i)
    {
        for(int j = i+2; j < N ; ++j)
        {
            long long sum = nums[i] + nums[j];
            int left = i+1;
            int right = j-1;
            int mid = (left+right)/2;

            //cout << "left: " << nums[i] << " right: " << nums[j] <<endl;
            while(left <= right)
            {
                long long sum = nums[i] + nums[j] + nums[mid];
                //cout << "mid : " << nums[mid] << endl;
                if(answerNum > abs(sum))
                {
                    answerNum = abs(sum);
                    answer.clear();
                    answer.push_back(nums[i]);
                    answer.push_back(nums[mid]);
                    answer.push_back(nums[j]);
                }
                
                
                if(sum < 0)
                    left = mid +1;
                else if(sum > 0)
                    right = mid- 1;
                else
                break;
                
                mid = (left+right) /2;
            }
            //cout << endl;
        }
    }

    for(int i = 0 ; i < 3 ; ++i)
    {
        cout << answer[i] << " ";
    }

    return 0;
}
