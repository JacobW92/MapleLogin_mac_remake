//
//  Range.hpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#ifndef Range_hpp
#define Range_hpp

#include <string>
#include <stdio.h>
namespace ms {
    template <class T>
    class Range {
        constexpr const T& fir() const ;
        constexpr const T& sec() const ;
        constexpr const T& greater() const ;
        constexpr const T& smaller() const ;
        constexpr T delta() const ;
        constexpr T length() const ;
        constexpr T center() const ;
        constexpr bool empty() const ;
        constexpr bool contains(const T& v) const ;
        constexpr bool contains(const Range<T>& v) const ;
        constexpr bool overlaps(const Range<T>& v) const ;
        constexpr bool operator == (const Range<T>& v) const ;
        constexpr bool operator != (const Range<T>& v) const ;
        constexpr Range<T> operator + (const Range<T>& v) const ;
        constexpr Range<T> operator - (const Range<T>& v) const ;
        constexpr Range<T> operator - () const ;
        static constexpr Range<T> empty();
    };
}



#endif /* Range_hpp */
