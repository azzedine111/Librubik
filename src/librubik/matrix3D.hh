#pragma once
#include <array>
#include <vector>

#include "vector3D.hh"
namespace rubik
{
    template <typename T>

    class Matrix3D
    {
    private:
        T x;
        T y;
        T z;
        std::array<std::array<int, 3>, 3> matrix_;

    public:
        Matrix3D(std::array<std::array<int, 3>, 3> matrix)
            : matrix_(matrix){};

        T at(int i, int j)
        {
            return matrix_[i][j];
        }
        Vector3D<T> operator*(const Vector3D<T>& v) const
        {
            T cord1;
            T cord2;
            T cord3;
            cord1 =
                matrix_[0][0] * v.x + matrix_[0][1] * v.y + matrix_[0][2] * v.z;
            cord2 =
                matrix_[1][0] * v.x + matrix_[1][1] * v.y + matrix_[1][2] * v.z;
            cord3 =
                matrix_[2][0] * v.x + matrix_[2][1] * v.y + matrix_[2][2] * v.z;
            return Vector3D<T>(cord1, cord2, cord3);
        }
        void transpose()
        {
            int tmp = 0;
            T temp;
            for (int i = 0; i < 2; i++)
            {
                for (int j = tmp; j < 3; j++)
                {
                    temp = matrix_[j][i];
                    matrix_[j][i] = matrix_[i][j];
                    matrix_[i][j] = temp;
                }
                tmp++;
            }
        }
    };

} // namespace rubik
