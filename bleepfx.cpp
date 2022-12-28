#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

void bleep(string censorContent, string &textToCensor) {

    //gettings length of inputs
    const int ccLength = censorContent.size();
    const int textLength = textToCensor.size();

    cout << ccLength << endl;
    cout << textLength << endl;

    //establishing arrays for inputs to be looped through
    char ccArr[ccLength];       //censorContentArray
    char tlArr[textLength];     //text(toCensor)lengthArray

    //copying string into array
    strcpy(ccArr, censorContent.c_str());
    strcpy(tlArr, textToCensor.c_str());

    for (int u; u < sizeof(ccArr)/sizeof(char); u++) {
        cout << ccArr[u];
    } cout << "\n";

    for (int q; q < sizeof(ccArr)/sizeof(char); q++) {
        cout << tlArr[q];
    } cout << "\n";
    //looping through
    /*My idea is to loop through both strings comparing characters.
      If a character matches, matchCount increases by 1, loop continues
      If it fails before matchCount = ccLength - 1, break and start again
      If it completes, loop through again and censor all designated contents
        Can possibly do this by starting with the number in an int
      */
    int matchCount = 0;
    int matchesArrStart;
    //int matchesArrStop; //just use ccLength

    int i = 0;

    while (i < textLength) {
        
    
       for (int k = 0; k < ccLength; k++) {
        //cout << k << endl;
        //cout << i << endl;
        if (ccArr[k] == tlArr[i]) {
            //match found? Increment matchCount!
            matchCount++;
            //cout << matchCount << endl;

            //here we want to check if matchesArrStart has been initialized
            //We can do this by checking if matchCount above has been incremented!
            //Hereby, we assert that the beginning of censored text is i in string
            //tlArr
            if (matchCount == 1 && matchesArrStart < i) {
                matchesArrStart = i;
            }

        }
        
        //Activates only when time to rewrite array
        if (matchCount == ccLength - 1) {
            cout << "Replacement loop should start here" << endl;
            cout << matchesArrStart << endl;
            for (int l = matchesArrStart; l < ccLength; l++) {
                cout << "Match found, replacing!";
                tlArr[l] = '*';
            }
            //Resetting counts and loop
            cout << "k should be reset here" << endl;
            k = 0;
            matchCount = 0;

        //Resets both the loop and match count
        }
        
        if (ccArr[k] != tlArr[i]) {
            matchCount = 0;
            k = 0;
        }

        //increments i regardless but only after all execution is done.
        i++;
       }
        
    }

    //return array to string and write 
    string temp;
    for (int h = 0; h < textLength; h++) {
        cout << "Rewriting character " << h << endl;
        temp.push_back(tlArr[h]);
    }

    cout << "Currently, temp reads: " << temp << endl;

    textToCensor = temp;

}