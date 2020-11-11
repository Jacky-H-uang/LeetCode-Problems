//                  79. 单词搜索
//
// 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
// 同一个单元格内的字母不允许被重复使用。
//
//  
// 示例:
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
// 给定 word = "ABCCED", 返回 true
// 给定 word = "SEE", 返回 true
// 给定 word = "ABCB", 返回 false
//  
//
// 提示：
// board 和 word 中只包含大写和小写英文字母。
// 1 <= board.length <= 200
// 1 <= board[i].length <= 200
// 1 <= word.length <= 10^3


#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    int len;
    vector<vector<int>> visited;
    int dir[4][4]={{-1,0},{1,0},{0,-1},{0,1}};

    bool dfs(int x,int y, int pos,vector<vector<char>>& board,string& word)
    {
        if(pos == len-1)
        {
            return word[pos] == board[x][y];
        }

        if(word[pos]==board[x][y])
        {
            visited[x][y]=true;
            for(int i=0;i<4;i++)
            {
                int new_x=x+dir[i][0];
                int new_y=y+dir[i][1];
                
                if(new_x >= 0 && new_x < board.size() && new_y >=0 && new_y < board[0].size() && !visited[new_x][new_y])
                {
                    if(dfs(new_x,new_y,pos+1,board,word))
                    {
                        return true;
                    }
                }
            }
            visited[x][y]=false;
        }

        return false;
    }
    
    bool exist(vector<vector<char>>& board,string word)
    {
        this->len = word.size();
        visited.resize(board.size(),vector<int>(board[0].size()));
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(dfs(i,j,0,board,word))
                {
                    return true;
                }
            }
        }

        return false;
    }
};