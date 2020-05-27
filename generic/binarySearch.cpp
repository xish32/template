//Problem: You are given n binary values x0, x1, . . . , xn?1, such that xi ¡Ê {0, 1}. This array
//represents holes in a roof (1 is a hole). You are also given k boards of the same size. The goal
//is to choose the optimal (minimal) size of the boards that allows all the holes to be covered
//by boards.
//Solution: The size of the boards can be found with a binary search. If size x is sufficient to
//cover all the holes, then we know that sizes x+ 1, x+ 2, . . . , n are also sufficient. On the other
//hand, if we know that x is not sufficient to cover all the holes, then sizes x ? 1, x ? 2, . . . , 1
//are also insufficient

//¶þ·ÖËÑË÷ÊµÀý 

int check(int A[], int szA, int k)

{
	int boards = 0;
	int last = -1;
	for (int i = 0 ; i < n ; i++)
	{
		if (A[i] == 1 && last < i)
		{
			boards = boards + 1;
			last = i + k - 1;
		}			
	}
	return boards;
}

int binarySearch(int A[], int szA, int k)
{
	int n = szA;
	int head = 0;
	int tail = szA - 1;
	int result = -1;
	int mid;
	
	while (head <= tail)
	{
		mid = (head + tail) / 2;
		if (check(A, szA, mid) <= k)
		{
			tail  = mid - 1;
			result = mid;
		}
		else
		{
			head = mid + 1;
		}
	}
	
	return result;
}


