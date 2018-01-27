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

FBullCowGame::FBullCowGame()
{
    Reset();
}

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 5;
    MaxTries = MAX_TRIES;
    CurrentTry = 1;
    return;
}

bool FBullCowGame::CheckStringValidity(FString)
{
    return false;
}

BullCowCount FBullCowGame::SubmitGuess(FString)
{
    BullCowCount count;
    return count;
}




