//
// Created by hds on 11/12/19.
//
/**
 *实现一个 atoi 函数，使其能将字符串转换成整数。
 */

/**
 解题思路

 * */
#ifndef LEETCODE_T_H
#define LEETCODE_T_H

#include <iostream>
#include <vector>
using namespace std;
namespace t
{

void test()
{

  int f1(int x, int y) { return x > y ? x : y; }
  int f2(int x, int y) { return x > y ? y : x; }
  main()
  {
    int a = 4, b = 3, c = 5, d = 2, e, f, g;

    e = f2(f1(a, b), f1(c, d));

    f = f1(f2(a, b), f2(c, d));

    g = a + b + c + d - e - f;

    printf("%d,%d%d\n", e, f, g);
  }
}

} // namespace t
#endif //LEETCODE_T_H
