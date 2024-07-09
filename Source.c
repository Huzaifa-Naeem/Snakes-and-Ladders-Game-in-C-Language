include <stdio.h> 
include <stdlib.h>  
include <time.h>  
include <string.h> 

int scoreMeter1(int commandControl1, int lines1[]);
int scoreMeter2(int commandControl2, int lines2[]);


int main()

{
	
	printf("\t\t\tTHE GAME OF SNAKES AND LADDERS\n"
		"----------------------------------------------"
		"----------------------------------------\n\n");

	printf("Your Playing Board is\n");
	int a[100] = { 100,99,98,97,96,95,94,93,92,91,
		90,89,88,87,86,85,84,83,82,81,
		80,79,78,77,76,75,74,73,72,71,
		70,69,68,67,66,65,64,63,62,61,
		60,59,58,57,56,55,54,53,52,51,
		50,49,48,47,46,45,44,43,42,41,
		40,39,38,37,36,35,34,33,32,31,
		30,29,28,27,26,25,24,23,22,21,
		20,19,18,17,16,15,14,13,12,11,
		10,9,8,7,6,5,4,3,2,1 }, newline = 0;




	for (int counter = 0; counter < 100; counter++)

	{
		newline++;

		switch (a[counter]) {

		case 1:
			printf("\t(\\o/)");
			break;

		case 35:
		case 26:
		case 17:
		case 44:
		case 53:
		case 62:
		case 89:
		case 69:
		case 79:
		case 59:
			printf("\t/-/");
			break;

		case 3:
		case 10:
		case 13:
		case 20:
		case 30:
		case 47:
		case 57:
		case 67:
		case 77:
		case 87:
			printf("\t@");
			break;

		case 97:
		case 23:
		case 40:
			printf("\t<");
			break;

		default:
			printf("\t%2d", a[counter]);
			break;

		}
		

		if (newline == 10) {
			printf("\n");
			newline = 0;
		}

	}

	char rollCommand[10] = { 0 };

	int lower = 1, upper = 6, count = 10, num1 = 1, commandControl1 = 0, commandControl2 = 0, num2 = 1;

	int lines1[10] = { 0 }, lines2[10] = { 0 };

	srand(time(0));


	while (commandControl1 < 100 && commandControl2 < 100) {

		//Roll Sequence for Both Players
		printf("\nPlayers, Type Roll in order to roll the Dice\n");
		scanf_s("%9s", rollCommand, 5);

		while (!(strcmp(rollCommand, "roll") == 0) && !(strcmp(rollCommand, "Roll") == 0)) {
			printf("Please Type proper command 'Roll'\n");
			scanf_s("%9s", rollCommand, 5);
		}


		if (strcmp(rollCommand, "roll") == 0 || strcmp(rollCommand, "Roll") == 0) {

			num1 = (rand() % (upper - lower + 1)) + lower;
			num2 = (rand() % (upper - lower + 1)) + lower;
			printf("Dice Number is :\n \t\t\tFor Player 1: %d  "
				"\tFor Player 2: %d\n\n\n", num1, num2);

		}

		commandControl1 = num1 + commandControl1;
		commandControl2 = num2 + commandControl2;


		printf("\t\t\tPlayer 1 Score: %d\t Player 2 Score: %d\n\n"
			"Current Positions of Players\n\n",
			scoreMeter1(commandControl1, lines1), scoreMeter2(commandControl2, lines2));
		

		for (int counter = 0; counter < 100; counter++) {
		
			//In case any Player's Dice overshoots 100,repeat the turn for that player
			if (commandControl1 > 100) {
				commandControl1 = commandControl1 - num1;
				

			}
			if (commandControl2 > 100) {
				commandControl2 = commandControl2 - num2;
				
			}
			

			newline++;

			//when the particular element of array is reached, print \o/ or (^-^) otherwise continue  
			if (a[counter] == commandControl1) {

				printf("\t(\\o/) ");

			}
			else if (a[counter] == commandControl2) {

				printf("\t(^-^)");
			}

			//codes responsible for printing snakes and ladders 

			else switch (a[counter]) {

			case 35:
			case 26:
			case 17:
			case 44:
			case 53:
			case 62:
			case 89:
			case 69:
			case 79:
			case 59:
				printf("\t/-/");
				break;

			case 3:
			case 10:
			case 13:
			case 20:
			case 30:
			case 47:
			case 57:
			case 67:
			case 77:
			case 87:
				printf("\t@");
				break;

			case 97:
			case 23:
			case 40:
				printf("\t<");
				break;

			default:
				printf("\t%2d", a[counter]);
				break;

			}
			

			//start a newline after every ten elements 
			if (newline == 10)

			{
				printf("\n");
				newline = 0;
			}

			//Rewards and Penalties for Player 1
			switch (commandControl1) {

			case 17://ladder 
				commandControl1 = 62;
				break;

			case 59://ladder 
				commandControl1 = 89;
				break;

			case 40://snake 
				commandControl1 = 10;
				break;

			case 97://snake 
				commandControl1 = 47;
				break;

			case 23://snake 
				commandControl1 = 3;
				break;
			default:

				break;
			}


			//Rewards and Penalties for Player 2
			switch (commandControl2) {

			case 17://ladder
				commandControl2 = 62;
				break;
			case 59://ladder
				commandControl2 = 89;
				break;
			case 40://snake
				commandControl2 = 10;
				break;
			case 97://snake
				commandControl2 = 47;
				break;
			case 23://snake
				commandControl2 = 3;
				break;
			default:
				break;
			}



		}

	}

	if (scoreMeter1(commandControl1, lines1) > scoreMeter2(commandControl2, lines2)) {
		printf("\t\tCongratulations, Player 1 has won the game\n"
			"\t\tPlayer 2, Better luck next time");

	}
	else if (scoreMeter1(commandControl1, lines1) == scoreMeter2(commandControl2, lines2)) {
		printf("\t\tThe Game has ended in a draw\n");
	}
	else {
		printf("\t\tCongratulations, Player 2 has won the game\n"
			"\t\tPlayer 1, Better luck next time");
	}; 


	return 0;
}

