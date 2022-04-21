#pragma once
#include "color.hh"
#include "vector3D.hh"

namespace rubik
{
    class Piece
    {
    public:
        Vector3D<int> coords;
        Vector3D<Color> colors;
        enum Type
        {
            CORNER,
            CENTER,
            EDGE,
            NONE
        };

        Piece(Vector3D<int> coords_, Vector3D<Color> colors_);
        friend std::ostream& operator<<(std::ostream& os, const Piece& p);
        Type get_type();
        bool operator==(const Piece& other);
        bool operator<(const Piece& other);
        bool operator!=(const Piece& other);
        bool operator>(const Piece& other);
        bool operator<=(const Piece& other);
        bool operator>=(const Piece& other);
    };
} // namespace rubik
