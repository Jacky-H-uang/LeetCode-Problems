//                                      127. Word Ladder
//
// Given two words (beginWord and endWord), and a dictionary's word list, 
// find the length of shortest transformation sequence from beginWord to endWord, such that:
// Only one letter can be changed at a time.
// Each transformed word must exist in the word list.
//
// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.
//
// Example 1:
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
//
// Example 2:
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
// Output: 0
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.


#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    unordered_set<string> checked;
    unordered_set<string> wordset;
    queue<string> q;
    int wordLen;
    int step = 1;

    // 标准的 bfs 的框架
    int bfs(string beginWord, string endWord, vector<string>& wordList)
    {
        q.push(beginWord);
        checked.insert(beginWord);
        while(!q.empty())
        {
            int curSize = q.size();
            for(int i = 0; i < curSize; ++i)
            {
                string word = q.front();
                q.pop();
                for(int j = 0; j < wordLen; ++j)
                {
                    char originalC = word[j];
                    for(char k = 'a'; k <= 'z'; k++)
                    {
                        if(k == originalC)      continue;
                        word[j] = k;
                        string nextword = word;
                        if(wordset.count(nextword) == 1)
                        {
                            if(nextword == endWord)     return step+1;
                            if(!checked.count(nextword))
                            {
                                q.push(nextword);
                                checked.insert(nextword);
                            }
                        }
                    }
                    word[j] = originalC;
                }
            }
            step++;
        }

        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordLen = beginWord.size();

        for(auto& i : wordList)     wordset.insert(i);   
        wordset.erase(beginWord);
        if(wordset.count(endWord) == 0)     return 0;

        return bfs(beginWord , endWord , wordList);
    }
};