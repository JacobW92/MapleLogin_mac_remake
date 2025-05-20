//
//  EnumMap.hpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#ifndef EnumMap_hpp
#define EnumMap_hpp

#include "EnumMap.hpp"
#include <type_traits>
#include <utility>
#include <array>
#include <stdio.h>

namespace ms {

    template <typename K, typename V, K LENGTH = K::LENGTH>
    // Wraps an array so that it is addressable by enum values.
    class EnumMap {
    public:
        void clear();
        void erase(K key);
        template <typename...Args> 
        void emplace(K key, Args&& ...args);
        V& operator [](K key);
        const V& operator[](K key) const;
        template <typename T>
        

    };

}

#endif /* EnumMap_hpp */
