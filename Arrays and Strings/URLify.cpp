#include <iostream>

using namespace std;
int main() {
  // TODO: (to make it user friendly) how to avoid space as next input? How to
  // take space as an input in the string?
  //   string h;
  //   cout << "Enter the string: ";
  //   cin >> h;
  //   cout << "\nEnter the actual length: ";
  //   int normal_length;
  //   cin >> normal_length;
  //   cout << "\nEnter string to replace space: " << h << '\n';
  //   string replace_chars;
  //   cin >> replace_chars;
  //#############################################//
  //#############################################//
  /* method 1 - shifting the chars on each encounter of space
   */
  //   string h = "The Mr Smith Shop      ";
  //   string replace_chars = "%20";
  //   int normal_length = 17;
  //   cout << "\nThe Original string is: " << h << '\n';
  //   // each space adds replace_chars -1 more spaces for additional characters
  //   to
  //   // be inserted
  //   const int make_space = replace_chars.length() - 1;
  //   int count_space = 0;
  //   for (int i = 0; i < h.length(); i++) {
  //     if (h[i] == ' ') {
  //       count_space++;
  //       int j;
  //       for (j = normal_length + make_space * count_space; j > i +
  //       make_space;
  //            j--) {
  //         h[j] = h[j - make_space];
  //       }
  //       for (int k = j - make_space, p = 0; k <= j; k++, p++) {
  //         h[k] = replace_chars[p];
  //       }
  //     }
  //   }
  //   cout << "The Urlified string is: " << h << '\n';
  //#############################################//
  //#############################################//
  /* method 2 - shifting the chars all at once after counting all the spaces
   */
  string h = "The Mr Smith Shop      ";
  string replace_chars = "%20";
  int normal_length = 17;
  cout << "\nThe Original string is: " << h << '\n';
  // each space adds replace_chars -1 more spaces for additional characters to
  // be inserted
  const int make_space = replace_chars.length() - 1;
  int count_space = 0;
  for (int i = 0; i < normal_length; i++) {
    if (h[i] == ' ')
      count_space++;
  }
  int j;
  int extended_length =
      normal_length + make_space * count_space; // this is same as h.length()
  int i = normal_length - 1;
  for (j = extended_length - 1; j >= 0; j--, i--) {
    if (h[i] != ' ') {
      h[j] = h[i];
    } else {
      h[j] = '0';
      h[--j] = '2';
      h[--j] = '%';
    }
  }

  cout << "The Urlified string is: " << h << '\n';

  return 0;
}