
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<string>
#include<deque>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
const int n = 300010;
int tree[n];
void add(int k, int val)
{
    while (k <= n)
    {
        tree[k] ^= val; //加号改^号
        k += k & -k; //这里是下标的操作，不能动
    }
}
int getsum(int k)
{
    int sum = 0;
    while (k)
    {
        sum ^= tree[k]; //加号改^号
        k -= k & -k; //
    }
    return sum;
}

int N, Q;
int t, x, y;

int main(void)
{
    scanf("%d%d", &N, &Q);
    int num;
    for (int i = 1 ; i <= N ; i++) {
    	scanf("%d", &num);
    	add(i, num);
	}
	
	
	for (int i = 0 ; i < Q ; i++)
	{
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1) {
			add(x, y);
		} else {
			int numA = getsum(y);
			int numB = getsum(x - 1);
			int ans = numA ^ numB;
			printf("%d\n", ans);
		}
    }    

    return 0;
}
