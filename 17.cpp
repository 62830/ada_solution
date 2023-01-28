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

#define print(arg...) 0
signed main(){
	IO;
	int n,m,r,ans = 0;
	
	cin>>n>>m>>r;
	vvi lst(m+1,vi(m+1,0)),nxt(m+1,vi(m+1,0)),lst_i(m+1,vi(m+1,0)),lst_j(m+1,vi(m+1,0));

	
	FOR(k,1,n+1){
		lst[0][0] = 1;
		print(lst);
		FOR(i,0,m+1){
			FOR(j,0,m+1){
				if(i==0)lst_i[i][j] = lst[i][j];
				else{
					lst_i[i][j] = lst[i][j] + lst_i[i-1][j];
					lst_i[i][j] = lst_i[i][j] >= r? lst_i[i][j]-r : lst_i[i][j];
				}
			}
		}
		print(lst_i);

		FOR(i,0,m+1){
			FOR(j,0,m+1){
				if(j==0)lst_j[i][j] = lst[i][j];
				else{
					lst_j[i][j] = lst[i][j] + lst_j[i][j-1];
					lst_j[i][j] = lst_j[i][j] >= r? lst_j[i][j] - r: lst_j[i][j];
				}
			}
		}
		print(lst_j);

		FOR(i,1,m+1){
			FOR(j,0,i+1){
				//put 1
				nxt[i][j] = 0;
				nxt[i][j] = lst_i[i][j];
				if(j>0){
					nxt[i][j] -= lst_i[j-1][j];
					nxt[i][j] = nxt[i][j] < 0 ? nxt[i][j] + r: nxt[i][j];
				}
				/*
				FOR(l,j,i+1){
					nxt[i][j] += lst[l][j];
					nxt[i][j] = nxt[i][j] >= r? nxt[i][j]-r:nxt[i][j];
				}*/
				// put -1
				nxt[i][j] += lst_j[i][j-1];
				nxt[i][j] = nxt[i][j] >= r? nxt[i][j]-r:nxt[i][j];
				/*
				FOR(l,1,j+1){
					nxt[i][j] += lst[i][j-l];
					nxt[i][j] = nxt[i][j] > r? nxt[i][j]-r:nxt[i][j];
				}*/
			}
		}
		swap(nxt,lst);
	}
	print(lst);
	FOR(i,0,m+1){
		FOR(j,0,m+1){
			ans += lst[i][j];
			ans = ans >= r? ans-r:ans;
		}
	}
	cout<<ans<<endl;
	return 0;
	
}
