//
//  Lerp.cpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#include "Lerp.hpp"

namespace ms {
    
    template <typename T>
    
constexpr T lerp(T fir, T sec, float alpha) {
    return alpha <= 0.0f ? fir : alpha >= 1.0f ? sec :fir == sec? fir : static_cast<T>((1.0f-alpha) * fir + alpha * sec);
}

}
