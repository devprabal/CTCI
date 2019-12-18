#include <cstring>
#include <iostream>
using namespace std;
/* method 1
using freq count
time complexity O(n)
space complexity O(n)
*/
// bool palindromePerm(string s) {
//   int freq[128] = {0};
//   for (int i = 0; i < s.length(); i++) {
//     if (s[i] == ' ')
//       continue;
//     freq[tolower(s[i])]++;
//   }
//   int found_middle_element = 0;
//   for (int i = 0; i < 128; i++) {
//     // all the elements freq should be even except for "atmost" one element
//     if (freq[i] % 2 != 0) {
//       // there can only be one middle element when the string length without
//       space is odd found_middle_element++;
//     }
//   }
//   if (found_middle_element > 1)
//     return false;
//   else
//     return true;
// }
//  ﭱ   
//  ﭱ   
/* method 2 using a bit vector
to reduce space complexity to O(1)
*/
bool isPowerOfTwo(int z) {
  // RIGHT: power of two and one less than power of two gives all bits zero when
  // done bitwise ANDed WRONG: power of two and one less than power of two gives
  // all bits one when done bitwise ORed 110 OR 101 = 111 neither six nor five
  // is a power of two also if z == 0 then return false (0 AND -1 =
  // 11111111...0)
  return (!(z & (z - 1)) && (z > 0));
}
bool palindromePerm(string s) {
  // assume A-Za-z only
  int checker = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != ' ') {
      // becuase we need to check only the palindrome, we can use tolower()
      checker ^= 1 << (tolower(s[i]) - 'a'); // XOR
    }
  }
  if (checker == 0)
    return true;
  else if (isPowerOfTwo(checker))
    return true;
  else
    return false;
}
int main(int argc, char const *argv[]) {
  string s = "Taco cat";
  cout << (palindromePerm(s) ? "true" : "false") << '\n';
  return 0;
}
