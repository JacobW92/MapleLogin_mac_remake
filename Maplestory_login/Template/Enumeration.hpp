//
//  Enumeration.hpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#ifndef Enumeration_hpp
#define Enumeration_hpp


#include <type_traits>
#include <array>

namespace ms
{
    template <typename E, E LENGTH = E::LENGTH>
    // Makes contiguous enums iterable.
    class Enumeration
    {
    public:
        using underlying_t = typename std::array<E, LENGTH>;

        template <std::size_t... VS>
    constexpr Enumeration(std::index_sequence<VS...>) noexcept
        : values{{static_cast<E>(VS)...}}
    {
    }

        constexpr Enumeration() : Enumeration(std::make_index_sequence<LENGTH>{})
        {
            static_assert(std::is_enum<E>::value, "Template parameter E for Enumeration must be an enum.");
        }

        auto begin() const
        {
            return values.begin();
        }

        auto end() const
        {
            return values.end();
        }

        auto cbegin() const
        {
            return values.cbegin();
        }

        auto cend() const
        {
            return values.cend();
        }

    private:
        underlying_t values;
    };
}

#endif /* Enumeration_hpp */
