#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(const int a,const int b){return b ? gcd(b,a%b) : a;}
int lcm(const int a,const int b){return a / gcd(a, b) * b;}
int qw(int a,int k){int res = 1;while(k){if(k&1) res *= a;a*=a;k>>=1;}return res;}
queue<char> q[103];
stack<char> st;

void solve(){
    int n,m,smx;
    cin>>n>>m>>smx;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++) q[i].push(s[j]);
    }
    int op;
    vector<char> ans;
    while(cin>>op){//未知输入个数的时候
        if(!st.empty()&&op==0){
            int t=st.top();
            st.pop();
            ans.push_back(t);
        }else if(st.empty()&&op==0){
            
        }else if(op!=0&&q[op].empty()){
            
        }else{
            if(st.size()==smx){
                int xt=st.top();
                st.pop();
                ans.push_back(xt);    
            }
            int tt=q[op].front();
                q[op].pop();
                st.push(tt);
        }
    }
    for(auto x:ans) cout<<x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //int T;cin >> T;while (T--) 
    solve();
}