//                              406. Queue Reconstruction by Height
//
// Suppose you have a random list of people standing in a queue. 
// Each person is described by a pair of integers (h, k), 
// where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. 
// Write an algorithm to reconstruct the queue.
//
// Note:
// The number of people is less than 1,100.
//
// 
// Example
// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]


#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(),people.end(),[](const vector<int>& o1 , const vector<int>& o2){
            return o1[0] == o2[0] ? o1[1] < o2[1] : o1[0] > o2[0];
        });
        
        // Trick
        for(auto& p : people)
        {
            int len = ans.size();
            if(p[1] >= len)      ans.push_back(p);
            else                 ans.insert(ans.begin()+p[1],p);
        }
        

        return ans;
    }
};