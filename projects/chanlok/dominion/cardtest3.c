/*
 * cardtest3.c
 * Test Village
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"

int main() {
	int seed = 1000;
	int numPlayers = 2;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	int thisPlayer = 0;

	initializeGame(numPlayers, k, seed, &G);
	
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	int handSizeBefore = numHandCards(&G);
	int numActionsBefore = G.numActions;
	
	villageAction(thisPlayer, &G, 0);
	printf("Expected hand size = %d, actual hand size = %d\n", handSizeBefore, G.handCount[thisPlayer]);
	printf("Expected action size = %d, actual action size = %d\n", numActionsBefore+2, G.numActions);
	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}

