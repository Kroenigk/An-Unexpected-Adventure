/**
 *        @file: the_Hobbit.cc
 *      @author: Kylie Roenigk
 *        @date: May 19, 2024
 *       @brief: A single player game that follows the events of the Hobbit as the Hero Travels with the Company through Middle Earth
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

///function prototypes
class Hero
{
    string race;
    vector <string> skills;
    int level;
    int exp;
    int health;
    vector <string> inventory;
};
class Adventure
{
    string title;
    string description;
    int exp_reward;
    int damage;
    vector <string> consequences;


};

int main(int argc, char const *argv[]) {

///Reading in Quest Values
    ifstream in;
    in.open("quests.txt");

    if (in.fail())
    {
        cout << "File Failed to Open" << endl;
        exit(0);
    }

    string temp;
    char ch;
    ch = in.get();
    while(!in.eof())
    {
        if (ch == '|')
        {
            cout << temp << endl;
            temp = "";
        }
        else
        {
            temp += ch;
        }

        ch = in.get();
    
    }


    in.close();
   /*add code*/
   return 0;
}// main