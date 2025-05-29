//
//  Lerp.hpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#ifndef Lerp_hpp
#define Lerp_hpp

namespace ms
{
    template <typename T>
    constexpr T lerp(T first, T second, float alpha)
    {
        return alpha <= 0.0f ? first
            : alpha >= 1.0f ? second
            : first == second ? first
            : static_cast<T>((1.0f - alpha) * first + alpha * second);
    }
}

#endif /* Lerp_hpp */
