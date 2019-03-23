#include <cstdlib>
#include <cstring>

#include "Team.h"

Team::Team(const char* const name,
           const int&        foundation_year)
{
    this->name = (char *)malloc(strlen(name));
    strcpy(this->name, name);
    
    this->foundation_year = foundation_year;

    numPlayers = 0;
}

Team::~Team()
{
    free(name);
}

bool Team::addPlayer(Player *const player)
{
    if (numPlayers < MAX_NUMBER) {
        lineup[numPlayers] = player;
        numPlayers++;
        return true;
    } else {
        return false;
    }
}

double Team::avgAge() const
{
    int sum = 0;   
    for (int i = 0; i < numPlayers; i++) {
        sum += lineup[i]->getAge();
    }
    return double(sum) / double(numPlayers);
}

double Team::sumGrades() const
{
    double sum = 0;   
    for (int i = 0; i < numPlayers; i++) {
        sum += lineup[i]->getGrade();
    }
    return sum;
}

Player *Team::getPlayer(const int& index) const
{
    if (index < numPlayers) {
        return lineup[index];
    } else {
        return nullptr;
    }
}