#include<bits/stdc++.h>
using namespace std;
using ll = long long;;
int main(){
    int q; cin >> q;
    while(q--){
        int a1,a2,a3,a4,a5,a6,a7; cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7;
        vector<int> v={a1,a2,a3,a4,a5,a6,a7};
        int ma=*max_element(v.begin(),v.end());
        int neg=(-a1-a2-a3-a4-a5-a6-a7);
        int ans=neg+ma+ma;
        cout << ans << endl;
    }
    return 0;
}