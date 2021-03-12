/*****************************************************************************
*
*    Author:           Dymon Browne
*    Email:            dymon.browne@hotmail.com
*    Label:            P02
*    Title:            Processing in Linear Time
*    Course:           CMPS 3013
*    Semester:         Spring 2021
*    Description:
*         This program uses link list to which loads words from a
*       file and time the definition. It will search the list after
*       entering a string to find the word. This program also uses
*       getching to get input from the keyboard for the search.
*      
*    Files:
*         main.cpp
*         Timer.hpp
*         mygetch.hpp
*         termcolor.hpp
*         Animals.txt
*         dictionary.txt
*
*    Usage:
*           main.cpp         : driver program
*           animals.txt     : Input file
*           dictionary.txt
*
*           output will be display on the console in color.
*
******************************************************************************/

#include <iostream>
#include <time.h>
#include <chrono>
#include "timer.hpp"
#include "getch.hpp"
#include <string>
#include <vector>
#include <fstream>
#include "termcolor.hpp"

using namespace std;


/*                                                                    
* wordNode                                                                                                                   
* Description:                                                        
*        Node structure for  linked list                           
* Private Methods:                                                    
*        None                                                  
* Public Methods:                                                     
*        wordNode                             
*/
struct wordNode
{
    wordNode *Next;
    string word;

    wordNode()
    {
        Next = NULL;
        word = "";
    }
};


/**
*                                                                     
* Linklist                                                         
* Description:   
*                                                     
*        Node structure for linked list 
*                      
* Private Methods:                                                    
*        None                                       
* Public Methods:                                                     
*        LINKEDLIST                                                   
*        getSize                                                      
*        insert                                                   
*        print                                                        
*        vector<string>
*/
class Linklist
{
    protected:
        wordNode* head;
        wordNode* tail;
        int size;
        int word;
        int total;           
        int index;            
        bool Found;           


    public:
        Linklist();
        int getSize();
        int getWord();
        void Insert(wordNode *word);
        void print();
        vector<string> Find(string typed);
};

/*
*                                                         
* Linklist                                                      
* Description:                                           
*        Default Constructor                                  
*                                                         
* Method Variables:                                       
*        head                                               
*        tail                                             
*        size                                              
*                                                        
* Use:                                                       
*   Create a linked list within the class                     
*/

Linklist::Linklist()
  {
    head = NULL;
    tail = NULL;
    size = 0;
   }

/**
*                                                             
* getSize                                                     
*                                                             
* Description:                                                
*        Gets size of the linked list                     
*                                                            
* Method Variables:                                           
*        None                                                
*                                                           
* Return:                                                     
*   size                                                      
*                                                            
**/
    int Linklist::getSize()
      {
         return size;
      }
/**
*                                                             
* getWord                                                     
*                                                             
* Description:                                                
*        Gets word of the linked list                     
*                                                            
* Method Variables:                                           
*        None                                                
*                                                           
* Return:                                                     
*   word                                                      
*                                                            
**/

    int Linklist::getWord(){
      return word;
    }        
/**
* insert                                                           
*                                                                  
* Description:                                                     
*        Adds word to the linked list                            
*                            
* Method Variables:                                                
*        None                                                      
*                                                                  
* Return:                                                     
*   void                                                     
*                                                          
**/

void Linklist::Insert(wordNode* word)
{
  if (!head)
  {
    head = tail = word;
  }
  else
  {
    tail->Next = word;
    tail = word;
  }

   size++;
}

/**
* print                                                            
*                                                                 
* Description:                                                    
*        Prints the linked list                                   
*                                                                 
* Method Variables:                                               
*        None                                                     
*                                                                  
* Return:                                                          
*   void                                                          
*                                                                  
**/

void Linklist::print()
{
    wordNode *Current = head;

    while (Current)                        
    {
        cout << Current->word;              
        cout << endl;
        Current = Current->Next;            
    }
    
}

/**
 * Description:
 *      Originally wrote this to count size of input file so
 *      I could allocate enough memory for an array of strings
 *      but I went with a vector below. But I'm keeping it and
 *      using it anyway!
 * Params:
 *      string file_name - file to get the line count
 * 
 * Returns:
 *      int - line count
 */
// int CountLines(string file_name) {
//     ifstream inFile(file_name);
//     return count(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>(), '\n');
// }

/**
 * Description:
 *      Loads a file of strings (words, names, whatever) reading them in
 *      with one word per line. So words must be delimited by newlines '\n'
 * Params:
 *      string file_name - file to get the line count
 * 
 * Returns:
 *      int - line count
 */
