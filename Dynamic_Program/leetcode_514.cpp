//                                                  514. Freedom Trail
// In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", 
// and use the dial to spell a specific keyword in order to open the door.
// Given a string ring, which represents the code engraved on the outer ring and another string key, 
// which represents the keyword needs to be spelled. 
// You need to find the minimum number of steps in order to spell all the characters in the keyword.
// Initially, the first character of the ring is aligned at 12:00 direction. 
// You need to spell all the characters in the string key one by one by rotating the ring clockwise 
// or anticlockwise to make each character of the string key aligned at 12:00 direction and then by pressing the center button.
// At the stage of rotating the ring to spell the key character key[i]:
// You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. 
// The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, 
// where this character must equal to the character key[i].
// If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell,
// which also counts as 1 step. After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling.
//
//
// Example: 
// Input: ring = "godding", key = "gd"
// Output: 4
// Explanation:
// For the first key character 'g', since it is already in place, we just need 1 step to spell this character. 
// For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
// Also, we need 1 more step for spelling.
// So the final output is 4.
//
//
// Note:
// Length of both ring and key will be in range 1 to 100.
// There are only lowercase letters in both strings and might be some duplcate characters in both strings.
// It's guaranteed that string key could always be spelled by rotating the string ring.


#include<bits/stdc++.h>
using namespace std;

// Hard
// 定义 dp[i][j] 表示从前往后拼写出 key 的第 i 个字符， 
// ring 的第 j 个字符与 12:00 方向对齐的最少步数（下标均从 0 开始）。

class Solution {
public:
    int findRotateSteps(string ring, string key) 
    {
        int n = ring.size(), m = key.size();
        vector<int> pos[26];
        for (int i = 0; i < n; ++i) 
        {
            pos[ring[i] - 'a'].push_back(i);
        }
        int dp[m][n];
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        for (auto& i: pos[key[0] - 'a']) 
        {
            dp[0][i] = min(i, n - i) + 1;
        }
        for (int i = 1; i < m; ++i) 
        {
            for (auto& j: pos[key[i] - 'a']) 
            {
                for (auto& k: pos[key[i - 1] - 'a']) 
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
                }
            }
        }
        return *min_element(dp[m - 1], dp[m - 1] + n);
    }
};