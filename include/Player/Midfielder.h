#ifndef MIDFIELDER_H
#define MIDFIELDER_H

#include "FieldPlayer.h"

class Midfielder : public FieldPlayer {
    public:
        Midfielder(const char* const name,
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

#endif // MIDFIELDER_H