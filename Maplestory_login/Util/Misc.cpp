//
//  Misc.cpp
//  Maplestory_login
//
//  Created by Jacob on 5/29/25.
//

#include "Misc.hpp"


namespace ms
{
    namespace string_format
    {
        void split_number(std::string& input)
        {
            for (std::size_t i = input.size(); i > 3; i -= 3)
                input.insert(i - 3, 1, ',');
        }

        std::string extend_id(std::int32_t id, std::size_t length)
        {
            std::string strid = std::to_string(id);

            if (strid.size() < length)
                strid.insert(0, length - strid.size(), '0');

            return strid;
        }
    }

    namespace bytecode
    {
        bool compare(std::int32_t mask, std::int32_t value)
        {
            return (mask & value) != 0;
        }
    }
}
