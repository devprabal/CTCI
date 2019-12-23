#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    //assuming string has only a-zA-Z
    string s = "aaaaabbcc";
    int freq[128]={0};
    for (int i =0; i<s.length();i++){
        freq[(int)s[i]]++;
    }
    string compressed_str = "";
    for (int i =0; i<s.length();i++){
        if(s[i+1]!=s[i]){
        compressed_str+=s[i];
        compressed_str+=to_string(freq[s[i]]);
        }
    }
    if(compressed_str.length()>= s.length())
        cout<<s<<'\n';
    else
        cout<<compressed_str<<'\n';
    return 0;
}
