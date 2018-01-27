//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Aly Stroud on 23/01/2018.
//  Copyright © 2018 Aly Stroud. All rights reserved.
//

#include "FBullCowGame.hpp"

bool FBullCowGame::IsGameWon() const { return false; }

int32 FBullCowGame::GetMaxTries() const { return MaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return (int32) HiddenWord.length(); }

FBullCowGame::FBullCowGame()
{
    Reset();
}

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 5;
    MaxTries = MAX_TRIES;
    CurrentTry = 1;
    
    const FString HIDDEN_WORD = "plane";
    HiddenWord = HIDDEN_WORD;
    return;
}

bool FBullCowGame::CheckStringValidity(FString) const
{
    return false;
}

//Receives valid guess, increments current try
//Returns count
BullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    CurrentTry++;
    BullCowCount Count;
    for(int32 i = 0; i < HiddenWord.length(); i++)
    {
        for(int32 j = 0; j < Guess.length(); j++)
        {
            if(HiddenWord[i] == Guess[j])
            {
                if(i == j)
                {
                    Count.Bulls++;
                }
                else{
                    Count.Cows++;
                }
            }
        }
    }
    return Count;
}




