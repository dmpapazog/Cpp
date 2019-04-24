#ifndef TEAM_H
#define TEAM_H

#include "Player/Player.h"

#define MAX_NUMBER 30

class Team {
    private:
        char* name;
        int foundation_year;
        Player *lineup[MAX_NUMBER];
        int numPlayers;

    public:
        Team(const char* const name,
             const int&        foundation_year);

        ~Team();

        bool addPlayer(Player *const player);
        Player *getPlayer(const int &index) const;
        double avgAge() const;
        double sumGrades() const;
};



#endif // TEAM_H