//
// Created by hds on 11/7/19.
//
/**
 *给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。
 */
#ifndef LEETCODE_L4_H
#define LEETCODE_L4_H

#include <iostream>
#include <vector>
using namespace std;
namespace l4{

    class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            return 0;
        }
    };

    void test(){
        Solution s = Solution();
        int a1[] = {1,3};
        int a2[] = {2};

        vector<int> n1(begin(a1),end(a1));
        vector<int> n2(begin(a2),end(a2));

        cout << s.findMedianSortedArrays(n1,n2) << endl;

    }

}
#endif //LEETCODE_L4_H
