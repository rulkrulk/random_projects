#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to determine the game result
int game(char you, char computer) {
    // Draw
    if (you == computer) {
        return -1;
    }

    // Rock vs Paper
    else if (you == 'r' && computer == 'p') {
        return 0;
    }

    // Rock vs Scissors
    else if (you == 'r' && computer == 's') {
        return 1;
    }

    // Scissors vs Paper
    else if (you == 's' && computer == 'p') {
        return 1;
    }

    // Scissors vs Rock
    else if (you == 's' && computer == 'r') {
        return 0;
    }

    // If you enter an invalid character
    return -2; // Invalid input
}

int main() {
    int n;
    char you;
    char computer;

    // Seed the random number generator
    srand(time(NULL));

    // Generate random choice for computer
    n = rand() % 3; // Generate a number between 0 and 2

    if (n == 0) {
        computer = 'r'; // Rock
    } else if (n == 1) {
        computer = 'p'; // Paper
    } else {
        computer = 's'; // Scissors
    }

    // Prompt the user for input
    printf("Enter your choice (r for rock, p for paper, s for scissors): ");
    scanf(" %c", &you); // Added a space before %c to ignore whitespace

    // Determine the result of the game
    int result = game(you, computer);

    // Print the result
    if (result == -1) {
        printf("It's a draw! You both chose %c.\n", computer);
    } else if (result == 1) {
        printf("You win! %c beats %c.\n", you, computer);
    } else if (result == 0) {
        printf("You lose! %c beats %c.\n", computer, you);
    } else {
        printf("Invalid input! Please enter r, p, or s.\n");
    }

    return 0;
}
