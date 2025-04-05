#include<bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
    long long exp = n; // Use long long to prevent overflow
    if (exp < 0) {
        x = 1 / x; // Convert to positive exponent
        exp = -exp;
    }
    
    double res = 1.0;
    while (exp > 0) {
        if (exp & 1) { // If exponent is odd, multiply result
            res *= x;
        }
        x *= x;  // Square the base
        exp /= 2;  // Reduce exponent by half
    }
    return res;
}
int main(){
    int n;
    double x;
    cin>>x>>n;
    double ans = myPow(x,n);
    cout<<fixed<<setprecision(5)<<ans<<endl;
    return 0;
}