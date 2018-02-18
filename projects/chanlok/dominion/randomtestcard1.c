#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "smithy"

int main(){
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int player = 0;
	int prevHand = 0;
	int curHand = 0;
	int prevDeck = 0;
	int curDeck = 0;
	int i;
	struct gameState G;

	srand(time(NULL));
	
	for (i = 0; i < 10000; i++) {
		printf("----------------- Random Testing Card (%d): %s ----------------\n", i + 1, TESTCARD);

		initializeGame(numPlayers, k, seed, &G);

		// in the beginning, deck count cannot be less than 3
		G.handCount[player] = rand() % MAX_HAND;
		G.deckCount[player] = rand() % MAX_DECK + 3;
		
		// previous hand count and deck count
		prevHand = G.handCount[player];
		prevDeck = G.deckCount[player];
		smithyAction(player, &G, 0);

		// current hand count and deck count
		curHand = G.handCount[player];
		curDeck = G.deckCount[player];

		printf("\nTesing hand count:\n");
		printf("Expected hand count: %d, Actual hand count: %d\n", prevHand + 2, curHand);
		if (curHand == prevHand + 2) {
			printf("Success\n");
		} else {
			printf("Failed\n");
		}
		assert(curHand == prevHand + 2);

		printf("\nTesing deck Count:\n");
		printf("Expected deck count: %d, Actual deck count: %d\n", prevDeck - 3, curDeck);
		if (curDeck == prevDeck - 3) {
			printf("Success\n");
		}
		else {
			printf("Failed\n");
		}
		assert(curDeck == prevDeck - 3);
	}

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}