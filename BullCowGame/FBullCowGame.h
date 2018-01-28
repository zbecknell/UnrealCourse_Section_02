#pragma once

#include <string>

using FString = std::string;
using int32 = int;

// all values initialized to zero
struct FBullCowCount{
    int32 Bulls = 0;
    int32 Cows = 0;
};

class FBullCowGame{
public:
    FBullCowGame(); // Constructor!

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;
    int32 GetHiddenWordLength() const;


    void Reset();
    bool CheckGuessValidity(FString);

    // provide a method for counting bulls and cows, and incrementing turn number
    // assumes valid guess
    FBullCowCount SubmitGuess(FString guess);

// Don't worry about these things right now... pay attention to the public interface
private:
    // Go to the dang ole constructor for the init!!!!!
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
};
