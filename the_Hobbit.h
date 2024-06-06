/**
 *        @file: the_Hobbit.h
 *      @author: Kylie Roenigk
 *        @date: June 06, 2024
 *       @brief: This is the header program for the_Hobbit file
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
    private:
    string race;
    vector<string> skills;
    int level;
    int exp;
    int health;
    vector<string> inventory;

    public:
    ///setters and getters
    void set_race(string new_race);
    string get_race();
    void set_skills(vector<string> skills);
    vector<string> get_skills();
    void set_level(int new_level);
    int get_level();
    void set_exp(int new_exp);
    int get_exp();
    void set_health(int new_health);
    int get_health();
    void set_inventory(vector<string> new_inventory);
    vector<string> get_inventory();

    ///Helper Functions
    void add_to_inventory(string new_item);
    void level_Up();


};
class Adventure
{
    private:
    string title;
    string description;
    int exp_reward;
    int p_damage;

    public:
    ///Constructors
    Adventure(string data);
    /// setters and getters
    void set_title(string new_title);
    string get_title();
    void set_description(string new_description);
    string get_description();
    void set_exp_reward(int new_exp_reward);
    int get_exp_reward();
    void set_p_damage(int new_p_damage);
    int get_p_damage();
};