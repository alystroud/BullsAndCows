//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Aly Stroud on 23/01/2018.
//  Copyright © 2018 Aly Stroud. All rights reserved.
//

#include "FBullCowGame.hpp"



void FBullCowGame::Reset() { 
    return;
}

bool FBullCowGame::CheckStringValidity(std::string) { 
    return false;
}


bool FBullCowGame::IsGameWon() const { return false; }

int FBullCowGame::GetMaxTries() const { return MaxTries; }

int FBullCowGame::GetCurrentTry() const { return CurrentTry; }


