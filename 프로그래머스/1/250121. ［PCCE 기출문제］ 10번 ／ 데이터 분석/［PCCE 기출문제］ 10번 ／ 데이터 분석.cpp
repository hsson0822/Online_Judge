#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Goods
{
public:
    int code;
    int date;
    int maximum;
    int remain;
    string sort;
    
    Goods(int c, int d, int m, int r, string s) : code(c), date(d), maximum(m), remain(r), sort(s)
    {};
    
    bool operator<(Goods& goods)
    {
        if(sort == "code")
        {
            return code < goods.code;
        }
        else if(sort == "date")
        {
            return date < goods.date;
        }
        else if(sort == "maximum")
        {
            return maximum < goods.maximum;
        }
        else
        {
            return remain < goods.remain;
        }
    }
    
};

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    vector<Goods> goods;
    
    for(int i = 0 ; i < data.size() ; ++i)
    {
        if(ext == "code")
        {
            if(data[i][0] > val_ext) continue;
        }
        else if(ext == "date")
        {
            if(data[i][1] > val_ext) continue;
        }
        else if(ext == "maximum")
        {
            if(data[i][2] > val_ext) continue;
        }
        else if(ext == "remain")
        {
            if(data[i][3] > val_ext) continue;
        }
            
        goods.push_back(Goods{data[i][0], data[i][1],data[i][2],data[i][3],sort_by});
    }
    
    sort(goods.begin(), goods.end());
    
    for(int i = 0 ; i < goods.size() ; ++i)
    {
        vector<int> vec;
        vec.push_back(goods[i].code);
        vec.push_back(goods[i].date);
        vec.push_back(goods[i].maximum);
        vec.push_back(goods[i].remain);
        answer.push_back(vec);
    }
    
    return answer;
}