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

#define int long long

signed main(){
	IO;
	int n,m;
	cin>>n>>m;
	vector<vvi> e(n);
	vi ee(4);
	FOR(i,0,m){
		cin>>ee[0]>>ee[1]>>ee[2]>>ee[3];
		e[ee[0]].pb(ee);
		e[ee[1]].pb(ee);
	}

	set<vi> s;
	vi vst(n,0);
	vvi ans(n,vi(2,1e16));
	s.insert(vi({0,0,0}));//mx,toll,idx
	vst[0] = 1;
	ans[0][0] = 0;
	ans[0][1] = 0;

	while(s.size()){
		vi v = *(s.begin());
		vst[v[2]] = 1;
		s.erase(v);

		for(auto u:e[v[2]])FOR(i,0,2)
			if(!vst[u[i]]){
				vi tmp(3,0);
				tmp[0] = max(u[2],v[0]);
				tmp[2] = u[i];
				if(u[2] <= v[0])
					tmp[1] += v[1];
				if(u[2] >= v[0])
					tmp[1] += u[3];

				if(u[2] < ans[u[i]][0]){
					s.erase(vi{ans[u[i]][0],ans[u[i]][1],u[i]});
					s.insert(tmp);
					ans[u[i]][0] = tmp[0];
					ans[u[i]][1] = tmp[1];
				}
				if(u[2] == ans[u[i]][0] && tmp[1] < ans[u[i]][1]){
					s.erase(vi{ans[u[i]][0],ans[u[i]][1],u[i]});
					s.insert(tmp);
					ans[u[i]][1] = tmp[1];
				}
			}
	}
	int a = 0;
	FOR(i,0,n)
		a += ans[i][1];
	cout<<a;
	return 0;
}
