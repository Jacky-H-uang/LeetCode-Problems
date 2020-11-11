#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;



class Solution {
public:
    int numSub(string s) 
    {
        int x = pow(10,9)+7;
        int len = s.size();
        long ans = 0;
        long count = 0;
        int p = 0;
        while(p<len)
        {
            if(s[p] == '1')
            {
                count++;
                p++;
            }
            else
            {
                int temp = (count+1)*count/2%x;
                ans += temp;
                p++;
                count = 0;
            }
        }
        int temp = (count+1)*count/2%x;
        ans = ans + temp;
        return ans;
    }
};


int main()
{
    Solution s;
    cout<<s.numSub("0110111")<<endl;
    system("pause");
    return 0;
}