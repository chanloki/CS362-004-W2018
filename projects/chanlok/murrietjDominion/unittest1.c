/*
 * unittest1.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
	printf("----------------- Unit Test 1 ----------------\n");

	printf("Testing card that does not exist\n");
	printf("actual cost = %d, expected cost = %d\n", getCost(1000), -1);
	assert(getCost(1000) == -1);

	printf("Testing curse\n");
	printf("actual cost = %d, expected cost = %d\n", getCost(curse), 0);
	assert(getCost(curse) == 0);

	printf("Testing estate\n");
	printf("actual cost = %d, expected cost = %d\n", getCost(estate), 2);
	assert(getCost(estate) == 2);

	printf("Testing silver\n");
	printf("actual cost = %d, expected cost = %d\n", getCost(silver), 3);
	assert(getCost(silver) == 3);

	printf("Testing feast\n");
	printf("actual cost = %d, expected cost = %d\n", getCost(feast), 4);
	assert(getCost(feast) == 4);

	printf("Testing duchy\n");
	printf("actual cost = %d, expected cost = %d\n", getCost(duchy), 5);
	assert(getCost(duchy) == 5);

	printf("Testing gold\n");
	printf("actual cost = %d, expected cost = %d\n", getCost(gold), 6);
	assert(getCost(gold) == 6);

	printf("Testing province\n");
	printf("actual cost = %d, expected cost = %d\n", getCost(province), 8);
	assert(getCost(province) == 8);
	
	printf("\n >>>>> SUCCESS: Unit Test 1 complete <<<<<\n\n");

	return 0;
}


