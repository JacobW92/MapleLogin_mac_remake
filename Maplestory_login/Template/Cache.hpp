//
//  Cache.hpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#ifndef Cache_hpp
#define Cache_hpp


#include <unordered_map>
#include <cstdint>

namespace ms
{
    template <typename T>
    // Template for a cache of game objects
    // which can be constructed from an identifier.
    // The 'get' factory method is static.
    class Cache
    {
    public:
        virtual ~Cache() {}

        // Return a ref to the game object with the specified id.
        // If the object is not in cache, it is created.
        static const T& get(std::int32_t id)
        {
            auto iter = cache.find(id);

            if (iter == cache.end())
                iter = cache.emplace(id, T{ id }).first;

            return iter->second;
        }

    private:
        static std::unordered_map<std::int32_t, T> cache;
    };

    template <typename T>
    std::unordered_map<std::int32_t, T> Cache<T>::cache;
}

#endif /* Cache_hpp */
