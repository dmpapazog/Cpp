#include "Attacker.h"

Attacker::Attacker(const char* const name,
                   const int&        age,
                   const int&        height,
                   const double&     weight,
                   const int&        games,
                   const bool&       international,
                   const int&        shots,
                   const int&        goals,
                   const int&        passes,
                   const int&        s_passes,
                   const int&        tackles,
                   const int&        s_tackles)
: FieldPlayer(name,
              age,
              height,
              weight,
              games,
              international,
              shots,
              goals,
              passes,
              s_passes,
              tackles,
              s_tackles)
{
}

double Attacker::getGrade() const
{
    double grade = FieldPlayer::getGrade();
    grade += 0.5 * getDefending();
    grade += 1.5 * getMidfieldering();
    grade += 2.5 * getAttacking();

    return grade;
}