#include<iostream>
using namespace std;
#include<string.h>
string r1;
string xorop(char a[], char b[]){
    int i;
    for(i=0;i<strlen(b);i++){
        if(a[i]==b[i]){
            char r = '0';
            strcat(r1,r);
        }
        else{
            strcat(r1,'1');
        }
    }
    return r1;
}

void main(){

}
