#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

void bleep(string censorContent, string &textToCensor) {

    //gettings length of inputs
    const int ccLength = censorContent.size();      //Working as intended
    const int textLength = textToCensor.size();     //Working as intended

    //establishing arrays for inputs to be looped through
    vector<char> ccArr(censorContent.begin(), censorContent.end());     //String to vector (working as intended)      
    vector<char> tlArr(textToCensor.begin(), textToCensor.end());       //String to vector (working as intended)

    int matchCount = 0;
    int matchesArrStart = 0;
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
        if (matchCount == ccLength - 1) {

            for (int l = matchesArrStart - 1; l < (matchesArrStart + ccLength) -1; l++) {
                tlArr[l] = '*';
            }
            //Resetting counts and loop
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

        if (i > textLength) {
            break;
        }

       }
        
    }

    //return array to string and write 
    string temp;
    for (int h = 0; h < textLength; h++) {      //This works as intended
        temp.push_back(tlArr[h]);            //This works as intended
    }

    textToCensor = temp;
    cout << textToCensor << endl;
 
}