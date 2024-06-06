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
#include <cctype>
#include <fstream>
#include "the_Hobbit.h"

using namespace std;


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

///Hero Class Functions
Hero::Hero()
{
    ///initialises starting values
    race = "Hobbit";
    level = 1;
    exp = 0;
    health = 100;
    vector<string> skills = {"Whit and Wisdom"};
    vector<string> inventory = {"Handkerchief"};



}
///setters and getters
    void Hero::set_race(string new_race)
    {
        if(!new_race.empty())
        {
            race = new_race;
        }
    }
    string Hero::get_race()
    {
        return race;
    }
    void Hero::set_skills(vector<string> new_skills)
    {
        if(!new_skills.empty())
        {
            skills = new_skills;
        }
    }
    vector<string> Hero::get_skills()
    {
        return skills;
    }
    void Hero::set_level(int new_level)
    {
        if(new_level > 0)
        {
            level = new_level;
        }
    }
    int Hero::get_level()
    {
        return level;
    }
    void Hero::set_exp(int new_exp)
    {
        if(new_exp >= 0)
        {
            exp = new_exp;
        }
    }
    int Hero::get_exp()
    {
        return exp;
    }
    void Hero::set_health(int new_health)
    {
        if(new_health > 0)
        {
            health = new_health;
        }
    }
    int Hero::get_health()
    {
        return health;
    }
    void Hero::set_inventory(vector<string> new_inventory)
    {
        if(!new_inventory.empty())
        {
            inventory = new_inventory;
        }
    }
    vector<string> Hero::get_inventory()
    {
        return inventory;
    }

    ///Helper Functions
    void Hero::add_to_inventory(string new_item)
    {
        if(!new_item.empty())
        {
            inventory.push_back(new_item);
        }
    }
    void Hero::level_Up()
    {
        ++level;
    }
    void Hero::learn_skill(string new_skill)
    {
        if(!new_skill.empty())
        {
            skills.push_back(new_skill);
        }
    }
    string make_lower(string word)
    {
    string lowerCase = "";
    char conversion;

    for(int i = 0; i < word.length(); ++i)
    {
        ///takes one character at a time and makes it lowercase
        conversion = tolower(word.at(i));
        lowerCase = lowerCase + conversion;
    }
    return lowerCase;
}

    ///Customizing Hero
    void Hero::customize_hero()
    {
     ///customization of character
    string choice;
    cout << "You have started your journey. Please build your hero..." << endl;
    cout << setw(40) << setfill('-') << " ";
    cout << endl;

    race_menu();
    cout << "What is your race? ";
    cin >> choice;
    choice = make_lower(choice);
    if(choice == "human" || choice == "hobbit" || choice == "dwarf" || choice == "elf")
    {
        race = choice;
    }
    cout << setw(40) << setfill('-') << " ";
    cout << endl;

    //skills
    string skill1;
    string skill2;
    cout << "Choose two skills" << endl;
    cout << setw(40) << setfill('-') << " ";
    cout << endl;
    skill_menu();
    cout << "Select your skill: ";
    cin >> skill1;
    skills.push_back(skill1);
    cout << "Select your other skill: ";
    cin >> skill2;
    skills.push_back(skill2);
    cout << setw(40) << setfill('-') << " ";
    cout << endl;

    ///items
    string item;
    cout << "What item do you carry?" << endl;
    cout << setw(40) << setfill('-') << " ";
    cout << endl;
    item_menu();
    cout << "Select and item: ";
    cin >> item;
    inventory.push_back(item);
    cout << setw(40) << setfill('-') << " ";
    cout << endl; 


    }
    ///Menus
    void Hero::race_menu()
    {
        cout << "Human" << endl;
        cout << "Hobbit" << endl;
        cout << "Dwarf" << endl;
        cout << "Elf" << endl;
    }
    void Hero::skill_menu()
    {
        cout << "Healing" << endl;
        cout << "Fighting" << endl;
        cout << "Tracking" << endl;
        cout << "Scouting" << endl;
        cout << "Baking and Cooking" << endl;
        cout << "Sewing" << endl;
    }
    void Hero::item_menu()
    {
        cout << "Axe" << endl;
        cout << "Sword" << endl;
        cout << "Bow and Arrows" << endl;
        cout << "Daggers" << endl;
        cout << "Medical Kit" << endl;
        cout << "Sewing kit" << endl;
    }
    void Hero::hero_stats()
    {
        cout << "Race: " << race << endl;
        cout << "Level: " << level << endl;
        cout << "Exp: " << exp << endl;
        cout << "Skills: ";
        for (int i = 0; i < skills.size(); ++i)
        {
            cout << skills.at(i);
            if(!(i = skills.size() - 1))
            {
                cout << ", ";
            }
        }
        cout << setfill('-') << setw(20) << endl; 
        cout << "Inventory: ";
        for (int i = 0; i < inventory.size(); ++i)
        {
            cout << inventory.at(i);
            if(!(i = inventory.size() - 1))
            {
                cout << ", ";
            }
        }
        cout << setfill('-') << setw(20) << endl; 

    }