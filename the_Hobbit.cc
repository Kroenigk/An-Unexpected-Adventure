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
    Adventure(string data);
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

    vector <Adventure> allQuests = loadQuests();

    for(int i = 0; i < allQuests.size(); ++i)
    {
        cout << allQuests.at(i).get_title() << endl;
        cout << allQuests.at(i).get_p_damage() << endl;

    }



   return 0;
 }

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
 Adventure::Adventure(string data)
 {
    string temp;
    vector<string> holder;

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
        ///initializing object values
        title = holder.at(0);
        description = holder.at(1);
        exp_reward = stoi(holder.at(2));
        p_damage = stoi(holder.at(3));
    }
void Adventure::set_title(string new_title)
{
    if(!new_title.empty())
    {
        title = new_title;
    }
}

string Adventure::get_title()
{
    return title;
}

void Adventure::set_description(string new_description)
{
    if(!new_description.empty())
    {
        description = new_description;
    }
}

string Adventure::get_description()
{
    return description;
}

void Adventure::set_exp_reward(int new_exp_reward)
{
    if (new_exp_reward >= 0)
    {
        exp_reward = new_exp_reward;
    }
}

int Adventure::get_exp_reward()
{
    return exp_reward;
}

void Adventure::set_p_damage(int new_p_damage)
{
    if(new_p_damage >= 0)
    {
        p_damage = new_p_damage;
    }
}
int Adventure::get_p_damage()
{
    return p_damage;
}