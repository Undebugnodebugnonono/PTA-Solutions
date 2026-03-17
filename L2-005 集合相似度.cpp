//vctor+set 集合相似度
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353; 
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
int gcd(const int a,const int b){return b ? gcd(b,a%b) : a;}
int lcm(const int a,const int b){return a / gcd(a, b) * b;}
int qw(int a,int k){int res = 1;while(k){if(k&1) res *= a;a*=a;k>>=1;}return res;}

void solve(){
    int n;cin>>n;
    vector<set<int>> a(n+1);
    for(int i=1;i<=n;i++){
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int x;cin>>x;
            a[i].insert(x);
        }
    }
    int k;cin>>k;
    while(k--){
        int x,y;
        cin>>x>>y;
        int cnt=0;
        for(auto t:a[x])
            if(a[y].count(t)) cnt++;
        double ans = (double)cnt/(a[x].size()+a[y].size()-cnt);
        ans*=100;
        cout<<fixed<<setprecision(2)<<ans<<"%"<<'\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //int T;cin >> T;while (T--) 
    solve();
}