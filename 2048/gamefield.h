#ifndef GAMEFIELD_H
#define GAMEFIELD_H


class GameField
{
private:
    int theField[][];

public:
    GameField();
    int getState(int x, int y);
    void setState(int x, int y, int state);
    void setColumm(int i, int newColumm[]);
    int *getColumm[](int i);
};

#endif // GAMEFIELD_H
