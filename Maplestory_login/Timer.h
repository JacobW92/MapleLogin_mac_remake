//
//  Timer.h
//  Maplestory_login
//
//  Created by Jacob on 5/29/25.
//

#ifndef Timer_h
#define Timer_h

#include "Template/Singleton.h"
#include <cstdint>
#include <chrono>

namespace ms {

    class Timer : public Singleton<Timer> {
    public:
        Timer() {
            start();
        }
        ~Timer() {}
        
        void start() {
            
        }
    private:
    }


#endif /* Timer_h */
