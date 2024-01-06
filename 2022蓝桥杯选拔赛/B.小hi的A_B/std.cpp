#include <bits/stdc++.h>
using namespace std;
int c[5000000]= {0};
int x=0;

int main() {
    string s1,s2;
    cin>>s1>>s2;
    vector<int>a;
    vector<int>b;
    int flag1 = 1;
    int flag2 = 1;
    if(s1[0]=='-') {
        flag1 = -1;
    }
    if(s2[0]=='-') {
        flag2 = -1;
    }
    for(int i=0; i<((int)s1.length()-(flag1 > 0 ? 0:1)); i++) {
        a.push_back(s1[(int)s1.length()-i-1]-'0');
    }
    for(int j=0; j<((int)s2.length()-(flag2 > 0 ? 0:1)); j++) {
        b.push_back(s2[(int)s2.length()-j-1]-'0');
    }
    if(s1[0]=='0'||s2[0]=='0')
        cout<<0;
    else {
        for(int k=0; k<(int)a.size(); k++) {
            x=0;
            for(int m=0; m<(int)b.size(); m++) {
                c[m+k]=c[m+k]+a[k]*b[m]+x;
                x=c[m+k]/10;
                c[m+k]%=10;
            }
            c[k+(int)b.size()]=x;
        }
        if(flag1*flag2<0)printf("-");
        for(int i=0; i<(int)(a.size()+b.size()); i++) {
            if(c[a.size()+b.size()-1-i]==0&&i==0) continue;
            else cout<<c[(int)(a.size()+b.size())-i-1];
        }
    }
    return 0;
}
