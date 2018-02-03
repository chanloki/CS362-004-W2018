/*
 * cardtest1.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
	int newCards = 0;
	int discarded = 1;
	int xtraCoins = 0;
	int shuffledCards = 0;

	int handpos = 0, bonus = 0;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// add 3 more cards
	memcpy(&testG, &G, sizeof(struct gameState));
	smithyAction(thisPlayer, &testG, handpos);

	newCards = 3;
	xtraCoins = 0;
	printf("Expected hand size = %d, actual hand size = %d\n", G.handCount[thisPlayer] + newCards - discarded, testG.handCount[thisPlayer]);
	printf("Expected deck size = %d, actual deck size = %d\n", G.deckCount[thisPlayer] - newCards + shuffledCards, testG.deckCount[thisPlayer]);
	printf("Expected coins = %d, actual coins = %d\n", G.coins + xtraCoins, testG.coins);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
	assert(testG.coins == G.coins + xtraCoins);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}
