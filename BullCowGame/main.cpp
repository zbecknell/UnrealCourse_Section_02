/* This is the console executable that makes use of the BullCow class
This acts as the view in an MVC pattern, and is responsible for all
user interaction. For game logic, see the FBullCowGame class.

*/

#include <iostream>
#include "FBullCowGame.h"

using FText = std::string;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

// the entry point for our application
int main()
{
    bool bPlayAgain;
    do{
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    } while (bPlayAgain);
}

void PrintIntro()
{
    std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
}

void PlayGame()
{
    BCGame.Reset();
    int32 maxTries = BCGame.GetMaxTries();

    for (int32 i = 0; i < maxTries; ++i)
    {
        FText guess = GetGuess(); // TODO: make loop checking valid

        // Submit valid guess to the game
        FBullCowCount BullCowCount = BCGame.SubmitGuess(guess);
        // Print number of bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

        std::cout << "Your guess was: " << guess << std::endl << std::endl;
    }

    // TODO: Add a game summary
}

FText GetGuess()
{
    // get a guess from the player
    FText guess;

    std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
    getline(std::cin, guess);
    return guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? ";
    FText response;

    getline(std::cin, response);

    char firstChar = response[0];

    return firstChar == 'y' || firstChar == 'Y';
}
