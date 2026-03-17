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
    int n;
    cin>>n;
    set<string> s;
    for(int i=0;i<n;i++){
        string t;cin>>t;
        s.insert(t);
    }
    int m;cin>>m;
    vector<pair<string,int>> ans;
    double sum=0;
    vector<string> ss(m);
    vector<double> a(m);
    for(int i=0;i<m;i++){
        cin>>ss[i]>>a[i];
        sum+=a[i];
    }
    double avg=(double)sum/m;
    for(int i=0;i<m;i++){
        if(!s.count(ss[i])&&a[i]>avg) ans.push_back({ss[i],a[i]});
    }
    sort(ans.begin(),ans.end());
    if(ans.size()==0){
        cout<<"Bing Mei You\n";
        return;
    }
    for(auto x:ans){
        cout<<x.first<<'\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //int T;cin >> T;while (T--) 
    solve();
}