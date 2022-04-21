#include "piece.hh"

#include "color.hh"

namespace rubik
{
    Piece::Piece(Vector3D<int> coords_, Vector3D<Color> colors_)
        : coords(coords_)
        , colors(colors_)
    {}

    std::ostream& operator<<(std::ostream& os, const Piece& p)
    {
        os << p.coords << " " << p.colors;
        return os;
    }

    Piece::Type Piece::get_type()
    {
        int compteur = 0;
        if (this->colors.x == Color::NONE)
            compteur++;
        if (this->colors.y == Color::NONE)
            compteur++;
        if (this->colors.z == Color::NONE)
            compteur++;
        if (compteur == 0)
            return CORNER;
        else if (compteur == 1)
            return EDGE;
        else if (compteur == 2)
            return CENTER;
        else
            return NONE;
    }

    bool Piece::operator==(const Piece& other)
    {
        if (coords == other.coords && colors == other.colors)
            return true;
        return false;
    }

    bool Piece::operator!=(const Piece& other)
    {
        if (coords == other.coords && colors == other.colors)
            return false;
        return true;
    }

    bool Piece::operator<(const Piece& other)
    {
        if (coords.x < other.coords.x)
            return true;
        if (coords.y < other.coords.y && coords.x == other.coords.x)
            return true;
        if (coords.z < other.coords.z && coords.y == other.coords.y
            && coords.x == other.coords.x)
            return true;
        return false;
    }

    bool Piece::operator>(const Piece& other)
    {
        if (coords.x > other.coords.x)
            return true;
        if (coords.y > other.coords.y && coords.x == other.coords.x)
            return true;
        if (coords.z > other.coords.z && coords.y == other.coords.y
            && coords.x == other.coords.x)
            return true;
        return false;
    }

    bool Piece::operator>=(const Piece& other)
    {
        if (coords == other.coords)
            return true;
        if (coords.x > other.coords.x)
            return true;
        if (coords.y > other.coords.y && coords.x == other.coords.x)
            return true;
        if (coords.z > other.coords.z && coords.y == other.coords.y
            && coords.x == other.coords.x)
            return true;
        return false;
    }

    bool Piece::operator<=(const Piece& other)
    {
        if (coords == other.coords)
            return true;
        if (coords.x < other.coords.x)
            return true;
        if (coords.y < other.coords.y && coords.x == other.coords.x)
            return true;
        if (coords.z < other.coords.z && coords.y == other.coords.y
            && coords.x == other.coords.x)
            return true;
        return false;
    }

} // namespace rubik
