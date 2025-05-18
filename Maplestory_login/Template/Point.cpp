//
//  Point.cpp
//  Maplestory_login
//
//  Created by Jacob on 5/18/25.
//

#include "Point.hpp"

namespace ms
{
//    class Point
//    {
//    public:
//        // Construct a point from  a vector property.
//        // 从向量的属性构建一个坐标点。
    template <class T>
    Point<T>::Point(nl::node src)
    {
        a = static_cast<T>(src.x());
        b = static_cast<T>(src.y());
    }
    // Construct a point from the specified coordinates.
    // 从一个特定的坐标构建一个坐标点。
    template <class T>

    constexpr Point<T>::Point(T fir, T sec) : a(fir), b(sec) {}
    // Construct a point with coordinates (0, 0).
    // 从(0, 0)构建一个坐标。

    template <class T>

    constexpr Point<T>::Point() : Point(0, 0) {}
    // Return the x-coordinate.
    // 返回x坐标
    template <class T>

    constexpr T Point<T>::x() const {
        return a;
    }
    // Return the y-coordinate.
    // 返回y坐标
    template <class T>
    constexpr T Point<T>::y() const {
        return b;
    }
    
    // Return the inner product.
    // 返回距离
    template <class T>

    constexpr T Point<T>::length() const {
        return static_cast<T>(std::sqrt(a*a+b*b));
    }
    
    // Check whether the coordinates are equal.
    // 检查坐标是否相等
    template <class T>

    constexpr bool Point<T>::straight() const {
        return a == b;
    }
    
    // Return a string representation of the point.
    // 返回用string输出的坐标
    template <class T>

    std::string Point<T>::to_string() const {
        return "("+std::to_string(a)+","+std::to_string(b)+")";
    }
    
    // Return the distance to another point
    // 返回 和另一个点的距离
    template <class T>
    constexpr T Point<T>::distance(Point<T> v) const {
        return Point<T>(a-v.a, b-v.b).length();
    }
    
    template <class T>
    void Point<T>::set_x(T x) {
        a = x;
    }
    
    template <class T>
    void Point<T>::set_y(T y) {
        b = y;
    }
    
    template <class T>
    void Point<T>::shift_x(T x) {
        a += x;
    }
    
    template <class T>
    void Point<T>::shift_y(T y) {
        b += y;
    }
    // Shift the this point by the amounts defined by another point. Equivalent to operator +=.
    template <class T>
    void Point<T>::shift(Point<T> v) {
        a += v.a;
        b += v.b;
    }
    
    // Check whether point is equivalent to the specified point.
    template <class T>
    constexpr bool Point<T>::operator == (const Point<T>& v) const {
        return a == v.a && b == v.b;
    }

    // Check whether point is not equivalent to the specified point.
    template <class T>
    constexpr bool Point<T>::operator != (const Point<T>& v) const {
        return !(*this == v);
    }

    // Shift the this point by the amounts defined by another point.
    template <class T>
    void Point<T>::operator += (Point<T> v) {
        a += v.a;
        b += v.b;
    }

    // Shift the this point in reverse direction by the amounts defined by another point.
    template <class T>
    void Point<T>::operator -= (Point<T> v) {
        a -= v.a;
        b -= v.b;
    }

    // Return a point whose coordinates are the negation of this point's coordinates.
    template <class T>
    constexpr Point<T> Point<T>::operator - () const {
        return { -a, -b };
    }

    // Return a point whose coordinates have been added the specified amount.
    template <class T>
    constexpr Point<T> Point<T>::operator + (T v) const {
        return { a + v, b + v };
    }

    // Return a point whose coordinates have been substracted the specified amount.
    template <class T>
    constexpr Point<T> Point<T>::operator - (T v) const {
        return { a - v, b - v };
    }

    // Return a point whose coordinates have been multiplied by the specified amount.
    template <class T>
    constexpr Point<T> Point<T>::operator * (T v) const {
        return { a * v, b * v };
    }

    // Return a point whose coordinates have been divided by the specified amount.
    template <class T>
    constexpr Point<T> Point<T>::operator / (T v) const {
        return { a / v, b / v };
    }

    // Return a point whose coordinates are the sum of this and another points coordinates.
    template <class T>
    constexpr Point<T> Point<T>::operator + (Point<T> v) const {
        return { a + v.a, b + v.b };
    }

    // Return a point whose coordinates are the difference of this and another points coordinates.
    template <class T>
    constexpr Point<T> Point<T>::operator - (Point<T> v) const {
        return { a - v.a, b - v.b };
    }

    // Return a point whose coordinates are the product of this and another points coordinates.
    template <class T>
    constexpr Point<T> Point<T>::operator * (Point<T> v) const {
        return { a / v.a, b / v.b };
    }

    // Return a point whose coordinates are the division of this and another points coordinates.
    template <class T>
    constexpr Point<T> Point<T>::operator / (Point<T> v) const {
        return {
            a / (v.a == 0 ? 1 : v.a),
            b / (v.b == 0 ? 1 : v.b)
        };
    }

    
        
//        
//    private:
//        T a;
//        T b;
//    };
}

