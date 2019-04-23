#ifndef DSTATE_H
#define DSTATE_H

#include <string>
#include <vector>

using std::string;

class DState {
private:
    int     side;
    int    *board;
    DState *parent;
    int     grade;
    string  move;

    // Generate the 1-dim index of the 2 coordinates
    // based on the eq index = x * row + y
    int getIndex(const int& x, const int& y) const;

    // Set the value of every tile to -1;
    void initDState();
    void swap(int& a, int& b);

    // Save the 2-dim coordinates of tile num.
    bool findNum(int& x, int& y, const int& num) const;

public:
    DState(const int&    side);
    DState(const DState& old);
    ~DState();

    int     getGrade()  const { return grade;  }
    DState *getParent() const { return parent; }
    string  getMove()   const { return move;   }

    void setFinalDState();

    // The problem's given board.
    void setDefaultInitialDState();
    void setRandomInitialDState();
    int  setManhattan();

    bool isSolvable() const;

    // Move functions takes into account the x and y
    // of the 0's position.
    bool    moveUp(const int& x, const int& y, DState& child);
    bool moveRight(const int& x, const int& y, DState& child);
    bool  moveDown(const int& x, const int& y, DState& child);
    bool  moveLeft(const int& x, const int& y, DState& child);

    void expand(std::vector<DState>& children);

    void show() const;

    // Append every tile's number to a string and return it.
    string myHash() const;

    DState operator=(const DState& rhs);

    friend bool operator==(const DState& lhs, const DState& rhs);
    friend bool operator!=(const DState& lhs, const DState& rhs);
    friend bool  operator<(const DState& lhs, const DState& rhs);
    friend bool  operator>(const DState& lhs, const DState& rhs);
    friend bool operator<=(const DState& lhs, const DState& rhs);
    friend bool operator>=(const DState& lhs, const DState& rhs);
};

#endif // DSTATE_H