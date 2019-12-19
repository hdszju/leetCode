//
// Created by hds on 11/12/19.
//
/**
 *将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列
 */

/**
 解题思路
 递归法

 * */
#ifndef LEETCODE_L6_H
#define LEETCODE_L6_H



#include <iostream>
#include <vector>
using namespace std;
namespace l6{
    class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows==1) return s;            

            vector<string> rows(min(numRows,int(s.size())));
            int curRow = 0;
            bool goingDown = false;

            for(char c:s){
                rows[curRow] += c;   //追加

                if (curRow==0 || curRow==numRows-1) goingDown = !goingDown;  //翻转                
                curRow += goingDown?1:-1;   
            }

            //拼接
            string ret;
            for(string row:rows) ret += row;
            return ret;
        }
    };

    void test(){
        Solution s = Solution();
        
        string str("LEETCODEISHIRING");
        cout << s.convert(str,3) << endl;

    }

}
#endif //LEETCODE_L6_H
