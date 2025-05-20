//
//  Interpolated.hpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#ifndef Interpolated_hpp
#define Interpolated_hpp
#include "Interpolated.hpp"
#include "../Util/Lerp.hpp"
#include <stdio.h>

namespace ms {

    template <typename T>
    class Nominal {
        T get() const;
        T get(float alpha) const;
        T last() const;
        void set(T value);
        void normalize();
        bool normalized() const;
        void next(T value, float thrs);
        bool operator == (T value) const;
        bool operator != (T value) const;
        bool operator + (T value) const;
        bool operator - (T value) const;
        bool operator * (T value) const;
        bool operator / (T value) const;
    };


}


#endif /* Interpolated_hpp */
