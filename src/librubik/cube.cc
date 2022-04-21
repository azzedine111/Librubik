#include "cube.hh"

#include <fstream>

namespace rubik
{
    Cube::Cube()
    {
        rubik::Color color_x;
        rubik::Color color_y;
        rubik::Color color_z;
        for (int x = -1; x < 2; x++)
        {
            if (x == 1)
            {
                color_x = Color::GREEN;
            }
            if (x == 0)
            {
                color_x = Color::NONE;
            }
            if (x == -1)
            {
                color_x = Color::BLUE;
            }
            for (int y = -1; y < 2; y++)
            {
                if (y == 1)
                {
                    color_y = Color::RED;
                }
                if (y == 0)
                {
                    color_y = Color::NONE;
                }
                if (y == -1)
                {
                    color_y = Color::ORANGE;
                }
                for (int z = -1; z < 2; z++)
                {
                    if (z == 1)
                    {
                        color_z = Color::WHITE;
                    }
                    if (z == 0)
                    {
                        color_z = Color::NONE;
                    }
                    if (z == -1)
                    {
                        color_z = Color::YELLOW;
                    }

                    Vector3D<int> cord = { x, y, z };
                    Vector3D<Color> col = { color_x, color_y, color_z };
                    Piece piece = Piece(cord, col);
                    pieces_.push_back(piece);
                }
            }
        }
    }

    std::ostream& operator<<(std::ostream& os, const Cube& cube)
    {
        for (auto i = 0; i < 27; i++)
        {
            os << cube.pieces_[i] << '\n';
        }
        return os;
    }

    Cube Cube::from_stream(std::istream& is)
    {
        std::string token;
        std::vector<std::string> vec_l;
        std::vector<std::string> vec_r;
        std::string left_str;
        std::string right_str;
        Cube cube;
        cube.pieces_.clear();

        while (std::getline(is, token))
        {
            int x, y, z;
            char c_x, c_y, c_z;
            int ret = std::sscanf(token.c_str(), "(%d,%d,%d) (%c,%c,%c)", &x,
                                  &y, &z, &c_x, &c_y, &c_z);
            if (ret != 6)
                throw std::invalid_argument("bad format");
            if (x < -1 || x > 1 || y < -1 || y > 1 || z < -1 || z > 1)
                throw std::invalid_argument("error variable");
            if ((c_x == 'W' || c_x == 'Y' || c_x == 'G' || c_x == 'B'
                 || c_x == 'R' || c_x == 'O' || c_x == 'X')
                && (c_y == 'W' || c_y == 'Y' || c_y == 'G' || c_y == 'B'
                    || c_y == 'R' || c_y == 'O' || c_y == 'X')
                && (c_z == 'W' || c_z == 'Y' || c_z == 'G' || c_z == 'B'
                    || c_z == 'R' || c_z == 'O' || c_z == 'X'))
            {
                Piece piece = Piece(Vector3D<int>(x, y, z),
                                    Vector3D<Color>(static_cast<Color>(c_x),
                                                    static_cast<Color>(c_y),
                                                    static_cast<Color>(c_z)));
                cube.pieces_.push_back(piece);
            }
            else
                throw std::invalid_argument("color is invalid");
        }
        return cube;
    }

    Piece Cube::find_piece(Vector3D<int> coords) const
    {
        for (auto value : pieces_)
        {
            if (value.coords == coords)
                return value;
        }
        throw std::invalid_argument("coords not available");
    }

    Piece Cube::find_piece(Vector3D<Color> colors) const
    {
        std::vector<Color> c_vec({ static_cast<Color>(colors.x),
                                   static_cast<Color>(colors.y),
                                   static_cast<Color>(colors.z) });
        for (auto value : pieces_)
        {
            Color x = value.colors.x;
            Color y = value.colors.y;
            Color z = value.colors.z;
            std::vector<rubik::Color> vec({ static_cast<Color>(x),
                                            static_cast<Color>(y),
                                            static_cast<Color>(z) });
            if (is_permutation(c_vec.begin(), c_vec.end(), vec.begin()))
            {
                return value;
            }
        }
        throw std::invalid_argument("colors not available");
    }

} // namespace rubik
