/**
 *        @file: the_Hobbit_main.cc
 *      @author: Kylie Roenigk
 *        @date: June 06, 2024
 *       @brief: This is the main program for the Hobbit choose your own adventure.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include "the_Hobbit.h"

using namespace std;

///function prototypes
vector<Adventure> loadQuests();

int main(int argc, char const *argv[])
 {
    Hero character;
    string answer;

    vector <Adventure> allQuests = loadQuests();

    ///The Quest Begins
    cout << "Would you like to Customize your hero?" << endl;
    cout << "Please Select one: Yes or No: ";
    cin >> answer;
    if (answer == "yes" || answer == "Yes")
    {
       character.customize_hero();
    }
    else
    {
        cout << character.get_race() << endl;
    }

   return 0;
 }
 /// @brief Loads all quests for the story
 /// @return 
 vector<Adventure> loadQuests()
 {
    vector<Adventure> allQuests;
    string data;
    ifstream in;
    in.open("quests.txt");

    ///checks for failure
    if (in.fail())
    {
        cout << "File Failed to Open" << endl;
        exit(0);
    }
    ///just getting the first line
    getline(in, data);
    ///deals with empty lines
    while(data.empty())
    {
        getline(in, data);
    }

    while(!in.eof())
    {
        Adventure a(data);
        allQuests.push_back(a);
        getline(in, data);
     }
     ///makes sure the last quest is included
     if(in.eof() && !data.empty())
     {
        Adventure a(data);
        allQuests.push_back(a);
     }
    in.close();
    return allQuests;
 }