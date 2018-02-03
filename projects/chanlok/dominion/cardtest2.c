/*
 * cardtest2.c
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int main() {
	struct gameState G;
	int numPlayer = 2;
	int seed = 1000;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, great_hall};	
	int currentPlayer = 0;
	int temphand[MAX_HAND];

	initializeGame(numPlayer, k, seed, &G);
	
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	adventurerAction(&G, currentPlayer, temphand);

	printf("Expected hand size = %d, actual hand size = %d\n", 7, G.handCount[currentPlayer]);
	
	// the last 2 cards are treasures
	int t1 = handCard(G.hand[currentPlayer][numHandCards(&G) - 1], &G);
	int t2 = handCard(G.hand[currentPlayer][numHandCards(&G) - 2], &G);
	assert(t1 == copper || t1 == silver || t1 == gold);
	assert(t2 == copper || t2 == silver || t2 == gold);
  	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;

}
