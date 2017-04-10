#include "../include/FGraphic.h"

FGraphic::FGraphic()
{
    //ctor
}

FGraphic::~FGraphic()
{
    //dtor
}

// define boxwidth as an int. boxwidth < 1 will automatically set a width (slower).
void FGraphic::drawBox(int boxWidth, std::vector<std::string> items) const
{
    // Top Row
    std::cout << pCornerTopLeft;

    if (boxWidth < 1) {
        // auto length
        int longestItem = 0;
        for (std::string currentItem : items) {
            if (currentItem.length() > longestItem) {
                longestItem = currentItem.length();
            }
        }
        if (boxWidth == -100) { std::cout << "\nAuto box width is " << longestItem + 2 << std::endl; }
        boxWidth = longestItem + 2;
    }

    for (int i = 0; i < boxWidth; i++) { std::cout << pStraightHorizontal; }
    std::cout << pCornerTopRight << std::endl;

    // Content
    for (std::string currentItem : items) {
        std::cout << pStraightVertical << " ";
        std::cout << currentItem;
        //std::cout << items[currentItem];

        // Spaces to end of box
        for (int spaceCount = 0; spaceCount < (boxWidth - currentItem.length() - 1); spaceCount++) {
            std::cout << ' ';
        }

        std::cout << pStraightVertical << std::endl;
    }

    // Bottom Row
    std::cout << pCornerBottomLeft;
    for (int i = 0; i < boxWidth; i++) { std::cout << pStraightHorizontal; }
    std::cout << pCornerBottomRight << std::endl;

}
