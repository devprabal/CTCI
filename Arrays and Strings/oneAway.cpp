#include <iostream>
// #define absolute(x)                                                            \
//   ((x) < 0) ? -(x) : x // the paranthesis for negation of x is very necessary, see
//                      // how it would be expanded otherwise
int absolute(int x) {
  if (x < 0)
    return -x;
  else
    return x;
}
using namespace std;

bool oneAway(string a, string b) {
  if (a.length() == b.length()) {
    int found = 0;
    for (int i = 0; i < a.length(); i++) {
      if (a[i] != b[i])
        found++;
    }
    if (found == 1)
      return true;
    else
      return false;
  } else if (absolute(a.length() - b.length()) == 1) {
    int found = 0;
    string min_str = b;
    string max_str = a;
    if ((a.length() - b.length()) == -1) {
      min_str = a;
      max_str = b;
    }
    for (int i = 0, j = 0; i < min(a.length(), b.length()); i++, j++) {
      if (min_str[i] != max_str[j]) {
        found++;
        i--;
      }
    }
    if (found == 1 || found == 0) // found==0 makes sure that the case "pale"
                                  // and "pales" is also correct
      // the "pale" string will finish before it encounter a char which is not
      // same in the other string.
      return true;
    else
      return false;
  } else
    return false;
}
int main(int argc, char const *argv[]) {
  cout << (oneAway(argv[1], argv[2]) ? "true\n" : "false\n");
  // cout << (oneAway("pale", "pales") ? "true\n" : "false\n");
  return 0;
}
