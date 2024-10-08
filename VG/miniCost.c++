#include <bits/stdc++.h>
using namespace std;
// string calculateSum(const vector<string>& s, int m) {
//     bool is_sum_odd = false; 

   
//     for (const string& str : s) {
       
//         for (char c : str) {
//             int ascii_value = static_cast<int>(c);  
            
           
//             if (ascii_value % 2 != 0) {
              
//                 if (m % 2 != 0) {
//                     is_sum_odd = !is_sum_odd; 
//                 }
//             }
//         }
        
     
//         if (is_sum_odd) {
//             return "ODD";
//         }
//     }

    
//     return is_sum_odd ? "ODD" : "EVEN";
// }


int main() {
    vector<string> s = {"azbde", "abcher","acegk"};
    int m = 2;
    cout << calculateSum(s, m) << endl;  
    return 0;
}