
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool isVowel(char ch){
    ch=tolower(ch);
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}
void removeconso(string &str){
    int j=0;
    for(int i=0;i<str.length();i++){
        if(isVowel(str[i])){
            str[j]=str[i];
            j++;
        }
    }
    str.resize(j);
}

int main(){
    string str;
    cout<<"enter string: " ;
    getline(cin,str);
    removeconso(str);
    cout<<str;
}