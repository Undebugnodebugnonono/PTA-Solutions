#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353; 
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
int gcd(const int a,const int b){return b ? gcd(b,a%b) : a;}
int lcm(const int a,const int b){return a / gcd(a, b) * b;}
int qw(int a,int k){int res = 1;while(k){if(k&1) res *= a;a*=a;k>>=1;}return res;}
bool ok[1010],okok[1010];//bool 行列是最佳方式

void solve(){
    int n,m,k;
    if(!(cin>>n>>m>>k)) return;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];

    while(k--){
        int mx = -2e18, t1 = -1, t2 = -1;//会有负数，也不能用0来标记轰炸。。。
        for(int i=0;i<n;i++){
            if(ok[i]) continue;//炸过的跳过不然只会炸一次
            for(int j=0;j<m;j++){
                if(okok[j]) continue;//同上
                if(a[i][j] > mx){
                    mx = a[i][j];
                    t1 = i;
                    t2 = j;
                }
            } 
        }
        ok[t1]=1;
        okok[t2]=1;
    }
    for(int i=0;i<n;i++){
        bool okk=1;
        for(int j=0;j<m;j++){
            if(!ok[i]&&!okok[j]){
                if(!okk) cout << ' ';
                cout << a[i][j];
                okk = 0;
            }
        }
        if(!okk) cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //int T;cin >> T;while (T--) 
    solve();
}