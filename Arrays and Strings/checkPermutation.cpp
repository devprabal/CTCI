#include <algorithm>
#include <iostream>
using namespace std;
bool checkPermutation(string a, string b);
int main() {
  string a, b;
  cin >> a >> b;
  cout << (checkPermutation(a, b) ? "true" : "false");
  return 0;
}
/* method 1
O(n) space, counting frequency of each character
O(n) time
*/
// bool checkPermutation(string a , string b){
//// assuming the strings contain ascii values
//     if(a.length()!=b.length())
//         return false;
//     else{
//         int freq[128]={0};
//         for(int i =0;i<a.length();i++){
//             freq[(int)a[i]]++;
//         }
//         for(int i =0;i<b.length();i++){
//             freq[(int)b[i]]--;
//         }
//         for(int i =0;i<128;i++){
//             if(freq[i]!=0)
//                 return false;
//         }
//         return true;
//     }
// }
//  ﭱ   
//  ﭱ   
/* method 2
O(n square) time
for each char in a, mark that corresponding char in b as #
in the end, if all chars in b are # (or the count of all corresponding findings
is equal to the length of string then return true)
*/
// bool checkPermutation(string a, string b) {
//   // assuming the strings contain a-zA-Z0-9
//   if (a.length() != b.length())
//     return false;
//   else {
//     int count_letters = 0;
//     for (int i = 0; i < a.length(); i++) {
//       bool found = false;
//       for (int j = 0; j < b.length(); j++) {
//         if (b[j] == a[i]) {
//           found = true;
//           count_letters++;
//           b[j] = '#'; // a symbol which is not in the string
//         }
//       }
//       if (found == false)
//         return false;
//     }
//     if (count_letters != a.length())
//       return false;
//     else
//       return true;
//   }
// }
//  ﭱ   
//  ﭱ   
//
/* method 3
sort the strings and compare them
O(n log n) time
*/
bool checkPermutation(string a, string b) {
  // assuming the strings contain a-zA-Z0-9
  if (a.length() != b.length())
    return false;
  else {
    sort(a.begin(), a.end()); // O(n log n)
    sort(b.begin(), b.end());
    for (int i = 0; i < a.length(); i++) { // O(n)
      if (a[i] != b[i])
        return false;
    }
    return true;
  }
}