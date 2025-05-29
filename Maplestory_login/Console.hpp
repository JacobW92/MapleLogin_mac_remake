//
//  Console.hpp
//  Maplestory_login
//
//  Created by Jacob on 5/29/25.
//

#ifndef Console_hpp
#define Console_hpp

#include "Maplestory.h"

#include "Template/Singleton.hpp"

#include <unordered_set>
#include <string>
#include <iostream>

namespace ms
{
#ifndef PRINT_WARNINGS
    class Console : public Singleton<Console>
    {
    public:
        void print(const char*, const std::string&) {}
        void print(const char*, const std::exception&) {}
        void print(const std::string&) {}
    };
#else
    class Console : public Singleton<Console>
    {
    public:
        void print(const char* func, const std::string& msg)
        {
            static const std::string delim = ", ";
            print(func + delim + msg);
        }

        void print(const char* func, const std::exception& ex)
        {
            print(func, { ex.what() });
        }

        void print(const std::string& str)
        {
            if (!printed.count(str))
            {
                std::cout << str << std::endl;
                printed.insert(str);
            }
        }

    private:
        std::unordered_set<std::string> printed;
    };
#endif
}


#endif /* Console_hpp */
