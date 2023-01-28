#include<bits/stdc++.h>
using namespace std;
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

#define int long long
#define print(...) 0
static bool cmp0(vi &a,vi&b){
	return a[0]<b[0] || (a[0]==b[0]&&a[1]<b[1]);
}
static bool cmp1(vi &a,vi&b){
	return a[1]<b[1] || (a[1]==b[1]&&a[0]<b[0]);
}
static bool weight_cmp(vi&a,vi&b){
	return a[1]*b[0]<=a[0]*b[1];
}

signed main(){
	IO;
	int N,n;
	cin>>N;
	vvi arr(N,vi(3));
	FOR(i,0,N){
		cin>>n;
		vvi tmp(n,vi(2));
		FOR(j,0,n)
			cin>>tmp[j][0]>>tmp[j][1];
		sort(BE(tmp),cmp1);
		int p=0,q=0;
		IFOR(i,n,0){
			p += tmp[i][0];
			q = max(p+tmp[i][1],q);
		}
		arr[i][0] = n;
		arr[i][1] = p;
		arr[i][2] = q;
		print(tmp);
	}
	sort(BE(arr),weight_cmp);
	print(arr);
	
	int ans=0, wait=0;
	FOR(i,0,N){
		ans += arr[i][0]*(wait + arr[i][2]);
		wait += arr[i][1];
		print(ans);
	}
	cout<<ans;
}
