#include "Goalie.h"

Goalie::Goalie(const char* const name,
               const int&        age,
               const int&        height,
               const double&     weight,
               const int&        games,
               const bool&       international,
               const int&        saves,
               const int&        n_goals)
: Player(name,
         age,
         height,
         weight,
         games,
         international)
{
    this->saves   = saves;
    this->n_goals = n_goals;
}

double Goalie::getGoaling() const
{
    return double(saves) / double(n_goals);
}

double Goalie::getGrade() const
{
    return Player::getGrade() + 2 * getGoaling();
}