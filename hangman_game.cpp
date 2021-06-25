#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <conio.h>

#include "words.h"

bool printBlanks(char (&player_word)[5], int num_tries)
{
    int cntr = 0;

    for(char i : player_word)     // For each element on the board's display word
    {
        std::cout << i << ' ';

        if(i != '_')        // Determines if you completed the word
        {                   // If it isn't vacant, then increase the counter (which tells how many letters you got right)
            cntr++;

            if(cntr == 5)   // If you got all the letters on display, then return true
                return true;
        }
    }
    return false;
}

bool findLetter(char (&chosen_word)[5], char (&player_word)[5])
{
    char guess;                         // Player's guess
    int cntr = 0;
    int num_correct_letters = 0;        // Determines how many letters you got right

    do
    {
        std::cout << "\nEnter guess: ";
        std::cin >> guess;
    }   while(!isalpha(guess));         // Reiterates if not a letter

    for(char letter : chosen_word)      // Checks each individual letter of the secret word
    {
        if(letter == guess)                 // If your guess and the letter match up,
        {                                   // then number of correct letters increases
            num_correct_letters++;          // And puts that correct letter on the board word
            player_word[cntr] = guess;      // This keeps on going until you are incorrect
        }
        else if (letter != guess)           // If your guess and the letter don't match up,
        {                                   // then it checks if the spot already has a letter in order to
            if(player_word[cntr] != '_')    // check the next spot. If it is vacant already, then it marks it as vacant,
            {                               // and increments the counter
                cntr++;
                continue;                   // This function's job is to count how many correct letters you got
            }                               // and to mark which spots are vacant (aka the ones that don't match up)
            player_word[cntr] = '_';
        }
        cntr++;
    }

    std::cout << "There are " << num_correct_letters << " occurrence(s) of the letter "
              << guess << " in the chosen word.\n";

    if(num_correct_letters > 0)             // If you have found some correct letters, it returns true
        return true;                        // If you found no correct letters, it returns false

    return false;
}

int main()
{
    // Seed rand
    srand((int)time(0));

    // Declare variables
    int choice;
    int num_tries = 6;
    char chosen_word[5];
    char player_word[5] = {'_', '_', '_', '_', '_'};    // Starts off as blank

    // Set a random choice
    choice = (rand() % 10) + 1;

    // Select a word from the dictionary in words.h
    dictionary(chosen_word, choice);

    // Beginning screen
    std::cout << "Welcome to Hangman! Press [ENTER] to continue.";
    getch();

    std::cout << "\nYour word has 5 letters! You have 6 tries to guess this word. Press [ENTER] to begin.";
    getch();

    // Win/loss check
    while(num_tries != 7 && num_tries != 0)
    {
        num_tries--;
        if(findLetter(chosen_word, player_word))            // If you found some correct letters,
        {                                                   // then increase the number of tries
            num_tries++;
        }
        if(printBlanks(player_word, num_tries))             // If you have all the letters on the board word completed,
        {                                                   // Then display your win and end program
            std::cout << "\n\nCongrats, you win! Press any key to exit.";
            getch();
            return 0;
        }
        std::cout << '\t' << num_tries << " tries left.\n"; // Displays how many tries you have left
    }

    // Displays loss and end program
    std::cout << "\n\nOoh, looks like you lost. The word was ";

    for(int i = 0; i < 5; ++i)
    {
        std::cout << chosen_word[i];
    }

    std::cout << ". Better luck next time! Press any key to exit.";
    getch();

    return 0;
}

