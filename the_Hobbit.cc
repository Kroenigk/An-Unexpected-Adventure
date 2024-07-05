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
    skills.push_back("Whit");
    inventory.push_back("Handkercheif"); 



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

    ///Menu Selection and data validation
    do
    {
        race_menu();
        cout << "What is your race? ";
        cin >> choice;
        choice = make_lower(choice);
        if(choice == "human" || choice == "hobbit" || choice == "dwarf" || choice == "elf")
        {
            race = choice;
        }
    } while (choice != "human" && choice != "hobbit" && choice != "dwarf" && choice != "elf");
    
    ///formatting
    cout << setw(40) << setfill('-') << " ";
    cout << endl;

    //skills
    string skill1;
    string skill2;
    
    cout << "Choose two skills" << endl;
    cout << setw(40) << setfill('-') << " ";
    cout << endl;
    do
    {
        skill_menu();
        ///Menu Selection
        cout << "Select your skill: ";
        cin >> skill1;

    } while (validate_stat(skill1) == false);
    
    ///adds skill to vector
    skills.push_back(skill1);

    do
    {
        ///Menu Selection
        cout << "Select your other skill: ";
        cin >> skill2;
    } while (validate_stat(skill2) == false);

    ///adds skill to vector
    skills.push_back(skill2);

    ///formatting
    cout << setw(40) << setfill('-') << " ";
    cout << endl;

    ///items
    string item;

    ///Menu Selection
    cout << "What item do you carry?" << endl;
    cout << setw(40) << setfill('-') << " ";
    cout << endl;

    item_menu();
    cout << "Select and item: ";
    cin >> item;
    ///data validation
    inventory.push_back(item);

    ///formatting
    cout << setw(40) << setfill('-') << " ";
    cout << endl; 


    }
    ///Menus and Stats
    void Hero::race_menu()
    {
        cout << "1. Human" << endl;
        cout << "2. Hobbit" << endl;
        cout << "3. Dwarf" << endl;
        cout << "4. Elf" << endl;
    }
    void Hero::skill_menu()
    {
        cout << "1. Healing" << endl;
        cout << "2. Fighting" << endl;
        cout << "3. Tracking" << endl;
        cout << "4. Scouting" << endl;
        cout << "5. Baking" << endl;
        cout << "6. Cooking" << endl;
        cout << "7. Wisdom" << endl;
    }
    void Hero::item_menu()
    {
        cout << "1. Axe" << endl;
        cout << "2. Sword" << endl;
        cout << "3. Bow" << endl;
        cout << "4. Daggers" << endl;
        cout << "5. Medical Kit" << endl;
        cout << "6. Cooking Materials" << endl;
    }
    void Hero::hero_stats()
    {
        cout << "Race: " << race << endl;
        cout << "Level: " << level << endl;
        cout << "Exp: " << exp << endl;
        cout << "Skills: " << endl;
        for (int i = 0; i < skills.size(); ++i)
        {
            cout << "\t";
            cout << skills.at(i) << endl;
        }
        ///formatting
        cout << setfill('-') << setw(40) << " " << endl; 
        cout  << "Inventory: " << endl;
        for (int i = 0; i < inventory.size(); ++i)
        {
            
            cout << "\t";
            cout << inventory.at(i) << endl;
           
        }
        cout << setfill('-') << setw(40) << " " << endl; 

    }


    ///Opening Data Files to validate
    bool Hero::validate_stat(string check_skill)
    {
        ifstream in;
        string skill;
        in.open("skills.txt");
        if (in.fail())
        {
            cout << "Failed to Open Skills File" << endl;
            exit(0);
        }
        while(!in.eof())
        {
            getline(in, skill);
            skill = make_lower(skill);
            check_skill = make_lower(check_skill);
            if(check_skill == skill)
            {
                return true;
            }
            skill = "";
        }
        in.close();
        return false;
    }