//
//  TimedQueue.cpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#include "TimedQueue.hpp"

#include "../Constants.hpp"
#include <queue>
#include <functional>
#include <cstdint>

namespace ms {
    
    template <typename T>
    class TimedQueue {
    public:
        
        
    private:
        struct Timed {
            T value;
            int64_t when;
            
            Timed(int64_t w, const T& v): when {w}, value(v){}
            template <typename...Args>
            Timed(int64_t w, Args&& ...args):when {w}, value{std::forward<Args>(args)...} {}
            
        };
        
        struct TimedComparator {
            bool operator ()(const Timed& a, const Timed& b) const {
                return a.when > b.when;
            }
        };
        
        std::priority_queue<Timed, std::vector<Timed>, TimedComparator> queue;
        std::function<void(const T&)> action;
        int64_t time;
    };
    
}

