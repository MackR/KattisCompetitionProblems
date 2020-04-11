//
//  main.cpp
//  GuessingGameKattis
//
//  Created by Mack Ragland on 4/10/20.
//  Copyright © 2020 KattisPracticeProblems. All rights reserved.

//  Link to original programming problem: https://open.kattis.com/problems/guessinggame



#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int guess;
    string response;
    bool cheating;
    bool fullstop = false;
    
    vector<int> numbers = {1,2,3,4,5,6,7,8,9,10};
    vector<int>::iterator ptr;
    
    while (fullstop == false) {
        numbers = {1,2,3,4,5,6,7,8,9,10};
        cheating = true;
        
        while (1) {
            cin >> guess;
            if (guess == 0) {
                fullstop = true;
                break;
            }
            string firstWord;
            string secondWord;
            cin >> firstWord;
            cin >> secondWord;
            response = firstWord + " " + secondWord; // std::getline would be cleaner but this is easier for moment
            ptr = numbers.begin();
            
            if (response == "too high") {
                advance(ptr, guess-1); // point to the element with same number as guess as starting point for iterator
                for (ptr; ptr != numbers.end(); ptr++) {
                    *ptr = 11; // make that element 11 (an out of range number)
                }
                numbers.erase(ptr, numbers.end());
                
            }
            else if(response == "too low"){
                advance(ptr, guess); // point to the element one after the guess number element as the stopping point for iterator
                for (auto it = numbers.begin(); it != ptr; it++) {
                    *it = 11;
                }
                
            }
            else if(response == "right on"){
                
                advance(ptr, guess-1);  // point to the element that would have the same number as guess to check if it's invalid guess
                if (*ptr == guess) {
                    
                    cout << "Stan may be honest" << endl;
                }
                else{
                    cout << "Stan is dishonest" << endl;
                }
                break;
            }
            
            
        }
        
    }
    
    
    
    return 0;
}

