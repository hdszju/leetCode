//
// Created by hds on 11/7/19.
//
/**
 *给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。
 */

/**
 解题思路
 递归法

 * */
#ifndef LEETCODE_L4_H
#define LEETCODE_L4_H

// #define max(a,b) (((a) > (b)) ? (a) : (b))
// #define min(a,b) (((a) < (b)) ? (a) : (b))



#include <limits.h>
#include <iostream>
#include <vector>



using namespace std;

namespace l4{



// #define max(a,b) (((a) > (b)) ? (a) : (b))
// #define min(a,b) (((a) < (b)) ? (a) : (b))


    class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
		    int m = nums2.size();
            if (n > m)  //保证数组1一定最短
            {
                return findMedianSortedArrays(nums2, nums1); //交换
            }

            // Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
            int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n; //我们目前是虚拟加了'#'所以数组1是2*n长度

            while (lo <= hi)   //二分
            {
                c1 = (lo + hi) / 2;  //c1是二分的结果   
                c2 = m + n - c1;   //为什么必须有条件

                LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
                RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
                LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
                RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

                if (LMax1 > RMin2)
                    hi = c1 - 1;
                else if (LMax2 > RMin1)
                    lo = c1 + 1;
                else
                    break;
            }
            return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
        }
    };

    void test(){
        Solution s = Solution();
        int a1[] = {1,3,4,5,6};
        int a2[] = {2,3,7,9};

        vector<int> n1(begin(a1),end(a1));
        vector<int> n2(begin(a2),end(a2));

        cout << s.findMedianSortedArrays(n1,n2) << endl;

    }

}
#endif //LEETCODE_L4_H
