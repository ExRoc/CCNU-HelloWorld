#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    int a,b,j,i=0;
    cin>>a>>b;
    unsigned* partner=new unsigned[a];
    unsigned* cake = new unsigned[b];
    for (i = 0; i < a; i++) {
        cin >> partner[i];
    }
    for (i = 0; i < b; i++) {
        cin >> cake[i];
    }
    sort(partner,partner+a);
    sort(cake, cake+b);

    int count = 0;
    for ( i = 0, j = 0; i < a && j < b; i++, j++) {
        while (j < b && partner[i] > cake[j]) {
            j++;
        }
        if (j < b) {
            count++;
        }
    }
    cout<<count;

}
