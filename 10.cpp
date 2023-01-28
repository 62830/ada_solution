#include<bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define IFOR(i,a,b) for(int i=a-1;i>=b;--i)
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>
void print_arr(T arr){
	for(auto &i:arr)cout<<i<<' ';
	cout<<endl;
}

vector<pll>arr,tmp,arr2;

ll nish(int l,int r){
	if(l>=r-1)return 0;
	if(l==r-2){
		if(arr[l].S>=arr[r-1].S){
			swap(arr[l],arr[r-1]);
			return 1;
		}
		return 0;
	}

	int m = (l+r)/2;
	ll ans = nish(l,m)+nish(m,r);

	int lp=l,rp=m,tmpp=0;
	while(lp!=m && rp!=r){
		if(arr[lp].S>=arr[rp].S){
			ans += m-lp;
			tmp[tmpp] = arr[rp];
			++tmpp;
			++rp;
		}
		else{
			tmp[tmpp] = arr[lp];
			++tmpp;
			++lp;
		}
	}
	while(lp!=m){
		tmp[tmpp] = arr[lp];
		++tmpp;
		++lp;
	}
	while(rp!=r){
		tmp[tmpp] = arr[rp];
		++tmpp;
		++rp;
	}
	FOR(i,l,r)
		arr[i] = tmp[i-l];
	

#ifdef DEBUG
	cout<<l<<' '<<r<<endl;
#endif

	return ans;
}

ll nish_2(int l,int r){
	if(l>=r-1)return 0;
	if(l==r-2){
		if(arr2[l].S>arr2[r-1].S){
			swap(arr2[l],arr2[r-1]);
			return 1;
		}
		return 0;
	}

	int m = (l+r)/2;
	ll ans = nish_2(l,m)+nish_2(m,r);

	int lp=l,rp=m,tmpp=0;
	while(lp!=m && rp!=r){
		if(arr2[lp].S>arr2[rp].S){
			ans += m-lp;
			tmp[tmpp] = arr2[rp];
			++tmpp;
			++rp;
		}
		else{
			tmp[tmpp] = arr2[lp];
			++tmpp;
			++lp;
		}
	}
	while(lp!=m){
		tmp[tmpp] = arr2[lp];
		++tmpp;
		++lp;
	}
	while(rp!=r){
		tmp[tmpp] = arr2[rp];
		++tmpp;
		++rp;
	}
	FOR(i,l,r)
		arr2[i] = tmp[i-l];
	

#ifdef DEBUG
	cout<<l<<' '<<r<<endl;
#endif

	return ans;
}


int main(){
	IO;
	
	ll n,l1,l2,r1,r2,ans=0;
	cin>>n>>l1>>l2>>r1>>r2;
	arr = vector<pll>(n);
	tmp = vector<pll>(n);
	arr2 = vector<pll>(n);
	FOR(i,0,n)
		cin>>arr[i].F>>arr[i].S;
	sort(arr.begin(),arr.end());
	
	FOR(i,0,n){
		arr2[i].F = arr[i].F;
		arr2[i].S = arr[i].S;
	}

/*	if(n<=3000){
		FOR(i,0,n)
			FOR(j,i+1,n)
				if((arr[i].S- arr[j].S)*l2 <= (arr[i].F - arr[j].F)*l1
					&& (arr[i].S - arr[j].S)*r2 >= (arr[i].F - arr[j].F)*r1)
					++ans;
		cout<<ans<<endl;
	}
	else*/ if(l1/l2==-1e9 && !(l1%l2)){
		FOR(i,0,n)
			arr[i].S = r2*arr[i].S - r1*arr[i].F;
		cout<<nish(0,n)<<endl;
	}
	else{
		FOR(i,0,n)
			arr[i].S = r2*arr[i].S - r1*arr[i].F;
		ans = nish(0,n);
		FOR(i,0,n)
			arr2[i].S = l2*arr2[i].S - l1*arr2[i].F;
		
		ans -= nish_2(0,n);
		cout<<ans<<endl;
	}
	return 0;
}
