#include "FBullCowGame.h"

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

FBullCowGame::FBullCowGame(){
    Reset();
}

bool FBullCowGame::IsGameWon() const {
    return false;
}

bool FBullCowGame::CheckGuessValidity(FString) {
    return false;
}

void FBullCowGame::Reset() {

    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "planet";

    MyMaxTries = MAX_TRIES;
    MyCurrentTry = 1;
    MyHiddenWord = HIDDEN_WORD;
}

// receives a valid guess and increments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString guess) {
    // increment the turn
    MyCurrentTry++;

    // set up a return variable
    FBullCowCount BullCowCount;

    // loop through all letters in the guess
    int32 HiddenWordLength = MyHiddenWord.length();

    for(int32 i = 0; i < HiddenWordLength; i++){
        // compare letters against the hidden word
        for(int32 j = 0; j < HiddenWordLength; j++){

            // if they match then
            if(guess[i] == MyHiddenWord[j]){
                if(i == j){
                    BullCowCount.Bulls++;
                }
                else{
                    BullCowCount.Cows++;
                }
            }
                // increment bulls if they're in the same place
                // increment cows if not
        }
    }
    return BullCowCount;
}

int32 FBullCowGame::GetHiddenWordLength() const {
    return MyHiddenWord.length();
}
