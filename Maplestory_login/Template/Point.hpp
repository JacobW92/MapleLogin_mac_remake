//
//  Point.hpp
//  Maplestory_login
//
//  Created by Jacob on 5/18/25.
//

#ifndef Point_hpp
#define Point_hpp

#include <string>
#include <cmath>
#include <nlnx/node.hpp>

namespace ms
{
    template <class T>
    class Point
    {
    public:
        // Construct a point from  a vector property.
        // 从向量的属性构建一个坐标点。
        Point(nl::node src)
        {
            a = static_cast<T>(src.x());
            b = static_cast<T>(src.y());
        }
        // Construct a point from the specified coordinates.
        // 从一个特定的坐标构建一个坐标点。
        constexpr Point(T fir, T sec) : a(fir), b(sec) {}
        // Construct a point with coordinates (0, 0).
        // 从(0, 0)构建一个坐标。
        constexpr Point() : Point(0, 0) {}
        // Return the x-coordinate.
        // 返回x坐标
        constexpr T x() const {
            return a;
        }
        // Return the y-coordinate.
        // 返回y坐标
        constexpr T y() const {
            return b;
        }
        
        // Return the inner product.
        // 返回距离
        
        constexpr T length() const {
            return static_cast<T>(std::sqrt(a*a+b*b));
        }
        
        
        
    private:
        T a;
        T b;
    };
}

#endif /* Point_hpp */
