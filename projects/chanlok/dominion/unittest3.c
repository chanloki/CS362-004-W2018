/*
 * unittest3.c
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
	int currentPlayer = 0;

	printf("----------------- Unit Test 3 ----------------\n");
	
	printf("Testing fullDeckCount\n");

	initializeGame(numPlayers, k, seed, &G);
	
	// each player receives 7 copper and 3 estates as a starting deck
	printf("actual copper # = %d, expected copper # = %d\n", fullDeckCount(currentPlayer, copper, &G), 7);
	printf("actual estates # = %d, expected estates # = %d\n", fullDeckCount(currentPlayer, estate, &G), 3);
	
	// add two copper cards to player 2
	currentPlayer = 1;
	G.discard[currentPlayer][0] = copper;
	G.discard[currentPlayer][1] = copper;
	G.discardCount[currentPlayer] += 2;
	printf("add two copper cards to the palyer\n");
	printf("actual copper # = %d, expected copper # = %d\n", fullDeckCount(currentPlayer, copper, &G), 9);
	printf("actual estates # = %d, expected estates # = %d\n", fullDeckCount(currentPlayer, estate, &G), 3);
	
	printf("\n >>>>> SUCCESS: Unit Test 3 complete <<<<<\n\n");

	return 0;
}
