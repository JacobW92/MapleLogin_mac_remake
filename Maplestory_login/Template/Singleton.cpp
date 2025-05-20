//
//  Singleton.cpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#include "Singleton.hpp"


namespace ms {

    template <class T>
    class Singleton
    {
    public:
        virtual ~Singleton() {}
        
        static T& get() {
            return instance;
        }
        
    private:
        T& operator = (const T&) = delete;
        
        static T instance;
    };
}

