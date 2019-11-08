//
// Created by hds on 11/7/19.
//
/**
 *给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 */
#ifndef LEETCODE_L3_H
#define LEETCODE_L3_H

#include <iostream>
#include <string>
#include <map>
namespace l3{
    using namespace std;

    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            map<char,int> m;  //store s
            int maxLength = 0;
            int lastRepeatPos = -1;
            for (int i = 0; i < s.size(); ++i) {
                if(m.find(s[i]) != m.end() && lastRepeatPos<m[s[i]]) {
                    lastRepeatPos = m[s[i]];
                }
                if (i-lastRepeatPos > maxLength){
                    maxLength = i-lastRepeatPos;
                }
                m[s[i]] = i;
            }
            return maxLength;
        }
    };

    int test(){
        Solution s = Solution();
        string str("adbdsgbsd");
        return s.lengthOfLongestSubstring(str);
    }
}

#endif //LEETCODE_L3_H
