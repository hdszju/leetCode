//
// Created by hds on 11/12/19.
//
/**
 *编写一个函数来验证输入的字符串是否是有效的 IPv4 或 IPv6 地址
 */

/**
 解题思路
 递归法

 * */
#ifndef LEETCODE_L468_H
#define LEETCODE_L468_H

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
namespace l468{
    class Solution {
    public:
        string validIPAddress(string IP) {
            if (isValidIPv4(IP)) return "IPv4"; 
            if (isValidIPv6(IP)) return "IPv6";
            return "Neither";
        }
        void split(const string s, vector<string>& vs, const char delim= ' '){
            istringstream iss(s);
            string temp;
            while (getline(iss,temp,delim)){
                vs.emplace_back(move(temp)); //使用移动而不是复制   插入到最后
            }
            if (!s.empty() && s.back() == delim) vs.push_back({});
            //加这句的原因是getline不会识别最后一个delim,避免误判"172.16.254.1.","2001:0db8:85a3:0:0:8A2E:0370:7334:"之类的情况
        }
        bool isValidIPv4(string IP) {
            vector<string> vs;
            split(IP,vs,'.');
            if (vs.size()!=4) return false;

            for (auto &v:vs){
                if(v.empty() || (v.size()>1 && v[0]=='0') || v.size()>3) return false;

                for(auto c:v){
                    if (!isdigit(c)) return false;                    
                }

                int n = stoi(v);
                if(n<0 || n>255) return false;
            }
            
            return true;
        }
        
        bool isValidIPv6(string IP) {
            vector<string> vs;
            split(IP,vs,':');
            if (vs.size()!=8) {                
                cout << vs.size() << " 大小不符合" << endl;
                return false;
            }

            for (auto &v:vs){
                if(v.empty() || v.size()>4) return false;

                for(auto c:v){
                    if (!(isdigit(c) || (c>='a' && c<='f') || (c>='A' && c<='F'))){
                        cout << c << " 不是符合条件的" << endl;
                     return false;                    
                    }
                }
            }
            
            return true;
        }
    };

    void test(){
        Solution s = Solution();
        
        string str("2001:0db8:85a3:0:0:8A2E:0370:7334");
        cout << s.validIPAddress(str) << endl;

    }

}
#endif //LEETCODE_L468_H
