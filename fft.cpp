//BEGIN
#include <iostream>
#include <complex>
#include <cassert>
using namespace std;

typedef complex<long double> Complex;
long double PI = 2 * acos(0.0L);

// N must be power of 2
// dir = 1 is forward, dir = -1 inverse
// Inverse is scaled
void FFT(Complex *a, int N, int dir) {
	int lgN;
	for (lgN = 1; (1 << lgN) < N; lgN++);
	assert((1 << lgN) == N);

	for (int i = 0; i < N; i++) {
		int j = 0;
		for (int k = 0; k < lgN; k++)
			j |= ((i >> k) & 1) << (lgN - 1 -k);
		if (i < j)
			swap(a[i], a[j]);
	}

	for (int s = 1; s <= lgN; s++) {
		int h = 1 << (s - 1);
		Complex t, w, w_m = exp(Complex(0, dir * PI / h));
		for (int k = 0; k < N; k += h + h) {
			w = 1;
			for (int j = 0; j < h; j++) {
				t = w * a[k + j + h];
				a[k + j+ h] = a[k + j] - t;
				a[k + j] += t;
				w *= w_m;
			}
		}
	}
	if (dir == 1)
		return;

	for (int i = 0; i < N; i++) {
		a[i] /= N;
	}

}
// END
