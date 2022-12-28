#include <iostream>
#include <string>
#include "bleep.hpp"
using namespace std;

int main(int argc, char * argv[]) {

    string word = "broccoli";
    string text = "I said I don't want any damn broccoli!";
    
    bleep(word, text);

    cout << text;
    
}