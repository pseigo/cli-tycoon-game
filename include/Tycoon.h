#ifndef TYCOON_H
#define TYCOON_H

#include <iostream>
#include <windows.h>


class Tycoon
{
    public:
        Tycoon();
        virtual ~Tycoon();

        void PrintStoryIntro();
        void PrintMainMenu();
        void GetMainMenuInput();

    protected:
    private:
};

#endif // TYCOON_H
