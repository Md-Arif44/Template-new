/**
 * Author: 
 * Date:  
 * License:  
 * Source: 
 * Description: 
 */
/*
Count x in [L, R]:
gcd(x, m) = k   (k ≥ 1, k | m)
1 ≤ L ≤ R
Σ_{d | (m/k)} μ(d) ·
( ⌊R/(k·d)⌋ − ⌊(L−1)/(k·d)⌋ )

Count pairs (i, j) in ranges:
gcd(i, j) = k   (k ≥ 1)
1 ≤ l1 ≤ r1, 1 ≤ l2 ≤ r2
Σ_{d=1}^{min(⌊r1/k⌋, ⌊r2/k⌋)} μ(d) ·
( ⌊r1/(k·d)⌋ − ⌊(l1−1)/(k·d)⌋ ) ·
( ⌊r2/(k·d)⌋ − ⌊(l2−1)/(k·d)⌋ )

Count pairs (i, j) in an array a[]
gcd(a[i], a[j]) = k   (k ≥ 1)
Let cnt[x] = number of elements in a divisible by x  
Σ_{d=1}^{⌊Max/k⌋} μ(d) · cnt[d·k]^2
*/

const int N = 5e5 + 9;
int mob[N];
void mobius() {
  mob[1] = 1;
  for (int i = 2; i < N; i++){
    mob[i]--;
    for (int j = i + i; j < N; j += i) {
      mob[j] -= mob[i];
    }
  }
}
