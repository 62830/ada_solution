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
inline int c2i(char c){
	if(c <= '9')return c - '0';
	if(c <= 'Z')return c - 'A' + 10;
	return c - 'a' + 36;
}

vi lazy(2e6+10,0);

void modify(int l,int r,int cl,int cr,int idx){
	if(cl==l && cr==r){
		++lazy[idx];
		return;
	}
	lazy[2*idx+1] += lazy[idx];
	lazy[2*idx+2] += lazy[idx];
	lazy[idx] = 0;
	
	int cm = (cl+cr)/2;
	if(r<=cm)
		modify(l,r,cl,cm,2*idx+1);
	else if(l>=cm)
		modify(l,r,cm,cr,2*idx+2);
	else{
		modify(l,cm,cl,cm,2*idx+1);
		modify(cm,r,cm,cr,2*idx+2);
	}
}

int query(int q,int cl,int cr,int idx){
	if(cl+1==cr){
		return lazy[idx];
	}
	lazy[2*idx+1] += lazy[idx];
	lazy[2*idx+2] += lazy[idx];
	lazy[idx] = 0;
	int cm = (cl+cr)/2;
	if(q<cm){
		return query(q,cl,cm,2*idx+1);
	}
	else{
		return query(q,cm,cr,2*idx+2);
	}
}

signed main(){
	IO;
	string s;
	int k;
	cin>>s;
	cin>>k;
	int n = s.size(),idx,ofst;
	vector<deque<int>> vq(62);
	vi ans;
	FOR(i,0,n)
		vq[c2i(s[i])].pb(i);
	
	FOR(i,0,n){
		FOR(j,0,62){
			if(!vq[j].size())continue;
			idx = vq[j].front();
			if(idx-i<=k)
				ofst = query(idx,0,n,0);
			else 
				continue;
			if(idx + ofst - i <= k){
				vq[j].pop_front();
				ans.pb(idx);
				k -= idx + ofst - i;
				modify(0,idx,0,n,0);
				break;
			}
		}
	}
	FOR(i,0,n)
		cout<<s[ans[i]];
	cout<<endl;
	return 0;
}
