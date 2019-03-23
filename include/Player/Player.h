#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    char*  name;          // όνομα
    int    age;           // ηλικία
    int    height;        // ύψος
    double weight;        // βάρος
    int    played_games;  // συμμετοχές
    bool   international; // διεθνής

    double getExperience() const; // T
    double getPhysical() const;   // P

public:
    Player(const char* const name,
           const int&        age,
           const int&        height,
           const double&     weight,
           const int&        games,
           const bool&       international);
    ~Player();

    char* getName() const;
    int   getAge()  const;

    virtual double getGrade() const;
};

#endif // PLAYER_H