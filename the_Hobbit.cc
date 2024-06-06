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
    private:
    string title;
    string description;
    int exp_reward;
    int p_damage;

    public:
    void set_title(string new_title);
    string get_title();
    void set_description(string new_description);
    string get_description();
    void set_exp_reward(int new_exp_reward);
    int get_exp_reward();
    void set_p_damage(int new_p_damage);
    int get_p_damage();
};

///Function declarations
 vector<Adventure> loadQuests();

int main(int argc, char const *argv[])
 {

    vector <Adventure> quests = loadQuests();
   // for(int i = 0; i < quests.size(); ++i)
    //{
    //   cout << quests.at(i).title;
    //    cout << quests.at(i).p_damage;
   // }


   return 0;
 }
 vector<Adventure> loadQuests()
 {
    vector<Adventure> quests;
    ///Reading in Quest Values
    ifstream in;
    in.open("quests.txt");

    if (in.fail())
    {
        cout << "File Failed to Open" << endl;
        exit(0);
    }

    string temp;
    string data;
    vector<string> holder;

    getline(in, data);
    cout << data << endl;
    
    while(!in.eof())
    {
        for(int i = 0; i < data.size(); ++i)
        {
           if (data.at(i) == '|' || i == (data.size()- 1))
        {
            ///exception for the end of the string
            if(i == (data.size() - 1))
            {
                temp += data.at(i);
            }

            holder.push_back(temp);
            temp = "";
        }
            else
        {
            temp += data.at(i);
        }
        }
        getline(in, data);
    }

    for(int i = 0; i < holder.size(); i += 4)
    {
        cout << holder.at(i) << endl;
        cout << holder.at(i + 1) << endl;
        cout << holder.at(i + 2) << endl;
        cout << holder.at(i + 3) << endl;
    }
    in.close();
    return quests;
 }