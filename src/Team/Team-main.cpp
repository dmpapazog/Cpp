#include <iostream>
#include <cstdlib>

#include "Player/Defender.h"
#include "Team/Team.h"

using namespace std;

int main()
{
    Player k("Urko Pardo", 25, 190, 88, 31, false);
    Defender l("Katsiabis", 33, 190, 88, 31, false, 50, 3, 130, 100, 230, 175);

    cout << k.getGrade() << endl;
    cout << l.getGrade() << endl;
    
    Team iraklis("Iraklis", 1908);
    iraklis.addPlayer(&k);
    iraklis.addPlayer(&l);

    Player *a;
    a = iraklis.getPlayer(0);
    if (a != nullptr) {
        cout << a->getAge() << endl;
    }
    cout << iraklis.avgAge() << endl;
    cout << iraklis.sumGrades() << endl;

    return EXIT_SUCCESS;
}