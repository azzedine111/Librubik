#pragma once
#include <iostream>
namespace rubik
{
    enum class Color : char
    {
        WHITE = 'W',
        YELLOW = 'Y',
        GREEN = 'G',
        BLUE = 'B',
        RED = 'R',
        ORANGE = 'O',
        NONE = 'X'
    };

    inline std::ostream& operator<<(std::ostream& os, const Color& color)
    {
        switch (color)
        {
        case rubik::Color::WHITE:
            os << "W";
            break;
        case rubik::Color::YELLOW:
            os << "Y";
            break;
        case rubik::Color::GREEN:
            os << "G";
            break;
        case rubik::Color::BLUE:
            os << "B";
            break;
        case rubik::Color::RED:
            os << "R";
            break;
        case rubik::Color::ORANGE:
            os << "O";
            break;
        case rubik::Color::NONE:
            os << "X";
            break;
        }
        return os;
    }
    // FIXME

} // namespace rubik
