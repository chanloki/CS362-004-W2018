#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "adventurer"

int main(){
	int seed = 1000;
	int numPlayers;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	struct gameState G;
	int player = 0;
	int prevHand = 0;
	int i;
	int temphand[MAX_HAND];
    int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int handPos = 0;

	srand(time(NULL));
	
	for(i = 0; i < 1000; i++){
		printf("----------------- Random Testing Card (%d): %s ----------------\n", i + 1, TESTCARD);

		numPlayers = rand() % 4 + 2;
		
		initializeGame(numPlayers, k, seed, &G);
		
		prevHand = G.handCount[player] % MAX_HAND;

		G.deckCount[player] = rand() % MAX_DECK;

		printf("Previous: G.handCount[player] = %d, G.deckCount[player] = %d\n", G.handCount[player], G.deckCount[player]);
		// bug: keep drawing the card even hand count is less than 0
		// adventurerEffect(&G, player, temphand);
		cardEffect(adventurer, choice1, choice2, choice3, &G, handPos, &bonus);

		printf("Current: G.handCount[player] = %d, G.deckCount[player] = %d\n", G.handCount[player], G.deckCount[player]);
		
		printf("Testing hand count\n");			
		printf("Expected hand count: %d, actual hand count: %d\n", prevHand + 2, G.handCount[player]);

		if (prevHand + 2 == G.handCount[player]) {
			printf("Success\n");
		} else {
			printf("Failed\n");	
		}
		// assert(prevHand + 2 == G.handCount[player]);
	}

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}