vector<string> LoadDicword(string file_name) {
    ifstream fin;                            // file to dictwords
    int count = 224; // get size of input file
    vector<string> array(count);             // allocate vector of correct size

    fin.open("dictionary.txt"); // open file for reading

    // knowing the size of the file lets us treat
    // it like an array without using .push_back(value)
    for (int i = 0; i < count; i++) {
        fin >> array[i];           // read in dicword
        for (auto &c : array[i]) { // c++ 11 style loop
            c = tolower(c);        // lowercase the dicwords
        }
    }
    return array;
}

/**
 * Description:
 *      Finds partial matches in an array of strings and returns them. It
 *      doesn't matter where in the string the match is.
 * Params:
 *      vector<string>  array       - array to search
 *      string          substring   - substring to search for in each word
 * 
 * Returns:
 *      vector<string> - holding all the matches to substring
 */
vector<string> Linklist::Find(string letter) {

    vector<string> matches; // to hold any matches
    Found = false;                //No matches have been found
    total = 0;                    //There are no similar words yet
    

    wordNode *Current = head;

    while (Current != NULL && !Found)
    {
        string found = "";

        found = Current->word;           

        int len = letter.length();           

        if (found.substr(0, len) == letter)  
        {                                   
          matches.push_back(found);
        }

        Current = Current->Next;            
    }

    return matches;
}

int main() 
{

  Linklist L1;

  char k;                 // holder for character being typed
  string word = "";       // var to concatenate letters to
  vector<string> Dicword; // array of Dicword
  vector<string> matches; // any matches found in vector of Dicword     

  ofstream fout("temp.txt");

  Timer T;   // create a timer
  T.Start(); // start it

  ifstream in;           
  ofstream out;          
  in.open("dictionary.txt");

  while(!in.eof())
  {
    // Add words to the vector wordList
    string temp;
    in >> temp;

    matches.push_back(temp);

  }


  T.End(); // end the current timer

  // print out how long it took to load the dicword file
  cout << termcolor::blue << T.Seconds() << " seconds to read in and print json" << endl;

  cout << T.MilliSeconds() << " milli to read in and print json" << endl;

  cout << "Type keys and watch what happens. Type capital Z to quit." << endl;

  T.Start();

  // Loop through the vector.
  for (int j = 0; j < matches.size(); j++)
  {                                       
    wordNode *Temp = new wordNode;      

    string item = matches[j];

    Temp->word = item;

    L1.Insert(Temp);
  }

  T.End();

  cout << termcolor::blue << T.Seconds() << " seconds to read in the data" << endl;
  cout << T.MilliSeconds() << " milliseconds to read in the data"   << endl;

  // While capital Z is not typed keep looping
  while ((k = getch()) != 'Z') 
  {
        
    // Tests for a backspace and if pressed deletes
    // last letter from "word".

    if ((int)k == 127) 
    {
      if (word.size() > 0) 
        {
          word = word.substr(0, word.size() - 1);
        }
    }
    else 
    {
      // Make sure a letter was pressed and only letter
      if (!isalpha(k)) 
          {
            cout << "Letters only!" << endl;
                continue;
          }

          // We know its a letter, lets make sure its lowercase.
          // Any letter with ascii value < 97 is capital so we
          // lower it.
          if ((int)k < 97) 
            {
              k += 32;
            }
           word += k; // append char to word
        
    }
    
  
  
  string Tmatches[10];                // Initializing 10 words to print.
  int Searchmatches;   
        
  // Find any dicword in the array that partially match
  // our substr word
  T.Start(); // start it
  matches = L1.Find(word);
  T.End(); // end the current timer
  cout << T.Seconds() << " seconds to read in and print json" << endl;
  cout << T.MilliSeconds() << " milli to read in and print json" << termcolor::reset << endl;

  if ((int)k != 32) 
  { // if k is not a space print it
    //cout << "Keypressed: " << termcolor::yellow << termcolor::blue << k << " = " << (int)k << termcolor::reset << endl;
    cout << "Current Substr: " << termcolor::red << word << termcolor::reset << endl;
                 
    cout << "Words Found: "<< termcolor::red << Searchmatches 
    << endl << termcolor::reset;
    cout << termcolor::green;
    Searchmatches = matches.size();        

    if (matches.size() >= 10)       
      {
        for (int i = 0; i < 10; i++)
          {
            Tmatches[i] = matches[i];
              cout << Tmatches[i] << " ";
          }
      }      
    else
      {
        for (int j = 0; j < matches.size(); j++)
          {
            Tmatches[j] = matches[j];
            cout << Tmatches[j] << " ";
          }
      }
             
      cout << termcolor::reset << endl << endl;
    }
    
  }
    return 0;
}
