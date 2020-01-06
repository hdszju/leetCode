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
            int res = 0;
            int flag = 1;
            int i = 0;
            //检测空格
            while (str[i]==' ') i++;  // 2. 检查符号
            if (str[i] == '-') { flag = -1; }
            if (str[i] == '+' || str[i] == '-') { i++; }
            // 3. 计算数字
            while (i < str.size() && isdigit(str[i])) {
                int r = str[i] - '0';
                // ------ 4. 处理溢出，这是关键步骤 ------
                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7)) { 
                    return flag > 0 ? INT_MAX : INT_MIN;
                }
                // ------------------------------------
                res = res * 10 + r;
                i++;
            }
            return flag > 0 ? res : -res;
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
