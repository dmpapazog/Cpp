#include <cstring>
#include <cstdlib>

#include "Player.h"

Player::Player(const char *const name,
               const int &age,
               const int &height,
               const double &weight,
               const int &games,
               const bool &international)
{
    this->name = (char *)malloc(strlen(name));
    strcpy(this->name, name);
    this->age = age;
    this->height = height;
    this->weight = weight;
    this->played_games = games;
    this->international = international;
}

Player::~Player()
{
    free(name);
}

char *Player::getName() const
{
    return name;
}

int Player::getAge() const
{
    return age;
}

double Player::getExperience() const
{
    double experience;
    experience = double(played_games) * double(age);
    
    if (international) {
        experience *= 1.5;
    }
    return experience;
}

double Player::getPhysical() const
{
    return double(height) * double(weight);
}

double Player::getGrade() const
{
    return 0.9 * getExperience() + 1.1 * getPhysical();
}