int scoreMeter1(int commandControl1, int lines1[]) {

	static int score1 = 500;
	
	switch (commandControl1) {

	case 17://ladder
		score1 = score1 +(20*5);
		lines1[3] = 1;
		lines1[4] = 1;
		lines1[5] = 1;
		
		break;
	case 59://ladder
		score1 = score1 + (20 * 3);
		lines1[7] = 1;
		break;
	case 23://snake
		score1 = score1 - (20 * 2);
		lines1[0] = 0;
		lines1[1] = 0;
		break;
	case 40://snake
		score1 = score1 - (20 * 3);
		lines1[0] = 0;
		lines1[1] = 0;
		lines1[2] = 0;

		break;
	case 97://snake
		score1 = score1 - (20 * 5);
		
		lines1[4] = 0;
		lines1[5] = 0;
		lines1[6] = 0;
		lines1[7] = 0;
		lines1[8] = 0;
		break;

	default:
		break;
	}

	//score for jumping up rows
	switch (commandControl1 / 10) {

	case 1:
		if (lines1[0] == 0 && commandControl1 !=10) {
			score1 = score1 + 20;
			lines1[0] = 1;
			break;
		}
		break;
	case 2:
		if (lines1[1] == 0 && commandControl1 != 20) {
			score1 = score1 + 20;
			lines1[1] = 1;
			break;
		}
		break;
	case 3:
		if (lines1[2] == 0 && commandControl1 != 30) {
			score1 = score1 + 20;
			lines1[2] = 1;
			break;
		}
		break;
	case 4:
		if (lines1[3] == 0 && commandControl1 != 40) {
			score1 = score1 + 20;
			lines1[3] = 1;
			break;
		}
		break;
	case 5:
		if (lines1[4] == 0 && commandControl1 != 50) {
			score1 = score1 + 20;
			lines1[4] = 1;
			break;
		}
		break;
	case 6:
		if (lines1[5] == 0 && commandControl1 != 60) {
			score1 = score1 + 20;
			lines1[5] = 1;
			break;
		}
		break;
	case 7:
		if (lines1[6] == 0 && commandControl1 != 70) {
			score1 = score1 + 20;
			lines1[6] = 1;
			break;
		}
		break;
	case 8:
		if (lines1[7] == 0 && commandControl1 != 80) {
			score1 = score1 + 20;
			lines1[7] = 1;
			break;
		}
		break;
	case 9:
		if (lines1[8] == 0 && commandControl1 != 90 && commandControl1 != 97) {
			score1 = score1 + 20;
			lines1[8] = 1;
			break;
		}
		break;

	default:
		break;
	}
	if (commandControl1 == 100) {
		score1 = score1 + 200;
	}
	score1 = score1 - 5;
	
	return score1;

}

