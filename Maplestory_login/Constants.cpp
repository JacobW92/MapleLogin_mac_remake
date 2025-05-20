//
//  Constants.cpp
//  Maplestory_login
//
//  Created by Jacob on 5/19/25.
//

#include "Constants.hpp"

namespace ms {
    
    namespace Constants {
        
        constexpr std::uint16_t TIMESTEP = 8;
        constexpr std::int16_t VIEWOFFSET = 10;
        template <typename T>
        class Constants : public Singleton<Constants<T> > {
        public:
            Constants()
            {
                VIEWWIDTH = 800;
                VIEWHEIGHT = 600;
            }
            
            ~Constants() {}
            
            std::int16_t get_viewwidth()
            {
                return VIEWWIDTH;
            }
            
            void set_viewwidth(std::int16_t width)
            {
                VIEWWIDTH = width;
            }
            
            std::int16_t get_viewheight()
            {
                return VIEWHEIGHT;
            }
            
            void set_viewheight(std::int16_t height)
            {
                VIEWHEIGHT = height;
            }
            
        private:
            // Window and screen width.
            std::int16_t VIEWWIDTH;
            // Window and screen height.
            std::int16_t VIEWHEIGHT;
        };
    }


}



