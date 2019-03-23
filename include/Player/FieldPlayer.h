#ifndef FIELDPLAYER_H
#define FIELDPLAYER_H

#include "Player.h"

class FieldPlayer : public Player {
    private:
        int shots;     // σύνολο σουτ
        int goals;     // γκολ
        int passes;    // σύνολο πασών
        int s_passes;  // επιτυχημένες πάσες
        int tackles;   // σύνολο τάκλιν
        int s_tackles; // επιτυχημένα τάκλιν
    protected:
        double getDefending()     const; // D
        double getMidfieldering() const; // M
        double getAttacking()     const; // A
    public:
        FieldPlayer(const char* const name,
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
        ~FieldPlayer();
};


#endif // FIELDPLAYER_H