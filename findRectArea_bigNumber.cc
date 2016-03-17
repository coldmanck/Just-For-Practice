#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int solution(int K, int L, int M, int N, int P, int Q, int R, int S) {
    // check if area A is bigger than 2147483647
    // Area = dx *dy, dx * dy > INT_MAX <=> dx > INT_MAX / dy
    if(N - L != 0){
        if((M - K) > (static_cast<int>(INT_MAX / (N - L))) ) 
            return -1;
    } else if(M - K != 0){
        if((N - L) > (static_cast<int>(INT_MAX / (M - K))) ) 
            return -1;
    }
    
    // check if area B is bigger than 2147483647    
    if(S - Q != 0){
        if((R - P) > (static_cast<int>(INT_MAX / (S - Q))) ) 
            return -1;
    } else if(R - P != 0){
        if((S - Q) > (static_cast<int>(INT_MAX / (R - P))) ) 
            return -1;
    }

    int areaA = (M - K) * (N - L);
    int areaB = (R - P) * (S - Q);
    
    // check if total area is bigger than 2147483647
    if(areaA > static_cast<int>(INT_MAX - areaB)) return -1;
    int totalArea = areaA + areaB;
    
    int x1 = max(K, P);
    int x2 = min(M, R);
    int y1 = max(L, Q);
    int y2 = min(N, S);
    
    if(x2 > x1 && y2 > y1)  // verify the rectangle
        return totalArea - (x2 - x1) * (y2 - y1);
    return totalArea;
}

int main(){
	int k, l, m, n, p, q, r, s;
	cin >> k >> l >> m >> n >> p >> q >> r >> s;
	cout << solution(k, l, m, n, p, q, r, s) << endl;

	return 0;
}
