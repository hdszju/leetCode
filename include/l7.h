//
// Created by hds on 11/12/19.
//
/**
 *给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 */

/**
 解题思路

 * */
#ifndef LEETCODE_L7_H
#define LEETCODE_L7_H



#include <iostream>
#include <vector>
using namespace std;
namespace l7{
    class Solution {
    public:
        int reverse(int x) {
            int rev = 0;
            while (x != 0)
            {
                int pop = x%10;
                x /= 10;
                if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
                if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
                rev = rev*10 + pop;                
            }
            
            return rev;
        }
    };

    void test(){
        Solution s = Solution();
        
        cout << s.reverse(-123) << endl;

    }

}
#endif //LEETCODE_L7_H
