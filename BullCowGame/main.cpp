#include <iostream>

void PrintIntro();
std::string GetGuess();

// the entry point for our application
int main() {
    PrintIntro();
    std::string guess = GetGuess();
    std::cout << "Your guess was: " << guess << std::endl;
}

void PrintIntro(){
    constexpr int WORD_LENGTH = 9;

    std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
    std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}

std::string GetGuess(){
    // get a guess from the player
    std::string guess;

    std::cout << "Enter your guess: ";
    getline(std::cin, guess);
    return guess;
}
