/**********************************************************************
 * Libraries: You may need to add additional libraries
***********************************************************************/
#include <stdio.h>



/**********************************************************************
 * Predefined functions: Call these functions in your code to get user
 *                       input and report information to the user.
 *                       Do not modify these functions.
***********************************************************************/

// Asks the user how many rounds to play
void get_rounds(int *num_rounds) {
        printf("\n");
        printf(" Enter how many rounds you want to play:   ");
        scanf("%d", num_rounds);
        printf("\n");
}

// Asks the user whether the player cooperates or not
// The result is passed back by the pointer 'move'
void get_player_move(int *move) {
        printf(" Does the player cooperate (1) or not (0): ");
        scanf("%d", move);
}

// Prints the moves both players are making
void print_moves(int move_player1, int move_player2) {
        printf(" Player 1 played %d", move_player1);
        printf(" and player 2 played %d \n", move_player2);
        printf("\n");
}

// Prints the final score for the two players 
void print_scores(int score_player1, int score_player2) {
        printf(" Player 1 score:  %d\n", score_player1);
        printf(" Player 2 score:  %d\n", score_player2);
        printf("\n");
}

/**********************************************************************
 * Main functionality: Write your code for implementing the game of 
 *                     trust below.
***********************************************************************/

int main(){
	int rounds = 0;
	get_rounds(&rounds);
	int p1 = 0;
	int p2 = 0;
	//player 1
	int currentMoveP1 = -1;
	//player 2
	int currentMoveP2 = -1;

	int i;
	for(i=0; i<rounds;i++){
		get_player_move(&currentMoveP1);
		get_player_move(&currentMoveP2);
		if(currentMoveP1 == 1 && currentMoveP2 == 1){ //both coorporate
			p1 = p1 + 2;
			p2 = p2 + 2;
		}
		else if(currentMoveP1 > currentMoveP2){ //only P1 coorporates, P2 cheats
			p1 = p1 - 1;
			p2 = p2 + 3;
		}
		else if(currentMoveP2 > currentMoveP1){ //only P2 coorporates, P1 cheats
			p2 = p2 -1;
			p1 = p1 + 3;
		}
		print_moves(currentMoveP1, currentMoveP2);
	}
	print_scores(p1, p2);
}
