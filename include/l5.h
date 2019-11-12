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
            for (int j = 0; j < s.size(); ++j) {
                for (int i = j+1; i < s.size(); ++i) {
                    if (isPalindrome(s,j,i)){
                        if (maxPlength < i - j +1){
                            maxPlength = i - j +1;
                            cout<< "maxPlength is " << maxPlength << " (i,j)"<< i<<","<<j<< endl;
                        }
                    } else{
                        cout<< "is not" << endl;

                    }
                }
            }
            return  s;
        }

    private:
        bool isPalindrome(string s,int start,int end){
            bool res = true;
            for (int i = start; i < end/2; i++) {
                cout << s[i] << " " <<i << " " << end-i << " " << s[end-i] << endl;
                if(s[i]!=s[end-i]){
                    res = false;
                    break;
                }
            }
            return res;
        }
    };

    void  test(){
        Solution s = Solution();
        string str("aba0k00a1");
        s.longestPalindrome(str);

    }
}
#endif //LEETCODE_L5_H
