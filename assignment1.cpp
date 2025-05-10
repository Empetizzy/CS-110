/*
Program name: wordgame.cpp
Author: Devon Blewett
Purpose: This program prompts the user for an amount of consonants and vowels, generates them randomly, scrambles them, and presents the resulting string to the user

Written for the Open Textbooks program
*/
#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;
// generates a random consonant
char generateConsonant(char cons[]);
// generates a random vowel
char generateVowel(char vowels[]);
// scrambles the given string
void scramble(string& l);

int main() {
    // seed for random numbers
    srand(time(NULL));
    // output string
    string letters = "";
    // character array of all the consonants
    char consonants[] = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v', 'w' ,'x','y','z' };
    // character array of all the vowels
    char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
    // the amount of letters to generate
    int amount;
    cout << "Enter how many consonants to generate" << endl;
    cin >> amount;
    // for the amount of letters asked for
    for (int i = 0; i < amount; i++) {
        // generate a letter and add it to the letters string
        letters = letters + generateConsonant(consonants);
    }
    // repeat for vowels
    cout << "Enter how many vowels to generate" << endl;
    cin >> amount;

    for (int i = 0; i < amount; i++) {
        letters = letters + generateVowel(vowels);
    }
    // scramble the letters string
    scramble(letters);
    // output the result
    cout << letters;
}

/*
function name: generateConsonant
parameters: 1: Character array of consonants
purpose: Generates and returns a random consonant
*/
char generateConsonant(char cons[]) {
    // generate a random number between 0 and 20
    int c = rand() % 21;
    // return the character at that position in the array
    return cons[c];
}
/*
function name: generateVowel
parameters: 1: Character array of vowels
purpose: Generates and returns a random vowel
*/
char generateVowel(char vowels[]) {
    // generate a random number between 0 and 4
    int v = rand() % 5;
    // return the character at that position in the array
    return vowels[v];
}
/*
function name: scramble
parameters: 1: reference to string of letters
purpose: scrambles the positions of the letters in the given string
*/
void scramble(string& l) {
    // get the size of the string
    int size = l.size();
    // for some amount of times
    for (int i = 0; i < 20; i++) {
        // generate two positions to swap
        int pos1 = rand() % size;
        int pos2 = rand() % size;
        // set a temporary variable to the first char
        char temp = l[pos1];
        // set the char at the position of the first char to the 2nd
        l[pos1] = l[pos2];
        // set the char at the position of the second char to the 1st
        l[pos2] = temp;
    }
}