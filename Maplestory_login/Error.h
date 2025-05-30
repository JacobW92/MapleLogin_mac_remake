//
//  Error.h
//  Maplestory_login
//
//  Created by Jacob on 5/29/25.
//

#ifndef Error_h
#define Error_h

namespace ms {

    class Error {
    public:
        enum Code {
            NONE,
            CONNECTION,
            NLNX,
            MISSING_FILE,
            WRONG_UI_FILE,
            GLFW,
            GLEW,
            FREETYPE,
            VERTEX_SHADER,
            FRAGMENT_SHADER,
            SHADER_PROGRAM,
            SHADER_VARS,
            WINDOW,
            AUDIO,
            MISSSING_ICON,
            LENGTH
        };
        
        constexpr Error(Code c) : Error(c, "") {}
        constexpr Error(Code c, const char* args) : code(c), args(args) {}
        
        
    private:
        Code code;
        const char* args;
        static constexpr const char* messages[Code::Length] = {
            "",
            "The server seems to be offline. Please start the server and enter 'retry'.",
            "Could not initialize nlnx. Message: ",
            "Missing a game file: ",
            "UI.nx has wrong version.",
            "Could not initialize glfw.",
            "Could not initialize glew.",
            "Could not initialize freetype.",
            "Failed to create vertex shader.",
            "Failed to create fragment shader.",
            "Failed to create shader program.",
            "Failed to locate shader variables.",
            "Failed to create window.",
            "Failed to initialize audio",
            "Could not load icon. Message: "
        };
    }

}

#endif /* Error_h */
