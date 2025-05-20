//
//  TypeMap.hpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#ifndef TypeMap_hpp
#define TypeMap_hpp
#include "TypeMap.hpp"
#include <typeindex>
#include <unordered_map>
#include <memory>
#include <stdio.h>

namespace ms {
    class TypeMap {
        public:
        template <typename D, typename...Args>
        D* emplace(Args&& ... args);
        
        template <typename D>
        void erase();
        void clear();
        template <typename D>
        D* get();  
        template <typename D>
        const D* get();

    }

}


#endif /* TypeMap_hpp */
