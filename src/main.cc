#include <array>
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

#include "librubik/cube.hh"
#include "librubik/matrix3D.hh"
using namespace rubik;

int main()
{
    std::cout << std::boolalpha;

    std::cout << "Vector3D TESTS :\n\n";
    auto coords = Vector3D<int>{ 0, 1, 1 };
    auto colors = Vector3D<Color>{ Color::NONE, Color::RED, Color::WHITE };
    std::cout << coords << ' ' << colors << '\n';

    auto v1 = Vector3D<int>{ 1, 0, -1 };
    auto v2 = Vector3D<int>{ 1, 1, -1 };
    std::cout << (v1 == v1) << '\n';
    std::cout << (v1 != v2) << '\n';
    std::cout << (v1 == v2) << '\n';

    auto v3 = Vector3D<Color>{ Color::NONE, Color::RED, Color::WHITE };
    auto v4 = Vector3D<Color>{ Color::NONE, Color::ORANGE, Color::WHITE };

    std::cout << (v3 == v3) << '\n';
    std::cout << (v3 != v4) << '\n';
    std::cout << (v3 == v4) << '\n';

    std::cout << '\n';

    std::cout << "Piece TESTS :\n\n";

    auto front_left_edge =
        Piece{ { 1, -1, 0 }, { Color::GREEN, Color::ORANGE, Color::NONE } };
    std::cout << front_left_edge << '\n';

    auto p1_ = Piece{ { 1, 1, 1 }, { Color::GREEN, Color::RED, Color::WHITE } };
    auto p2_ =
        Piece{ { 0, 0, -1 }, { Color::NONE, Color::NONE, Color::YELLOW } };
    auto p3_ =
        Piece{ { -1, -1, 0 }, { Color::BLUE, Color::ORANGE, Color::NONE } };
    auto p4 = Piece{ { 0, 0, 0 }, { Color::NONE, Color::NONE, Color::NONE } };

    std::cout << p1_.get_type() << '\n';
    std::cout << p2_.get_type() << '\n';
    std::cout << p3_.get_type() << '\n';
    std::cout << p4.get_type() << '\n';

    auto p5 = Piece{ { 0, 0, 0 }, { Color::NONE, Color::NONE, Color::NONE } };
    auto p6 = Piece{ { 1, 0, 0 }, { Color::NONE, Color::NONE, Color::NONE } };
    auto p7 = Piece{ { 0, 0, 0 }, { Color::YELLOW, Color::NONE, Color::NONE } };

    std::cout << (p5 == p5) << '\n';
    std::cout << (p5 == p6) << '\n';
    std::cout << (p5 == p7) << '\n';

    auto p8 = Piece{ { -1, 0, 0 }, { Color::BLUE, Color::NONE, Color::NONE } };
    auto p9 = Piece{ { -1, 1, 0 }, { Color::BLUE, Color::RED, Color::NONE } };
    auto p10 = Piece{ { -1, 1, 1 }, { Color::BLUE, Color::RED, Color::WHITE } };

    std::cout << (p8 < p9) << '\n';
    std::cout << (p9 < p10) << '\n';

    Cube cube = Cube();
    std::cout << cube;

    std::ifstream file("tests/cube_state_example.txt");
    Cube cube1 = Cube::from_stream(file);
    std::cout << "\nRead cube state:\n" << cube1 << '\n';
    std::cout << "\nTEST find-------------\n";
    auto red_center = cube.find_piece({ 0, 1, 0 });
    std::cout << red_center << '\n';
    // Must print: (0,1,0) (X,R,X)
    auto p1 = cube.find_piece({ Color::NONE, Color::RED, Color::NONE });
    auto p2 = cube.find_piece({ Color::RED, Color::NONE, Color::NONE });
    auto p3 = cube.find_piece({ Color::NONE, Color::NONE, Color::RED });
    // (p1 == red_center && p2 == red_center && p3 == red_center) => true
    std::cout << p1 << '\n';
    std::cout << p2 << '\n';
    std::cout << p3 << '\n';
    // A constructor accepting a 3×3 array
    std::array<std::array<int, 3>, 3> values = {
        { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } }
    };
    auto matrix = Matrix3D<int>{ values };
    // A getter to access individual elements
    std::cout << matrix.at(1, 1) << '\n';
    matrix.transpose();
    std::cout << matrix.at(1, 1) << ' ' << matrix.at(0, 1) << ' '
              << matrix.at(0, 2) << '\n';
    // Must print: 5 4 7
    auto res = matrix * Vector3D<int>{ 1, 2, 3 };
    std::cout << res << '\n';
    // Must print: (30,36,42)uto matrix = rubik::Matrix3D<int>{ values };
    return 0;
}
