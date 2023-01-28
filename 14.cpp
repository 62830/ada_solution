#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define IFOR(i,a,b) for(int i=a-1;i>=b;--i)
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define BE(a) a.begin(),a.end()
#define DIM(S) template<typename T> struct Dim<S<T>>{ enum {val = 1 + Dim<T>::val}; };
#define UGLIFY(U,B,S,E) template<typename ...T> ostream& operator<<(ostream&O,U<T...> a){ O<<B; int c=0; for(auto i:a)O<<(c++?S:"")<<i; return O<<E; } template<typename ...T> void _print(const char *s,U<T...> a,bool nxt_line = false,int idt = 0,int dim = Dim<U<T...>>::val,typename enable_if< (Dim<U<T...>>::val>1) >::type* = 0){ bool b = strlen(s); if(b) cerr<<s<<" =\n";if(nxt_line) cerr<<"\n"; cerr<<B; int c=0; string sep = S; for(int i=0;i<dim-1;++i)sep += "\n"; for(int i=0;i<idt+1;++i)sep += " "; for(auto i:a){ cerr<<(c++?sep:""); _print("",i,0,idt+1,dim-1); } cerr<<E; cerr<<(b?"\n":""); return; }
#define print(arg...) _print_all(#arg,arg);
template<typename T> struct Dim{ enum {val = 0}; }; DIM(vector); DIM(deque); DIM(set); DIM(multiset); DIM(unordered_set); template<typename S,typename T> struct Dim<map<S,T>>{ enum {val = 1 + Dim<T>::val}; }; template<typename S,typename T> struct Dim<unordered_map<S,T>>{ enum {val = 1 + Dim<T>::val}; }; template<typename S,typename T> ostream& operator<<(ostream&O,pair<S,T> a){ return O<<"("<<a.first<<", "<<a.second<<")"; } template<typename T> void _print(const char *s,T a,bool nxt_line = false,int idt = 0,int dim = Dim<T>::val,typename enable_if< (Dim<T>::val<=1) >::type* = 0){ bool b = strlen(s); if(b) cerr<<s<<" = "; cerr<<a<<(b?"\n":""); return; }
UGLIFY(vector,"[",", ","]"); UGLIFY(deque,"[",", ","]"); UGLIFY(set,"{",", ","}"); UGLIFY(multiset,"{",", ","}"); UGLIFY(unordered_set,"{",", ","}"); UGLIFY(map,"{",", ","}"); UGLIFY(unordered_map,"{",", ","}"); 
template<typename ...T> void _print_all(const char*s,T... a){ cerr<<s<<" = "; int c=0; ((cerr<<(c++?", ":""),_print("",a,true)),...); cerr<<"\n"; }

signed main(){
	IO;
	int n,m;
	cin>>n>>m;
	vi arr(n),add(n);
	vvi q(n,vi(n,0));
	FOR(i,0,n)
		cin>>arr[i];
	add[0] = arr[0];
	FOR(i,1,n)
		add[i] = add[i-1] + arr[i];

	vvi dp(m,vi(n,LLONG_MAX));
	FOR(i,0,n){
		FOR(j,i,n){
			int l=i,r=i,cur_sum=arr[l],mx_sum=arr[l];
			while(r<j){
				++r;
				if(cur_sum<0){
					l=r;
					cur_sum = arr[l];
					mx_sum = max(cur_sum,mx_sum);
					continue;
				}
				cur_sum += arr[r];
				mx_sum = max(cur_sum,mx_sum);
			}
			q[i][j] = mx_sum;
		}
	}
	FOR(i,0,m){
		FOR(j,i,n){
			if(i==0){
				dp[i][j] = q[i][j] * (j-i+1);
			}
			else{
				FOR(k,i,j+1){
					dp[i][j] = min(dp[i-1][k-1] + q[k][j]*(j-k+1),dp[i][j]);
				}
			}
		}
	}
	cout<<dp.back().back();
	return 0;
}
