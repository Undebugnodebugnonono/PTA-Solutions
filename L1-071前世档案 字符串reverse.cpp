#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353; 
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
int gcd(const int a,const int b){return b ? gcd(b,a%b) : a;}
int lcm(const int a,const int b){return a / gcd(a, b) * b;}
int qw(int a,int k){int res = 1;while(k){if(k&1) res *= a;a*=a;k>>=1;}return res;}

int cal(string s){
    int res = 0;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='y') res+=(1<<i);
    }
    return res;
}

void solve(){
    int n,m;
    cin>>n>>m;
    while(m--){
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        int ans = (1<<n)-cal(s);
        cout<<ans<<'\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //int T;cin >> T;while (T--) 
    solve();
}