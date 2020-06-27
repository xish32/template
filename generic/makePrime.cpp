
bool isPrime[4010];
std::vector<int> primes;

void makeP() {
	for (int i = 2 ; i <= 4000 ; i++) {
		isPrime[i] = true;
	}
	
	int p = 2;
	while (p <= 4000) {
		if (isPrime[p] == true) {
			primes.push_back(p);
			long long curNum = p;
			
			int j = 2;
			while (true) {
				curNum = p * j;
				if (curNum > 4000)
					break;
				isPrime[curNum] = false;
				j++;
			}
			
		}
		p++;
	}
}
