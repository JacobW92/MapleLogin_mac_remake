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
        // 从
        constexpr Point() : Point(0, 0) {}
        
        
        
        
    private:
        T a;
        T b;
    };
}

#endif /* Point_hpp */
