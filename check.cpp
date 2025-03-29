#include<bits/stdc++.h>
using namespace std;
int func(int n){
    if(n == 2){
        return 3;
    }
    return n*n*n - n*n -func(n-1);
}
int main(){
    cout<<func(25);
    return 0;
}

