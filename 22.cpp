#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define IFOR(i,a,b) for(int i=a-1;i>=b;--i)
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define F first
#define S second
#define pb emplace_back 
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define BE(a) a.begin(),a.end()
#define DIM(S) template<typename T> struct Dim<S<T>>{ enum {val = 1 + Dim<T>::val}; };
#define UGLIFY(U,B,S,E) template<typename ...T> ostream& operator<<(ostream&O,U<T...> a){ O<<B; int c=0; for(auto i:a)O<<(c++?S:"")<<i; return O<<E; } template<typename ...T> void _print(const char *s,U<T...> a,bool nxt_line = false,int idt = 0,int dim = Dim<U<T...>>::val,typename enable_if< (Dim<U<T...>>::val>1) >::type* = 0){ bool b = strlen(s); if(b) cerr<<s<<" =\n";if(nxt_line) cerr<<"\n"; cerr<<B; int c=0; string sep = S; for(int i=0;i<dim-1;++i)sep += "\n"; for(int i=0;i<idt+1;++i)sep += " "; for(auto i:a){ cerr<<(c++?sep:""); _print("",i,0,idt+1,dim-1); } cerr<<E; cerr<<(b?"\n":""); return; }
#ifdef ONLINE_JUDGE
#define print(arg...) 0
#else
#define print(arg...) _print_all(#arg,arg);
#endif
#define endl '\n'

template<typename T> struct Dim{ enum {val = 0}; }; DIM(vector); DIM(deque); DIM(set); DIM(multiset); DIM(unordered_set); template<typename S,typename T> struct Dim<map<S,T>>{ enum {val = 1 + Dim<T>::val}; }; template<typename S,typename T> struct Dim<unordered_map<S,T>>{ enum {val = 1 + Dim<T>::val}; }; template<typename S,typename T> ostream& operator<<(ostream&O,pair<S,T> a){ return O<<"("<<a.first<<", "<<a.second<<")"; } template<typename T> void _print(const char *s,T a,bool nxt_line = false,int idt = 0,int dim = Dim<T>::val,typename enable_if< (Dim<T>::val<=1) >::type* = 0){ bool b = strlen(s); if(b) cerr<<s<<" = "; cerr<<a<<(b?"\n":""); return; }
UGLIFY(vector,"[",", ","]"); UGLIFY(deque,"[",", ","]"); UGLIFY(set,"{",", ","}"); UGLIFY(multiset,"{",", ","}"); UGLIFY(unordered_set,"{",", ","}"); UGLIFY(map,"{",", ","}"); UGLIFY(unordered_map,"{",", ","}"); 
template<typename ...T> void _print_all(const char*s,T... a){ cerr<<s<<" = "; int c=0; ((cerr<<(c++?", ":""),_print("",a,true)),...); cerr<<"\n"; }

vi par,c,d,cs;
vvi e,dp;
int dpi=0;
int n,m;

void node_sum(int idx){
	cs[idx] += c[idx];
	for(auto u:e[idx]){
		node_sum(u);
		cs[idx] += cs[u];
	}
}

void dfs(int idx){
	int tmp = dpi;
	print(idx,tmp);
	for(auto u:e[idx]){
		dfs(u);
	}
	++dpi;
	FOR(i,0,m+1){
		dp[dpi][i] = dp[dpi-1][i];
		if(i-c[idx]>=0)
			dp[dpi][i] = max(dp[dpi-1][i-c[idx]] + c[idx],dp[dpi][i]);
	}
	++dpi;
	FOR(i,0,m+1){
		dp[dpi][i] = dp[dpi-1][i];
		if(i-d[idx]>=0)
			dp[dpi][i] = max(dp[tmp][i-d[idx]] + cs[idx],dp[dpi][i]);
	}
	print(dp);
}

signed main(){
	IO;
	cin>>n>>m;
	par.resize(n);
	c.resize(n);
	cs = vi(n,0);
	d.resize(n);
	e.resize(n);
	dp = vvi(2*n+1,vi(m+1,0));

	FOR(i,0,n)
		cin>>par[i];
	FOR(i,0,n)
		if(par[i]!=-1)
			e[par[i]].pb(i);
	FOR(i,0,n)
		cin>>c[i]>>d[i];
	
	FOR(i,0,n)
		if(par[i]==-1){
			node_sum(i);
			dfs(i);
		}
	
	print(dp);
	print(dp.back().back());
	print(cs);
	cout<<dp.back().back();
	return 0;
}
