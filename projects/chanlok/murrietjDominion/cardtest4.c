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

#define TESTCARD "great_hall"

int main() {
	int seed = 1000;
	int numPlayers = 2;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, great_hall};	
	int thisPlayer = 0;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	initializeGame(numPlayers, k, seed, &G);
	
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	int handSizeBefore = numHandCards(&G);
	int numActionsBefore = G.numActions;
	
	// great_hallAction(thisPlayer, &G, 0);
	cardEffect(great_hall, choice1, choice2, choice3, &G, handpos, &bonus);

	printf("Expected hand size = %d, actual hand size = %d\n", handSizeBefore, G.handCount[thisPlayer]);
	printf("Expected action size = %d, actual action size = %d\n", numActionsBefore+1, G.numActions);
	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}

