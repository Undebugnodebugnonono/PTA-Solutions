#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353; 
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
int gcd(const int a,const int b){return b ? gcd(b,a%b) : a;}
int lcm(const int a,const int b){return a / gcd(a, b) * b;}
int qw(int a,int k){int res = 1;while(k){if(k&1) res *= a;a*=a;k>>=1;}return res;}
const int N = 1e5+7;
const int M = 1e4+7;

struct Node{
    int key;
    int ne;
}idx[N];

void solve(){
    int st,n;
    cin>>st>>n;
    for(int i = 0;i < n;i ++){
        int t;
        cin>>t>>idx[t].key>>idx[t].ne;
    }
    vector<int> a;//存正确序列的idx
    int cur=st;
    while(cur!=-1){//化简while+for
        a.push_back(cur);
        cur=idx[cur].ne;
    }
    bool vis[M];
    for(int i = 0;i<M;i ++) vis[i]=0;
    vector<int> ans,anss;
    for(auto x:a){
        int t = abs(idx[x].key);
        if(!vis[t]){
            vis[t]=1;
            ans.push_back(x);
        }else anss.push_back(x);
    }
    for(int i = 0;i<ans.size();i++){
        cout << setfill('0') << setw(5) << ans[i] << ' ' << idx[ans[i]].key << ' ' ;
        if(i!=ans.size()-1){
            cout << setfill('0') << setw(5) << ans[i+1] << '\n';
        }else cout << -1 << '\n';
    }
    for(int i = 0;i<anss.size();i++){
        cout << setfill('0') << setw(5) << anss[i] << ' ' << idx[anss[i]].key << ' ' ;
        if(i!=anss.size()-1){
            cout << setfill('0') << setw(5) << anss[i+1] << '\n';
        }else cout << -1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //int T;cin >> T;while (T--) 
    solve();
}
/*
直接寻址法+struct+set
 s存访问过的绝对值，一边!s.count就存ans中另一边存anss中(已经出现过的)
 最后遍历ans anss输出即可
 或者bool代替set
*/