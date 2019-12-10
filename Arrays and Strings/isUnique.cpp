#include <algorithm> //for sorting in method 5
#include <iostream>
#include <string>
#define MAX_SIZE 128
using namespace std;
int main() {
  /*
  method 1 (using additional data structure) counting frequency of occurence
  */
  // string s1;
  // cin>>s1;
  // int freq[MAX_SIZE] = {0};

  // for(int i=0; i<s1.length(); i++)
  // {
  //     freq[int(s1[i])]++;
  // }
  //  for(int i=0; i<MAX_SIZE; i++)
  // {
  //     if(freq[i]>1){
  //         cout<<s1<<" is Not Unique\n";
  //         return -1;
  //     }

  // }
  // cout<<s1<<" is Unique\n";
  // return 0;
  //#############################################//
  //#############################################//
  /*
  method 2
  improved version of method 1
  assuming ascii characters and 128 characters as per ascii
  */
  //   string s1;
  //   cin >> s1;
  //   if (s1.length() > 128) // you cannot have all unique with more than 128 characters from
  //            // ascii set which only has 128 unique chars
  //   {
  //     cout << "Not Unique\n";
  //     return -1;
  //   }
  //   bool visited[128] = {false};
  //   for (int i = 0; i < s1.length(); i++) {
  //     if (!visited[s1[i]]) {
  //       visited[s1[i]] = true;
  //     } else {
  //       cout << "Not Unique\n";
  //       return -1;
  //     }
  //   }
  //   cout << "Unique\n";
  //   return 0;
  //#############################################//
  //#############################################//
  /*
  Method 3 using bitSet (bit vector/ bit array)
  not using frequency count array
  assuming that the string contains only a-z (lowercase) because we have checker
  as an int which is 32 bits only (4bytes) so 26 alphabets can be accomodated
  otherwise we will have to use long
  */
  string s1;
  cin >> s1;
  int checker = 0;
  for (int i = 0; i < s1.length(); i++) {
    int value = s1[i] - 'a'; // relative value, a is 0
    cout<<checker<<'\n';
    if ((checker & (1 << value)) != 0) {
      cout << "not Unique\n";
      return -1;
    } else {
      checker |= (1 << value); // this is same as "checker = checker | (1<<value);"
    }
  }
  cout << "Unique\n";
  return 0;

  //#############################################//
  //#############################################//
  /*
method 4
  comparing each char to every other rest char so that we use no additional data
structure O(n square) time
*/
  // string s1;
  // cin>>s1;
  // for (int i =0;i<s1.length();i++){
  //     for(int j=i+1;j<s1.length();j++){
  //         if(s1[i]==s1[j]){
  //             cout<<"Not Unique\n";
  //             return -1;
  //         }
  //     }
  // }
  // cout<<"Unique\n";
  // return 0;
  //#############################################//
  //#############################################//
  /*
method 5
  improvement over method 4 to take O(nlogn) time and no additional data
structure sorting the string and then comparing the adjacent chars
*/
  // string s1;
  // cin>>s1;
  // sort(s1.begin(),s1.end());
  // cout<<s1<<"\n";
  // for (int i=1; i<s1.length();i++){
  //     if(s1[i]==s1[i-1]){
  //         cout<<"Not Unique\n";
  //         return -1;
  //     }
  // }
  // cout<<"Unique\n";
  // return 0;
}