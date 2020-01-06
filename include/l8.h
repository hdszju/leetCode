//
// Created by hds on 11/12/19.
//
/**
 *实现一个 atoi 函数，使其能将字符串转换成整数。
 */

/**
 解题思路

 * */
#ifndef LEETCODE_L8_H
#define LEETCODE_L8_H



#include <iostream>
#include <vector>
using namespace std;
namespace l8{
    class Solution {
    public:
        int myAtoi(string str) {

            return 0;        
        }
    };

    void test(){
        Solution s = Solution();
        // cout << INT_MIN << "  " << INT_MAX << endl;  //-2147483648  2147483647
        // 1534236469
        // 2147483647
        // cout << sizeof(int) << endl;
        string str("4193 with words");
        cout << s.myAtoi(str) << endl;

    }

}
#endif //LEETCODE_L8_H
