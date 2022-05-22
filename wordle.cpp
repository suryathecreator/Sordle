/*
 * NIFTY CS1 PROJECT LINK: http://nifty.stanford.edu/2022/eroberts-spelling-bee-wordle/
 * I have modified the game with a personal twist; non-existant words are allowed.
 * I have made this a command line game opposed to a game on the web.
 * Compare my program to the actual WORDLE: https://www.nytimes.com/games/wordle/index.html
 * Included with my submission is the file "five-letter-words.txt" used within the program.
 * I will not be checking if the word exists as I don't have a dictionary of all 5-letter words.
   - Because of this limitation, if your word has multiple instances of the same character, 
    it will display a !Character! for all those characters 
    even though the WORDLE has less instances of that character.
 * Few examples to check versatility of program: 
   - Enter something else in the 1st (y/n) question.
   - Try to enter more than 5 letters (it will only take the first 5)
   - Try to enter capital letters.
   - Try to enter non-letters
   
   Hope you have fun playing SORDLE!
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

void game(char [], char [], const int, string);


int main()
{
    ifstream five_letter_words;
    int random, wordcount, repeat = 0;
    char answer;
    const int MAX_ATTEMPTS = 6;
    string word;
    vector<string> allwords;   
    do
    {
    five_letter_words.open("five-letter-words.txt", ios::in);
    for (int i = 1; five_letter_words.peek() != EOF; i++) 
    {
        getline(five_letter_words, word);
        allwords.push_back(word);
    }
    wordcount = allwords.size(); // Number of words in file

    srand(time(NULL));
    // cout << "# of words: " << wordcount << endl;
    random = rand() % wordcount;
    word = allwords[random];
    // cout << "THIS IS THE WORD: " << word << endl;
    five_letter_words.close();
    char wordle[word.length() + 1], attempt[word.length() + 1];
    strcpy(wordle, word.c_str()); 

    cout << "Hello, user! You are about to play SORDLE (Surya's Wordle). Want to hear the rules(y/n)? ";
    cin >> answer;
    answer = tolower(answer);

    cin.clear();
    fflush(stdin);

    while ( (answer != 'y') && (answer != 'n') )
    {
        cout << "You did not enter y or n. Please enter an option again. ";
        cin >> answer;
        answer = tolower(answer);

        cin.clear();
        fflush(stdin);
    }

    if (answer == 'y')
    {
        cout << "1) You have 6 attempts to guess one 5-letter word." << endl;
        cout << "2) !!Character!! means that the character is in the correct position." << endl;
        cout << "3) !Character! means that the character is in the word but in the wrong position. You may see multiple of these for the same character." << endl;
        cout << "4) Undisturbed characters are not in the word whatsoever." << endl;
        cout << "5) SORDLE will only take the first 5 characters in each guess." << endl;
    }

    cout << "Great! Let us commence." << endl;
    cout << endl;
    game(wordle, attempt, MAX_ATTEMPTS, word);
    
    cout << "Would you like to play again(0 = no, 1 = yes)? ";
    cin >> repeat;
    while ((repeat != 0) && (repeat != 1))
    {
        cout << "Invalid answer. Enter 0 for no, or 1 for yes." << endl;
        cout << "Would you like to play again(0 = no, 1 = yes)? ";
        cin >> repeat;
        cin.clear();
        fflush(stdin);
    }
    }
    while(repeat != 0);
    return 0;

}

void game(char wordle[], char attempt[], const int MAX_ATTEMPTS, string word)
{
    int letter1Found = 0, letter2Found = 0, letter3Found = 0, letter4Found = 0, letter5Found = 0, wordvalid;
    for (int i = 1; i <= MAX_ATTEMPTS; i++)
    {
        wordvalid = 0;
        while (wordvalid != 1)
        {
            wordvalid = 1;

            cout << "ATTEMPT " << i << ": " << "What is your guess? ";
            cin >> attempt[0] >> attempt[1] >> attempt[2] >> attempt[3] >> attempt[4];
            attempt[0] = tolower(attempt[0]);
            attempt[1] = tolower(attempt[1]);
            attempt[2] = tolower(attempt[2]);
            attempt[3] = tolower(attempt[3]);
            attempt[4] = tolower(attempt[4]);
            if (!isalpha(attempt[0]) ||  !isalpha(attempt[1]) || !isalpha(attempt[2]) || !isalpha(attempt[3]) || !isalpha(attempt[4])) 
            {
                cout << "Invalid attempt. Try again." << endl;

                wordvalid = 0;
            }
            cin.clear();
            fflush(stdin);

        }


        if (attempt[0] == wordle[0])
        {
            cout << "| !!" << attempt[0] << "!! |";
            letter1Found++;
        }
        else if ( (attempt[0] == wordle[1]) || (attempt[0] == wordle[2]) || (attempt[0] == wordle[3]) || (attempt[0] == wordle[4]) ) 
        {
            cout << "| !" << attempt[0] << "! |";
        }
        else
        {
            cout << "| " << attempt[0] << " |";
        }

        if (attempt[1] == wordle[1])
        {
            cout << " !!" << attempt[1] << "!! |";
            letter2Found++;
        }
        else if ( (attempt[1] == wordle[0]) || (attempt[1] == wordle[2]) || (attempt[1] == wordle[3]) || (attempt[1] == wordle[4]) ) 
        {
            cout << " !" << attempt[1] << "! |";
        }
        else
        {
            cout << " " << attempt[1] << " |";
        }

        if (attempt[2] == wordle[2])
        {
            cout << " !!" << attempt[2] << "!! |";
            letter3Found++;
        }
        else if ( (attempt[2] == wordle[0]) || (attempt[2] == wordle[1]) || (attempt[2] == wordle[3]) || (attempt[2] == wordle[4]) ) 
        {
            cout << " !" << attempt[2] << "! |";
        }
        else
        {
            cout << " " << attempt[2] << " |";
        }

        if (attempt[3] == wordle[3])
        {
            cout << " !!" << attempt[3] << "!! |";
            letter4Found++;
        }
        else if ( (attempt[3] == wordle[1]) || (attempt[3] == wordle[2]) || (attempt[3] == wordle[0]) || (attempt[3] == wordle[4]) ) 
        {
            cout << " !" << attempt[3] << "! |";
        }
        else
        {
            cout << " " << attempt[3] << " |";
        }

        if (attempt[4] == wordle[4])
        {
            cout << " !!" << attempt[4] << "!! |";
            letter5Found++;
        }
        else if ( (attempt[4] == wordle[1]) || (attempt[4] == wordle[2]) || (attempt[4] == wordle[3]) || (attempt[4] == wordle[0]) ) 
        {
            cout << " !" << attempt[4] << "! |";
        }
        else
        {
            cout << " " << attempt[4] << " |";
        }
        cout << endl;
        if ( (letter1Found > 0) && (letter2Found > 0) && (letter3Found > 0) && (letter4Found > 0) && (letter5Found > 0) )
        {
            cout << "You found the word in " << i << " attempt(s). Great job!" << endl;
            return;
        }

        letter1Found = 0;
        letter2Found = 0;
        letter3Found = 0;
        letter4Found = 0;
        letter5Found = 0;
    }
    cout << "You were unable to find the word. It was " << word << "." << endl;
    return;
}
