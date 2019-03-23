#ifndef DEFENDER_H
#define DEFENDER_H

#include "FieldPlayer.h"

class Defender : public FieldPlayer {
    public:
        Defender(const char* const name,
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

#endif // DEFENDER_H