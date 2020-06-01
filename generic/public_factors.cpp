#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <iterator>
#include <cmath>
#include <set>
#include <deque> 
#include <string>


using namespace std;

const int MOD = 1000000007;


vector<int> getFactors(long long num)
{
	std::vector<int> factors;
	if (num % 2 == 0)
	{
		factors.push_back(2);
		while (num % 2 == 0)
			num = num / 2;
	}
	
	long long d = 3;
	while ((d * d) <= num)
	{
//		printf("%d\n", d);
		if (num % d == 0)
		{
			factors.push_back(d);
			while (num % d == 0)
				num = num / d;
		}
		d = d + 2;
	}
	
	if (num > 1)
		factors.push_back(num);
		
	return factors;
}

long long f[110];

long long getPow(long long base, long long t)
{
	if (t <= 100)
		return f[t];
		
	if ((t <= 100) && (f[t] > 0))
		return f[t];
		
	long long r = t % 2;
	
	long long t1 = getPow(base, t / 2);
	long long ans = t1 * t1 % MOD;
	
	if (r == 1)
		ans = ans * base % MOD;
	
	return ans;
}


int main(){
	vector<int> factors = getFactors(60);
	for (int i = 0 ; i < factors.size() ; i++) {
		printf("%d ", factors[i]);
	}
	printf("\n");
	
	return 0;
}
