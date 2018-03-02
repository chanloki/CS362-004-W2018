/*
 * unittest2.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
	struct gameState G;
	int numPlayers = 2;
	int seed = 1000;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
	int i;

	printf("----------------- Unit Test 2 ----------------\n");
	printf("Testing handCard\n");

	initializeGame(numPlayers, k, seed, &G);
	
	for (i = 0; i < 5; i++) {
		printf("actual = %d, expected = %d\n", handCard(i, &G), G.hand[G.whoseTurn][i]);
		assert(handCard(i, &G) == G.hand[G.whoseTurn][i]);
	}
	
	printf("\n >>>>> SUCCESS: Unit Test 2 complete <<<<<\n\n");

	return 0;
}


