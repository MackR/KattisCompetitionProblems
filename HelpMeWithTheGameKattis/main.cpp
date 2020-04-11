//
//  main.cpp
//  HelpMeWithTheGameKattis
//
//  Created by Mack Ragland on 9/9/19.
//  Copyright © 2019 KattisPracticeProblems. All rights reserved.
//
// absolute column and row sizes 33,17
// Original Problem viewable at: https://open.kattis.com/problems/helpme


#include <iostream>
#include <vector>
using namespace std;

vector <vector <string>> white(6,vector<string>(0)),black(6,vector<string>(0)); // goes K, Q, R, B, N, P
vector <string> column{"a","b","c","d","e","f","g","h"};
auto itcolumn = column.begin();
vector <string> row{"1","2","3","4","5","6","7","8"};
auto itrow = row.rbegin();
string a[17];
int rowCount;
int whiteCount, blackCount;
string charStore;

int main(int argc, const char * argv[]) {
    for (int i = 0;  i <= 16; i++) {  // copies the board layout into a 17 x 33 array, all characters
        getline(cin, a[i]);
    }
 
    
    for (int rowCount = 0; rowCount < 17; rowCount++){ // for loop to go through each row and search
        for (int j = 0; j<34; j++) { // goes through the 34 characters in each row
            
            if (a[rowCount][j] == ':' || a[rowCount][j] == '.'){ // if we have reached a valid column beginning character ":" or "."
                if (itcolumn == column.end()) {
                    itrow++;
                    itcolumn = column.begin();
                }
                
                if (a[rowCount][j+1] == 'k') { // if its next character is a k, add a king to the vector of positions
                    black[0].push_back("K"+*itcolumn+*itrow);
                    itcolumn++;
                    blackCount++;
                    
                    
                }
                else if (a[rowCount][j+1]=='q'){
                    black[1].push_back("Q"+*itcolumn+*itrow);
                    itcolumn++;
                    blackCount++;
                    
                }
                else if(a[rowCount][j+1] == 'r'){
                    black[2].push_back("R"+*itcolumn+*itrow);
                    itcolumn++;
                    blackCount++;
                    
                }
                else if (a[rowCount][j+1] == 'b'){
                    black[3].push_back("B"+*itcolumn+*itrow);
                    itcolumn++;
                    blackCount++;
                    
                }
                else if (a[rowCount][j+1] == 'n'){
                    black[4].push_back("N"+*itcolumn+*itrow);
                    itcolumn++;
                    blackCount++;
                    
                }
                else if (a[rowCount][j+1] == 'p'){
                    black[5].push_back(*itcolumn+*itrow);
                    itcolumn++;
                    blackCount++;
                    
                }
                else if(a[rowCount][j] == a[rowCount][j+2]&& itcolumn != column.end()){
                    j+= 3;
                    itcolumn++;
                    
                }
            }
        }
    }
    auto itcolumn = column.begin();
    auto itrow = row.begin();
    
        for (int rowCount = 17; rowCount >= 0; rowCount--){
            for (int j = 0; j<=34; j++) {
                
                if (a[rowCount][j] == ':' || a[rowCount][j] == '.'){
        
                if (a[rowCount][j+1] == 'K') {
                    white[0].push_back("K"+*itcolumn+*itrow);
                    itcolumn++;
                    whiteCount++;
                    
                }
                else if (a[rowCount][j+1]=='Q'){
                    white[1].push_back("Q"+*itcolumn+*itrow);
                    itcolumn++;
                    whiteCount++;
                    
                }
                else if(a[rowCount][j+1] == 'R'){
                    white[2].push_back("R"+*itcolumn+*itrow);
                    itcolumn++;
                    whiteCount++;
                    
                }
                else if (a[rowCount][j+1] == 'B'){
                    white[3].push_back("B"+*itcolumn+*itrow);
                    itcolumn++;
                    whiteCount++;
                    
                }
                else if (a[rowCount][j+1] == 'N'){
                    white[4].push_back("N"+*itcolumn+*itrow);
                    itcolumn++;
                    whiteCount++;
                    
                }
                else if (a[rowCount][j+1] == 'P'){
                    white[5].push_back(*itcolumn+*itrow);
                    itcolumn++;
                    whiteCount++;
                    
                }
                else if(a[rowCount][j] == a[rowCount][j+2]){
                    j+= 2;
                    itcolumn++;
                    
                }
            
    }
        if (itcolumn == column.end()) {
            itrow++;
            itcolumn = column.begin();
        }
        
        
        }
    }
    cout << "White: ";
    for (auto itwhitePiece = white.begin(); itwhitePiece != white.end(); itwhitePiece++) {
        for (auto itwhitePieceNum = itwhitePiece -> begin(); itwhitePieceNum != itwhitePiece->end(); itwhitePieceNum++) {
            cout << *itwhitePieceNum;
            if (whiteCount > 1) {
                cout  << ",";
                whiteCount--;
            }


        }
    }
    cout << endl;
    cout << "Black: ";
    for (auto itblackPiece = black.begin(); itblackPiece != black.end(); itblackPiece++) {
        for (auto itblackPieceNum = itblackPiece -> begin(); itblackPieceNum != itblackPiece->end(); itblackPieceNum++) {
            cout << *itblackPieceNum;
            if (blackCount > 1) {
                cout  << ",";
                blackCount--;
            }

        }
    }

    return 0;
}
