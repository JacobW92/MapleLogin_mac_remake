//
//  Interpolated.cpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#include "Interpolated.hpp"
#include "../Util/Lerp.hpp"

namespace ms {

    template <typename T>
    class Nominal {
    public:
        constexpr Nominal() : now(T()), before(T()), threshold(0.0f) {}

        T get() const
        {
            return now;
        }

        T get(float alpha) const
        {
            return alpha >= threshold ? now : before;
        }

        T last() const
        {
            return before;
        }

        void set(T value)
        {
            now = value;
            before = value;
        }

        void normalize()
        {
            before = now;
        }

        bool normalized() const
        {
            return before == now;
        }

        void next(T value, float thrs)
        {
            before = now;
            now = value;
            threshold = thrs;
        }

        bool operator == (T value) const
        {
            return now == value;
        }

        bool operator != (T value) const
        {
            return now != value;
        }

        T operator + (T value) const
        {
            return now + value;
        }

        T operator - (T value) const
        {
            return now - value;
        }

        T operator * (T value) const
        {
            return now * value;
        }

        T operator / (T value) const
        {
            return now / value;
        }

    private:
        T now;
        T before;
        float threshold;
    };

    template <typename T>
    class Linear
    {
    public:
        T get() const
        {
            return now;
        }
        
        T get(float alpha) const
        {
            return lerp<T>(before, now, alpha);
        }
        
        T last() const
        {
            return before;
        }
        
        void set(T value)
        {
            now = value;
            before = value;
        }
        
        void normalize()
        {
            before = now;
        }
        
        bool normalized() const
        {
            return before == now;
        }
        
        void operator = (T value)
        {
            before = now;
            now = value;
        }
        
        void operator += (T value)
        {
            before = now;
            now += value;
        }
        
        void operator -= (T value)
        {
            before = now;
            now -= value;
        }
        
        bool operator == (T value) const
        {
            return now == value;
        }
        
        bool operator != (T value) const
        {
            return now != value;
        }
        
        bool operator < (T value) const
        {
            return now < value;
        }
        
        bool operator <= (T value) const
        {
            return now <= value;
        }
        
        bool operator > (T value) const
        {
            return now > value;
        }
        
        bool operator >= (T value) const
        {
            return now >= value;
        }
        
        T operator + (T value) const
        {
            return now + value;
        }
        
        T operator - (T value) const
        {
            return now - value;
        }
        
        T operator * (T value) const
        {
            return now * value;
        }
        
        T operator / (T value) const
        {
            return now / value;
        }
        
        T operator + (Linear<T> value) const
        {
            return now + value.get();
        }
        
        T operator - (Linear<T> value) const
        {
            return now - value.get();
        }
        
        T operator * (Linear<T> value) const
        {
            return now * value.get();
        }
        
        T operator / (Linear<T> value) const
        {
            return now / value.get();
        }
        
    private:
        T now;
        T before;
    };

}


