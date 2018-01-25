#include <iostream>

using namespace std;

void PrintIntro();

void PlayGame();

std::string GetGuess();

bool AskToPlayAgain();

// the entry point for our application
int main()
{
    do{
        PrintIntro();
        PlayGame();
    } while (AskToPlayAgain());
}

void PrintIntro()
{
    constexpr int WORD_LENGTH = 9;

    cout << "Welcome to Bulls and Cows, a fun word game." << endl;
    cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}

void PlayGame()
{
    constexpr int NUMBER_OF_GUESSES = 5;

    for (int i = 0; i < NUMBER_OF_GUESSES; ++i)
    {
        string guess = GetGuess();
        cout << "Your guess was: " << guess << endl << endl;
    }
}

std::string GetGuess()
{
    // get a guess from the player
    std::string guess;

    std::cout << "Enter your guess: ";
    getline(std::cin, guess);
    return guess;
}

bool AskToPlayAgain()
{
    cout << "Do you want to play again? ";
    string response;

    getline(cin, response);

    char firstChar = response[0];

    return firstChar == 'y' || firstChar == 'Y';
}
