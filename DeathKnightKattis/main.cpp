//
//  main.cpp
//  DeathKnightKattis
//
//  Created by Mack Ragland on 4/10/20.
//  Copyright © 2020 KattisPracticeProblems. All rights reserved.


#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    
    int counter;
    int lossCounter = 0;
    string textInput = "";
    int inputLength;
    
    cin >> counter;
    
    
    for (int i = 0; i < counter; ++i){
        cin >> textInput;
        inputLength = textInput.length();
        char prevAttack = 'L';
        for (int j = 0; j < inputLength; ++j) {
            if (textInput[j] == 'D') {
                if (prevAttack == 'C') {
                    ++lossCounter;
                    break;
                }
                
            }
            prevAttack = textInput[j];
        }
        
    }
    
    cout << (counter-lossCounter);
    
    
}
