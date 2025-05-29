//
//  Singleton.hpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#ifndef Singleton_hpp
#define Singleton_hpp

namespace ms
{
    template <class T>
    class Singleton
    {
    public:
        virtual ~Singleton() {}

        static T& get()
        {
            return instance;
        }

    private:
        T& operator = (const T&) = delete;

        static T instance;
    };

    template <class T>
    T Singleton<T>::instance;
}

#endif /* Singleton_hpp */
