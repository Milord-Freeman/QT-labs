#include <iostream>

using namespace std;

// // // // // // // //
//       ИГРА        //
//        НЕ         //
//     ДОДЕЛАНА!     //
//      СМОТРИ       //
//        В          //
// gamefield.cpp!!!  //
// // // // // // // //


int main(int argc, char *argv[])
{
    initFields(); // Инициализируем поле;
    createInitialCells(); // Инициализируем стартовые значения;

    while (!endOfGame)
    {
        input(); // Ввод данных от пользователя;
        logic(); // Преобразование главного массива;
        drawind(); // Отрисовка изменений;
    }
    return 0;
}
