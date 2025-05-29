//
//  Optional.hpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#ifndef Optional_hpp
#define Optional_hpp

#include <functional>
#include <type_traits>

namespace ms
{
    template <typename T>
    class Optional
    {
    public:
        template <typename R, typename = std::enable_if_t<std::is_base_of<R, T>::value || std::is_base_of<T, R>::value>>
        constexpr Optional(R* r_val) : val(static_cast<T*>(r_val)) {}

        template <typename R, typename = std::enable_if_t<std::is_base_of<R, T>::value || std::is_base_of<T, R>::value>>constexpr Optional(Optional<R> r_opt) : Optional(r_opt.get()) {}
        constexpr Optional(T* p) : val(p) {}
        constexpr Optional(T& p) : val(&p) {}
        constexpr Optional() : val(nullptr) {}

        explicit operator bool() const
        {
            return val != nullptr;
        }

        T* get() const
        {
            return val;
        }

        T* operator ->() const
        {
            return val;
        }

        T& operator *() const
        {
            return *val;
        }

    private:
        T* val;
    };
}
#endif /* Optional_hpp */
