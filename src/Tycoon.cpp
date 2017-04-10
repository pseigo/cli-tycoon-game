#include "../include/Tycoon.h"

Tycoon::Tycoon()
{
    //ctor
}

Tycoon::~Tycoon()
{
    //dtor
}

void Tycoon::PrintStoryIntro()
{
    std::cout << R"(
We'll show them. The idea is genius.
We'll be rich.

    )" << std::endl;

    system("pause");
    system("cls");

    return;
}
