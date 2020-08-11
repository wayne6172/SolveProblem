
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)

struct order {
	int A;	// lowest floor
	int B;	// highest floor
	int C;	// profit
};

int fcmp(const void * a, const void * b) {
	return ((struct order*)a)->B - ((struct order*)b)->B;
}


int main() {
	int T;

	scanf("%d", &T);
	for (int num_case = 1; num_case <= T; num_case++) {
		int n;
		int min_floor = 200001;
		int profit[200001] = {};
		struct order orders[30000] = {};

		scanf("%d", &n);
		for (int i = 0;i < n;i++) {
			scanf("%d %d %d", &orders[i].A, &orders[i].B, &orders[i].C);

			orders[i].B = orders[i].A + orders[i].B - 1;
			min_floor = MIN(min_floor, orders[i].A);
		}

		// sort by highest floor
		qsort(orders, n, sizeof (struct order), fcmp);

		int i = 0;						// index for orders
		int floor = min_floor;			// start from most lowest floor
		while (i < n)
			if (orders[i].B == floor) {
				// profit = MAX(not accept, accept i-th order)
				if(orders[i].A == 0)	// start from ground
					profit[floor] = MAX(profit[floor], orders[i].C);
				else					// start from orders[i].A floor
					profit[floor] = MAX(profit[floor], profit[orders[i].A - 1] + orders[i].C);
				i += 1;
			}
			else {
				// pass max profit forward to next floor
				profit[floor + 1] = profit[floor];
				floor += 1;
			}

		printf("Case %d: %d\n", num_case, profit[floor]);
	}

	return 0;
}