int scoreMeter2(int commandControl2, int lines2[]) {

	static int score2 = 500;

	switch (commandControl2) {

	case 17://ladder
		score2 = score2 + (20 * 5);
		lines2[3] = 1;
		lines2[4] = 1;
		lines2[5] = 1;
		break;
	case 59://ladder
		score2 = score2 + (20 * 3);
		lines2[7] = 1;
		break;
	case 23://snake
		score2 = score2 - (20 * 2);
		lines2[0] = 0;
		lines2[1] = 0;
		break;
	case 40://snake
		score2 = score2 - (20 * 3);
		lines2[0] = 0;
		lines2[1] = 0;
		lines2[2] = 0;

		break;
	case 97://snake
		score2 = score2 - (20 * 5);
		
		lines2[4] = 0;
		lines2[5] = 0;
		lines2[6] = 0;
		lines2[7] = 0;
		lines2[8] = 0;

		break;

	default:
		break;
	}

	//score for jumping up rows
	switch (commandControl2 / 10) {

	case 1:
		if (lines2[0] == 0 && commandControl2 != 10) {
			score2 = score2 + 20;
			lines2[0] = 1;
			break;
		}
		break;
	case 2:
		if (lines2[1] == 0 && commandControl2 != 20) {
			score2 = score2 + 20;
			lines2[1] = 1;
			break;
		}
		break;
	case 3:
		if (lines2[2] == 0 && commandControl2 != 30) {
			score2 = score2 + 20;
			lines2[2] = 1;
			break;
		}
		break;
	case 4:
		if (lines2[3] == 0 && commandControl2 != 40) {
			score2 = score2 + 20;
			lines2[3] = 1;
			break;
		}
		break;
	case 5:
		if (lines2[4] == 0 && commandControl2 != 50) {
			score2 = score2 + 20;
			lines2[4] = 1;
			break;
		}
		break;
	case 6:
		if (lines2[5] == 0 && commandControl2 != 60) {
			score2 = score2 + 20;
			lines2[5] = 1;
			break;
		}
		break;
	case 7:
		if (lines2[6] == 0 && commandControl2 != 70) {
			score2 = score2 + 20;
			lines2[6] = 1;
			break;
		}
		break;
	case 8:
		if (lines2[7] == 0 && commandControl2 != 80) {
			score2 = score2 + 20;
			lines2[7] = 1;
			break;
		}
		break;
	case 9:
		if (lines2[8] == 0 && commandControl2 != 90 && commandControl2 != 97) {
			score2 = score2 + 20;
			lines2[8] = 1;
			break;
		}
		break;

	default:
		break;
	}
	if (commandControl2 == 100) {
		score2 = score2 + 200;
	}

	score2 = score2 - 5;
	return score2;

}
