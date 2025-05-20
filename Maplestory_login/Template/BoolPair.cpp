//
//  BoolPair.cpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#include "BoolPair.hpp"
#include <stdexcept>

namespace ms
{
    template <typename T>
    class BoolPair
    {
    public:
        template <typename...Args>
        BoolPair(Args&& ...argsf, Args&& ...argss) : first(std::forward<Args>(argsf)...), second(std::forward<Args>(argss)...) {}
        BoolPair(T f, T s) : first(f), second(s) {}
        BoolPair() {}

        template <typename...Args>
        void set(bool b, Args&& ...args)
        {
            if (b)
                first = T(std::forward<Args>(args)...);
            else
                second = T(std::forward<Args>(args)...);
        }

        T& operator [](bool b)
        {
            return b ? first : second;
        }

        const T& operator [](bool b) const
        {
            return b ? first : second;
        }

    private:
        T first;
        T second;
    };
}
