#include<stdio.h>

static inline int abs2(int);
unsigned find_closest_number(int*, size_t);

static inline int
abs2(int x)
{
	return x < 0 ? -x : x;
}

unsigned
find_closest_number(int *nums, size_t n)
{
	int x = 0;
	int closest = abs2(nums[0]);
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
