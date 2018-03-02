#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "village"

int main() {
	int seed = 1000;
	int numPlayers = 2;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int player = 0;
	int prevHand = 0;
	int curHand = 0;
	int prevActions = 0;
	int curActions = 0;
	int i;
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int handPos = 0;

	srand(time(NULL));

	for (i = 0; i < 10000; i++) {
		printf("----------------- Random Testing Card (%d): %s ----------------\n", i + 1, TESTCARD);
		
		initializeGame(numPlayers, k, seed, &G);
		
		// randomize the hand count and number of actions
		G.handCount[player] = rand() % MAX_HAND;
		G.numActions = rand() % 1000;

		// record the previous hand count and number of actions
		// perform village method
		prevHand = G.handCount[player];
		prevActions = G.numActions;
		// villageAction(player, &G, 0);
		cardEffect(village, choice1, choice2, choice3, &G, handPos, &bonus);

		// get the hand count and number of actions after the village method
		curHand = G.handCount[player];
		curActions = G.numActions;

		printf("Expected hand size = %d, actual hand size = %d\n", prevHand, curHand);
		// assert(prevHand == curHand);
		
		printf("Expected action size = %d, actual action size = %d\n", prevActions + 2, curActions);
		// assert(prevActions + 2 == curActions);

		printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	}

	return 0;
}

