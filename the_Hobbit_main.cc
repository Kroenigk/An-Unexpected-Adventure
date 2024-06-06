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

    vector <Adventure> allQuests = loadQuests();

    for(int i = 0; i < allQuests.size(); ++i)
    {
        cout << allQuests.at(i).get_title() << endl;
        cout << allQuests.at(i).get_description() << endl;

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