#ifndef GOALIE_H
#define GOALIE_H

#include "Player.h"

class Goalie : public Player {
private:
    int saves;   // αποκρούσεις
    int n_goals; // αρνητικά τέρματα

    double getGoaling() const; // G

public:
    Goalie(const char* const name,
           const int&        age,
           const int&        height,
           const double&     weight,
           const int&        games,
           const bool&       international,
           const int&        saves,
           const int&        n_goals);

    double getGrade() const;
};

#endif // GOALIE_H