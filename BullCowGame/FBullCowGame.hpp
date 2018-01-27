//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Aly Stroud on 23/01/2018.
//  Copyright © 2018 Aly Stroud. All rights reserved.
//
#pragma once
#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <iostream>
#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

class FBullCowGame
{
public:
    FBullCowGame(); //Constructor 
    void Reset(); //TODO make a more rich return value
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;
    bool CheckStringValidity(FString);
    BullCowCount SubmitGuess(FString);
    
private:
    int32 CurrentTry;
    int32 MaxTries;
    bool IsIsogram(FString);
};
#endif /* FBullCowGame_hpp */
