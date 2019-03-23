#ifndef ATTACKER_H
#define ATTACKER_H

#include "FieldPlayer.h"

class Attacker : public FieldPlayer {
    public:
        Attacker(const char* const name,
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
                 const int&        s_tackles);

        double getGrade() const;
};

#endif // ATTACKER_H