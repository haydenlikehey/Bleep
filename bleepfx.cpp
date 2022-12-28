#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

void bleep(string censorContent, string &textToCensor) {

    //gettings length of inputs
    int ccLength = censorContent.size();
    int textLength = textToCensor.size();

    //establishing arrays for inputs to be looped through
    char ccArr[ccLength];       //censorContentArray
    char tlArr[textLength];     //text(toCensor)lengthArray

    //copying string into array
    strcpy(ccArr, censorContent.c_str());
    strcpy(tlArr, textToCensor.c_str());

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

        if (ccArr[k] == tlArr[i]) {
            //match found? Increment matchCount!
            matchCount++;

            //here we want to check if matchesArrStart has been initialized
            //We can do this by checking if matchCount above has been incremented!
            //Hereby, we assert that the beginning of censored text is i in string
            //tlArr
            if (matchCount == 1) {
                matchesArrStart = i;
            }

        }
        
        //Activates only when time to rewrite array
        if (matchCount == ccLength) {
            for (int l = matchesArrStart; l < ccLength; l++) {
                tlArr[l] = ccArr[(matchesArrStart - 1) + l];
            }
            k = 0;

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
        temp.push_back(tlArr[h]);
    }

    textToCensor = temp;

}