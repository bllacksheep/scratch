/*
 * O(n) time complexity
 * O(1) space complexity
 * */

#include<stdio.h>

static inline unsigned abs2(int);
unsigned find_closest_number(int*, size_t);

// unsigned above -INT_MAX UB overflow
static inline unsigned
abs2(int x)
{
	return (x < 0) ? -(unsigned)x :(unsigned)x;
}

unsigned
find_closest_number(int *nums, size_t n)
{
	unsigned x = 0;
	unsigned closest = abs2(nums[0]);
	for (int i = 0; i < n; i++) {
		x = abs2(nums[i]);
		if (x < closest && x != 0)
			closest = x;
	}

	return closest;
}

int
main(void) {
	// arrays are not pointers, you can't use the { ... } initializer with *p
	signed int arr[] = {-2, -1, 0, 1, 2};
	signed int *p = arr;
	int n = find_closest_number(p, sizeof(arr)/sizeof(arr[0]));
	printf("%d\n", n);
	return 0;
}
