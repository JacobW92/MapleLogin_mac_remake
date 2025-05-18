//
//  TypeMap.hpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#ifndef TypeMap_hpp
#define TypeMap_hpp

#include <stdio.h>
#include <typeindex>
#include <unordered_map>
#include <memory>

namespace ms {

    template <typename T>
    class TypeMap{
    public:
        using t_ptr = typename std::unique_ptr<T>;
        using pair = typename std::pair<std::type_index, t_ptr>;
        using cpair = typename std::pair<const std::type_index, t_ptr>;
        using underlying_map = typename std::unordered_map<std::type_index, t_ptr>;
        
        
        
    private:
        underlying_map container;
    };
}

#endif /* TypeMap_hpp */
