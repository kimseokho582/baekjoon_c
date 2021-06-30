using namespace std;

long long gcd(long long x, long long y) {
	long long tmp;
	while (y != 0) {
		tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}

long long solution(int w, int h) {
	long long answer = 1;
	long long nw = w / gcd(w, h), nh = h / gcd(w, h);
	answer = (long long)w * h - (nw + nh - 1) * gcd(w, h);


	return answer;
}