#ifndef PLAYER_H
#define PLAYER_H

class player{
public:
    player();
    virtual void move();
    virtual string getMoves();
    char getMove();
    bool win(Player * opponent);
    ~player();
protected:
    char recentMove;
    int numMovies;
};
#endif
