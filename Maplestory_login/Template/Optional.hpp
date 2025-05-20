//
//  Optional.hpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#ifndef Optional_hpp
#define Optional_hpp

#include <stdio.h>
#include <functional>
#include <type_traits>

namespace ms {

    template <typename T>
    class Optional {
        explicit operator bool() const ;
        T* get() const ;
        T* operator ->() const ;
        T& operator *() const ;
    };
}


#endif /* Optional_hpp */
