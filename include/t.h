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
#include <string>
using namespace std;
namespace t
{

void test()
{
    string str;
    
    // cin >> str;
    getline(cin,str);
    cout << str << endl;
    int maxLength = 0;
    for(int i=str.size()-1;i>=0;i--){
      count << str[i] << endl;
        if(str[i]==' '){
            break;
        }else{
            maxLength++;                
        }
    }
    cout << maxLength << endl;
    return ;
}

} // namespace t
#endif //LEETCODE_T_H
