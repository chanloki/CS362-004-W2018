/*
 * unittest4.c
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
	
	printf("----------------- Unit Test 4 ----------------\n");
	printf("Testing endTurn\n");

	initializeGame(numPlayers, k, seed, &G);
	
	printf("First round\n");
	printf("Play 0 hand count: actual = %d, expected = %d\n", G.handCount[0], 5);
	printf("Play 1 hand count: actual = %d, expected = %d\n", G.handCount[1], 0);
	printf("Whose Turn: actual player = %d, expected = %d\n", G.whoseTurn, 0);
	
	endTurn(&G);
	printf("After first round\n");
	printf("Play 0 hand count: actual = %d, expected = %d\n", G.handCount[0], 0);
	printf("Play 1 hand count: actual = %d, expected = %d\n", G.handCount[1], 5);
	printf("Whose Turn: actual player = %d, expected = %d\n", G.whoseTurn, 1);
	
	endTurn(&G);
	printf("After Second round\n");
	printf("Play 0 hand count: actual = %d, expected = %d\n", G.handCount[0], 5);
	printf("Play 1 hand count: actual = %d, expected = %d\n", G.handCount[1], 0);
	printf("Whose Turn: actual player = %d, expected = %d\n", G.whoseTurn, 0);	
	
	printf("\n >>>>> SUCCESS: Unit Test 4 complete <<<<<\n\n");

	return 0;
}
