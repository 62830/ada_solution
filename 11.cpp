#include<bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define IFOR(i,a,b) for(int i=a-1;i>=b;--i)
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define F first
#define S second
#define pb push_back

template<typename T>
void print_arr(T arr){
	for(auto &i:arr)cout<<i<<' ';
	cout<<endl;
}

const int N=500003,MX=100003;
int tl[MX],tr[MX],arr[N],sl[N/2],sr[N/2],slp=0,srp=0;
ll ans=0;


void f(int l,int r){
	if(l+1>=r)return;
	if(l+2==r){
		ans += abs(arr[l]-arr[r-1])==min(arr[l],arr[r-1]);
		return;
	}
	int m=(l+r)/2,a,b;
	int pl=m,pr=m+1,mn=arr[m];
	++tr[arr[m]];
	sr[srp] = arr[m];
	++srp;
	while(pl!=l || pr != r){
		a = pl==l?INT_MIN:arr[pl-1];
		b = pr==r?INT_MIN:arr[pr];
		if(a>=b){
			--pl;
			++tl[arr[pl]];
			sl[slp] = arr[pl];
			++slp;
			mn = min(mn,arr[pl]);
			if(arr[pl]-mn>0)ans += tr[arr[pl]-mn];
			if(arr[pl]+mn<MX)ans += tr[arr[pl]+mn];
		}
		else{
			++pr;
			++tr[arr[pr-1]];
			sr[srp] = arr[pr-1];
			++srp;
			mn = min(mn,arr[pr-1]);
			if(arr[pr-1]-mn>0)ans += tl[arr[pr-1]-mn];
			if(arr[pr-1]+mn<MX) ans += tl[arr[pr-1]+mn];
		}
	}

	FOR(i,0,slp)tl[sl[i]]=0;
	FOR(i,0,srp)tr[sr[i]]=0;
	slp=srp=0;
	f(l,m);
	f(m,r);
	return;
}
	
int main(){
	IO;
	int n;
	cin>>n;
	FOR(i,0,n)cin>>arr[i];
	f(0,n);
	cout<<ans;
}
