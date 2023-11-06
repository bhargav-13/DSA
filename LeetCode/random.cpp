#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int o = 0, e = 0;
	while(n >0){
		int t = n%10;
		n = n/10;

		if(t%2 == 0){
			e += t;
		}
		else{
			o += t;
		}
	}

	cout << e << " " << o << endl;
}
