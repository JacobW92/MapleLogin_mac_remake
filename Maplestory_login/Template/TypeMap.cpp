//
//  TypeMap.cpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#include "TypeMap.hpp"
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
        
        template <typename  D, typename...Args>
        D* emplace(Args&& ... args) {
            auto* ptr = container.emplace(typeid(D), std::make_unique<D>(args...)).first->second.get();
            return static_cast<D*>(ptr);
        }
        
        template <typename D>
        void erase() {
            container.erase(typeid(D));
        }
        
        void clear() {
            container.clear();
        }
        
        template <typename D>
        D* get() {
            return static_cast<D*>(container[typeid(D)].get());
        }
        
        template <typename D>
        const D* get() {
            return static_cast<D*>(container[typeid(D)].get());
        }
        
        typename underlying_map::iterator begin() {
            return container.begin();
        }
        
        typename underlying_map::iterator end() {
            return container.end();
        }
        
        typename underlying_map::const_iterator begin() const {
            return container.begin();
        }
        
        typename underlying_map::const_iterator end() const {
            return container.end();
        }
        
        
    private:
        underlying_map container;
    };
}


