//
//  Range.cpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#include "Range.hpp"



namespace ms {

    template <class T>
    class Range {
        
        constexpr Range(const T& fir, const T& sec): a(fir), b(sec){}
        
        constexpr Range() : Range(0,0) {}
        
        constexpr const T& fir() const {
            return a;
        }
        constexpr const T& sec() const {
            return b;
        }
        constexpr const T& greater() const {
            return (a>b)?a:b;
        }
        constexpr const T& smaller() const {
            return (a<b)?a:b;
        }
        constexpr T delta() const {
            return b - a;
        }
        constexpr T length() const {
            return greater() - smaller();
        }
        constexpr T center() const {
            return (a + b)/2;
        }
        constexpr bool empty() const {
            return a == b;
        }
        constexpr bool contains(const T& v) const {
            return v.a >= a && v.b <= b;
        }
        constexpr bool contains(const Range<T>& v) const {
            return v.a >= a && v.b <= b;
        }
        constexpr bool overlaps(const Range<T>& v) const {
            return contains(v.a) || contains(v.b) || v.contains(a) || v.contains(b);
        }
        constexpr bool operator == (const Range<T>& v) const {
            return a == v.a && b == v.b;
        }
        constexpr bool operator != (const Range<T>& v) const {
            return !(*this == v);
        }
        constexpr Range<T> operator + (const Range<T>& v) const {
            return {a+v.a, b+v.b};
        }
        constexpr Range<T> operator - (const Range<T>& v) const {
            return {a-v.a, b-v.b};
        }
        constexpr Range<T> operator - () const {
            return {-a , -b};
        }
        static Range<T> symmetric(const T& mid, const T& tail){
            return {mid - tail, mid + tail};
        }
        
    private:
        T a;
        T b;
    };


}




