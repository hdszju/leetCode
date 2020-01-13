// #include <iostream>
// #include "include/l4.h"
// #include "include/l5.h"
// #include "include/l6.h"
// #include "include/l7.h"
// #include "include/l8.h"
// #include "include/l468.h"
// #include "include/t.h"
// int main() {
// //    l4::test();
//     cout << "-----------------------t----------------------------" << endl;
//     t::test();

//     int i =0;
//     cin >> i;
//     return 0;
// }

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string str,c;
    cin >> str >> c;
    // getline(cin,str);
    // getline(cin,c);
    int count = 0;
    int length = abs('A' - 'a');
    cout << length << ' :: '<< sizeof(str) << endl;
    for(int i=0; i<sizeof(str);i++){
        if(str[i]==c[0] || abs(str[i]-c[0])==length) count++;
    }
    cout << count << endl;
    return 0;
}