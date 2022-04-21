#pragma once
#include <ostream>
namespace rubik
{
    template <typename T>

    class Vector3D
    {
    public:
        T x;
        T y;
        T z;

        Vector3D(T x_, T y_, T z_)
            : x(x_)
            , y(y_)
            , z(z_){};

        friend std::ostream& operator<<(std::ostream& os, const Vector3D& v)
        {
            os << '(' << v.x << ',' << v.y << ',' << v.z << ')';
            return os;
        }

        bool operator==(const Vector3D& other)
        {
            if (this->x == other.x && this->y == other.y && this->z == other.z)
                return true;
            return false;
        }

        bool operator!=(const Vector3D& other)
        {
            if (this->x == other.x && this->y == other.y && this->z == other.z)
                return false;
            return true;
        }
    };
} // namespace rubik
