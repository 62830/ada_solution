#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define IFOR(i,a,b) for(int i=a-1;i>=b;--i)
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>

//for debugs
#define print(...) cout<<#__VA_ARGS__<<": "<<__VA_ARGS__<<endl;

template<typename T>
void print_arr(T arr){
	for(auto &i:arr)cout<<i<<' ';
	cout<<endl;
}

int arr[100003];

inline void pop(int a){
	FOR(i,0,a)cout<<"POP"<<endl;
}

inline void place(int a,int b){
	if(a<=b)
		IFOR(i,b+1,a)cout<<"PLACE "<<i<<endl;
	else
		FOR(i,b,a+1)cout<<"PLACE "<<i<<endl;
}

inline void photo(){
	cout<<"PHOTO"<<endl;
}

void f(int l,int r){
#ifdef DEBUG
	cout<<l<<' '<<r<<endl;
#endif
	if(l+1==r){
		place(l,l);
		photo();
		pop(1);
		return;
	}
	int m = (l+r)/2;
	place(m,r-1);
	f(l,m);
	pop(r-m);
	place(l,m-1);
	f(m,r);
	pop(m-l);
	return;
}

int g(int a){
	if(arr[a]!=0)return arr[a];
	arr[a] = g(a/2) + g((a+1)/2) + 2*a;
	return arr[a];
}

int main(){
	IO;
	int n;
	cin>>n;
	arr[1] = 2;
	g(n);
	cout<<arr[n]+n<<endl;
	f(1,n+1);
}
