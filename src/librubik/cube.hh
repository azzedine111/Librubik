#pragma once
#include <cstring>
#include <vector>

#include "piece.hh"

namespace rubik
{
    class Cube
    {
    private:
        std::vector<Piece> pieces_;

    public:
        Cube();
        friend std::ostream& operator<<(std::ostream& os, const Cube& cube);
        static Cube from_stream(std::istream& is);
        std::vector<Piece>::iterator begin()
        {
            return this->pieces_.begin();
        };
        std::vector<Piece>::iterator end()
        {
            return this->pieces_.end();
        };
        std::vector<Piece>::const_iterator begin() const
        {
            return this->pieces_.cbegin();
        };
        std::vector<Piece>::const_iterator end() const
        {
            return this->pieces_.cend();
        };
        Piece find_piece(Vector3D<int> coords) const;
        Piece find_piece(Vector3D<Color> colors) const;
    };

} // namespace rubik
