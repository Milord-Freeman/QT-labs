#include "gamefield.h"
#include "constans.h"

GameField::GameField()
{
    GameField::theField = new int[X][Y]; // Выделяет память для игрового поля

    for (int i=0;i<X;i++)
    {
        for (int j=0;j<Y;j++)
        {
            GameField::theField[i][j] = 0; // И заполняет его нулями.
        }
    }
}

int GameField::getState(int x, int y) // Возвращает состояние ячейки по координатам x и y;
{
    return GameField::theField[x][y];
}

void GameField::setState(int x, int y, int state) // Устанавливает состояние в ячейку с координатами x и y;
{
    GameField::theField[x][y] = state;
}

void GameField::setColumm(int i, int newColumm[]) // Изменяет столбец под номером i;
{
    GameField::theField[i] = newColumm;
}

int *GameField::getColumm[](int i) // Возвращает состояние столбца под номером i;
{
    return *theField[i];
}

void GameField::setLine(int i, int newLine[]) // Изменяет линию под номером i;
{
    // TO DO
    // Запилить нормально. Вот ссылка на материал.
    //https://tproger.ru/articles/15-mins-for-2048/
}
