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
        Point(nl::node src);
        constexpr Point(T fir, T sec);
        constexpr Point();
        constexpr T x() const;
        constexpr T y() const;
        constexpr T length() const;
        constexpr bool straight() const;
        std::string to_string() const;
        constexpr T distance(Point<T> v) const;
        void set_x(T v);
        void set_y(T v);
        void shift_x(T v);
        void shift_y(T v);
        void shift(T x, T y);
        void shift(Point<T> v);
        constexpr bool operator == (const Point<T>& v) const;
        constexpr bool operator != (const Point<T>& v) const;
        void operator += (Point<T> v);
        void operator -= (Point<T> v);
        constexpr Point<T> operator - () const;
        constexpr Point<T> operator + (T v) const;
        constexpr Point<T> operator - (T v) const;
        constexpr Point<T> operator * (T v) const;
        constexpr Point<T> operator / (T v) const;
        constexpr Point<T> operator + (Point<T> v) const;
        constexpr Point<T> operator - (Point<T> v) const;
        constexpr Point<T> operator * (Point<T> v) const;
        constexpr Point<T> operator / (Point<T> v) const;
    private:
        T a;
        T b;
    };
}

#endif /* Point_hpp */
