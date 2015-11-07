//BEGIN
#define KMP_MAX (100001)
int kmp_T[KMP_MAX];

void kmp_init(string s) {
	size_t len = s.length();
	const char *cstr = s.c_str();
	int i, j;

	i = 0;
	j = kmp_T[0] = -1;
	while (i < (int) len) {
		while (j > -1 && cstr[i] != cstr[j])
			j = kmp_T[j];
		i++;
		j++;
		if (cstr[i] == cstr[j])
			kmp_T[i] = kmp_T[j];
		else
			kmp_T[i] = j;
	}
}

// Return the first offset where pat starts in text
// If KMP + len(pat) > len(text) only prefix was found.
size_t kmp(string pat, string text) {
	const char *x = pat.c_str();
	int m = pat.size();
	const char *y = text.c_str();
	int n = text.size();
	int i, j;

	i = j = 0;
	while (j < n) {
		while (i > -1 && x[i] != y[j])
			i = kmp_T[i];
		i++;
		j++;
		if (i >= m || j == n)
			return j - i;

	}
	return n;
}
//END
