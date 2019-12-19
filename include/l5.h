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
#include <vector>
namespace l5 {
    using namespace std;
    class Solution {
    public:
        string longestPalindrome(string s) {
            string T;// Transform S to T        ie: #a#  #a#b#
            for(int i=0;i<s.size();i++)
                T+="#"+s.substr(i,1);
            T.push_back('#');

            vector<int> P(T.size(),0); // Array to record longest palindrome
            int center=0,boundary=0,maxLen=0,resCenter=0;

            for(int i=1;i<T.size()-1;i++) {
                int iMirror=2*center-i; // calc mirror i = center-(i-center)
                P[i]=(boundary>i)?min(boundary-i,P[iMirror]):0;

                while(i-1-P[i]>=0&&i+1+P[i]<=T.size()-1&&T[i+1+P[i]] == T[i-1-P[i]]) // Attempt to expand palindrome centered at i
                    P[i]++;

                if(i+P[i]>boundary) { // update center and boundary
                    center = i;
                    boundary = i+P[i];
                }
                
                if(P[i]>maxLen) { // update result
                    maxLen = P[i];
                    resCenter = i;
                }  

            }
            
            return s.substr((resCenter - maxLen)/2, maxLen);

            // int maxPlength = 1;
            // int startPos = 0;
            // for (int j = 0; j < s.size(); ++j) {
            //     for (int i = j+1; i < s.size(); ++i) {
            //         if (isPalindrome(s,j,i)){
            //             if (maxPlength < i - j +1){
            //                 maxPlength = i - j +1;
            //                 startPos = j;
            //             }
            //         }
            //     }
            // }
            // return  s.substr(startPos,maxPlength);            
        }

    private:
        string lcs(string& s){
              vector<vector<int>> table(s.size(),vector<int>(s.size(),0));
//            for (int i = 0; i < s.size(); ++i) {
//                if (table[][])
//            }
        };
        bool isPalindrome(string& s,int start,int end){
            bool res = true;
//            int width = end - start + 1;
//            int middle = width/2;
            for (int i = 0; i < (end - start + 1)/2; i++) {
                if(s[start+i]!=s[end-i]){
                    res = false;
                    break;
                }
            }
            return res;
        }
    };

    void  test(){
        Solution s = Solution();
//        string str("jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx");
        string str("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg");
        cout << s.longestPalindrome(str) << endl;

    }
}
#endif //LEETCODE_L5_H
