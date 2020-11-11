#include<bits/stdc++.h>
using namespace std;

// Medium

// 暴力 BFS
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int size = s.size();
        queue<string> q;
        q.push(s);
        string ans = s;
        unordered_set<string> check;
        while(!q.empty())
        {
            string temp = q.front();
            q.pop();
            
            // 找到相同得字符串就直接跳过
            if(check.count(temp) == 1)  continue;
            else                        check.insert(temp);
            
            string c1 = temp;
            string c2 = temp;
            
            
            for(int i = 0; i < size; ++i)
            {
                c1[(i+b)%size] = temp[i];
            }

            for(int i = 1; i < size; i += 2)
            {
                int x = c2[i] - '0';
                int y = (x + a) > 9? (x+a)%10:x+a;
                c2[i] = y + '0';
            }
            
            q.push(c1);
            q.push(c2);
            
            string aux = c1 > c2 ? c2 : c1;
            
            ans = ans > aux ? aux : ans;
        }
        
        return ans;
    }
};