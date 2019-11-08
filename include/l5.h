//
// Created by hds on 11/8/19.
//

/**
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 */
#ifndef LEETCODE_L5_H
#define LEETCODE_L5_H

#include <iostream>
#include <string>
#include <map>
namespace l5 {
    using namespace std;
    class Solution {
    public:
        string longestPalindrome(string s) {
            int maxPlength = 1;
            int startPos = 0;
            for (int i = 1; i < s.size(); ++i) {
                if (isPalindrome(s,startPos,i)){
                    maxPlength = i - startPos +1;
                } else{

                }
            }
        }

    private:
        bool isPalindrome(string s,int start,int end){
            bool res = true;
            for (int i = start; i < (end-start)/2+1; i+=2) {
                if(s[i]!=s[start-end-1-i]){
                    res = false;
                    break;
                }
            }
            return res;
        }
    };

    void  test(){
        Solution s = Solution();
        string str("adbdsgbsd");

    }
}
#endif //LEETCODE_L5_H
