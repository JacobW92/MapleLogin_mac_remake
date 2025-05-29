//
//  Misc.hpp
//  Maplestory_login
//
//  Created by Jacob on 5/29/25.
//

#ifndef Misc_hpp
#define Misc_hpp

#include <stdio.h>


#include "../Console.hpp"

#include <cstdint>
#include <string>

namespace ms
{
    namespace string_conversion
    {
        template<typename T>
        inline T or_default(const std::string& str, T def)
        {
            try
            {
                std::int32_t intval = std::stoi(str);
                return static_cast<T>(intval);
            }
            catch (const std::exception& ex)
            {
                Console::get().print(__func__, ex);
                return def;
            }
        }

        template<typename T>
        inline T or_zero(const std::string& str)
        {
            return or_default<T>(str, T(0));
        }
    };

    namespace string_format
    {
        // Format a number string so that each 3 decimal points
        // are seperated by a ',' character.
        void split_number(std::string& input);

        // Prefix an id with zeroes so that it has the minimum specified length.
        std::string extend_id(std::int32_t id, std::size_t length);
    };

    namespace bytecode
    {
        // Check if a bit mask contains the specified value.
        bool compare(std::int32_t mask, std::int32_t value);
    }
}

#endif /* Misc_hpp */
