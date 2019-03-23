#include "FieldPlayer.h"

FieldPlayer::FieldPlayer(const char* const name,
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
: Player(name,
         age,
         height,
         weight,
         games,
         international)
{
    this->shots   = shots;
    this->goals = goals;
    this->passes = passes;
    this->s_passes = s_passes;
    this->tackles = tackles;
    this->s_tackles = s_tackles;
}

double FieldPlayer::getDefending() const
{
    return double(s_tackles) / double(tackles);
}

double FieldPlayer::getMidfieldering() const
{
    return double(s_passes) / double(passes);
}

double FieldPlayer::getAttacking() const
{
    return double(goals) / double(shots);
}