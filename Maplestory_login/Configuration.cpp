//
//  Configuration.cpp
//  Maplestory_login
//
//  Created by Jacob on 5/20/25.
//

#include "Configuration.hpp"


namespace ms
{
        // IP Address which the client will connect to.
    struct ServerIP : public Configuration::StringEntry
    {
        ServerIP() : StringEntry("ServerIP", "127.0.0.1") {}
    };

    // Port which the client will connect to.
    struct ServerPort : public Configuration::StringEntry
    {
        ServerPort() : StringEntry("ServerPort", "8484") {}
    };

    // Whether to start in fullscreen mode.
    struct Fullscreen : public Configuration::BoolEntry
    {
        Fullscreen() : BoolEntry("Fullscreen", "false") {}
    };

    // The width of the screen
    struct Width : public Configuration::ShortEntry
    {
        Width() : ShortEntry("Width", "800") {}
    };

    // The height of the screen
    struct Height : public Configuration::ShortEntry
    {
        Height() : ShortEntry("Height", "600") {}
    };

    // Whether to use VSync.
    struct VSync : public Configuration::BoolEntry
    {
        VSync() : BoolEntry("VSync", "true") {}
    };

    // The normal font which will be used.
    struct FontPathNormal : public Configuration::StringEntry
    {
        FontPathNormal() : StringEntry("FontPathNormal", "fonts/Roboto/Roboto-Regular.ttf") {}
    };

    // The bold font which will be used.
    struct FontPathBold : public Configuration::StringEntry
    {
        FontPathBold() : StringEntry("FontPathBold", "fonts/Roboto/Roboto-Bold.ttf") {}
    };

    // Music Volume, a number from 0 to 100.
    struct BGMVolume : public Configuration::ByteEntry
    {
        BGMVolume() : ByteEntry("BGMVolume", "50") {}
    };

    // Sound Volume, a number from 0 to 100.
    struct SFXVolume : public Configuration::ByteEntry
    {
        SFXVolume() : ByteEntry("SFXVolume", "50") {}
    };

    // Whether to save the last used account name.
    struct SaveLogin : public Configuration::BoolEntry
    {
        SaveLogin() : BoolEntry("SaveLogin", "false") {}
    };

    // The last used account name.
    struct DefaultAccount : public Configuration::StringEntry
    {
        DefaultAccount() : StringEntry("Account", "") {}
    };

    // The last used world.
    struct DefaultWorld : public Configuration::ByteEntry
    {
        DefaultWorld() : ByteEntry("World", "0") {}
    };

    // The last used channel.
    struct DefaultChannel : public Configuration::ByteEntry
    {
        DefaultChannel() : ByteEntry("Channel", "0") {}
    };

    // The last used character.
    struct DefaultCharacter : public Configuration::ByteEntry
    {
        DefaultCharacter() : ByteEntry("Character", "0") {}
    };

    // Whether to show the chatbar.
    struct Chatopen : public Configuration::BoolEntry
    {
        Chatopen() : BoolEntry("Chatopen", "false") {}
    };

    // The default position of the character stats inventory.
    struct PosSTATS : public Configuration::PointEntry
    {
        PosSTATS() : PointEntry("PosSTATS", "(72,62)") {}
    };

    // The default position of the equipment inventory.
    struct PosEQINV : public Configuration::PointEntry
    {
        PosEQINV() : PointEntry("PosEQINV", "(250,150)") {}
    };

    // The default position of the item inventory.
    struct PosINV : public Configuration::PointEntry
    {
        PosINV() : PointEntry("PosINV", "(300,150)") {}
    };

    // The default position of the skill inventory.
    struct PosSKILL : public Configuration::PointEntry
    {
        PosSKILL() : PointEntry("PosSKILL", "(96,86)") {}
    };

    // The default position of the quest log.
    struct PosQUEST : public Configuration::PointEntry
    {
        PosQUEST() : PointEntry("PosQUEST", "(300,150)") {}
    };

    // The default position of the world map.
    struct PosMAP : public Configuration::PointEntry
    {
        PosMAP() : PointEntry("PosMAP", "(100,25)") {}
    };

    // The default position of the userlist features.
    struct PosUSERLIST : public Configuration::PointEntry
    {
        PosUSERLIST() : PointEntry("PosUSERLIST", "(104, 94)") {}
    };

    // The default position of the chatbar.
    struct PosCHAT : public Configuration::PointEntry
    {
        PosCHAT() : PointEntry("PosCHAT", "(0, 562)") {}
    };

    // The default position of the mini map.
    struct PosMINIMAP : public Configuration::PointEntry
    {
        PosMINIMAP() : PointEntry("PosMINIMAP", "(0, 0)") {}
    };

    // The default position of shops.
    struct PosSHOP : public Configuration::PointEntry
    {
        PosSHOP() : PointEntry("PosSHOP", "(146, 38)") {}
    };

    // The default position of the notice windows.
    struct PosNOTICE : public Configuration::PointEntry
    {
        PosNOTICE() : PointEntry("PosNOTICE", "(400, 275)") {}
    };

    // The default position of the maple chat.
    struct PosMAPLECHAT : public Configuration::PointEntry
    {
        PosMAPLECHAT() : PointEntry("PosMAPLECHAT", "(50, 36)") {}
    };

    // The default position of the channel change.
    struct PosCHANNEL : public Configuration::PointEntry
    {
        PosCHANNEL() : PointEntry("PosCHANNEL", "(215, 90)") {}
    };

    // The default position of the joypad.
    struct PosJOYPAD : public Configuration::PointEntry
    {
        PosJOYPAD() : PointEntry("PosJOYPAD", "(312, 124)") {}
    };

    // The default position of the event list.
    struct PosEVENT : public Configuration::PointEntry
    {
        PosEVENT() : PointEntry("PosEVENT", "(99, 90)") {}
    };

    // The default position of the key bindings.
    struct PosKEYCONFIG : public Configuration::PointEntry
    {
        PosKEYCONFIG() : PointEntry("PosKEYCONFIG", "(65, 40)") {}
    };

    // The default position of the option menu.
    struct PosOPTIONMENU : public Configuration::PointEntry
    {
        PosOPTIONMENU() : PointEntry("PosUSERLIST", "(170, -11)") {}
    };

    template <typename T>
    // Can be used to access settings.
    struct Setting
    {
        // Access a setting.
        static T& get()
        {
            static_assert(std::is_base_of<Configuration::Entry, T>::value, "template parameter T for Setting must inherit from Configuration::Entry.");

            auto* entry = Configuration::get().settings.get<T>();

            if (entry)
            {
                return *entry;
            }
            else
            {
                static T defaultentry;
                return defaultentry;
            }
        }
    };
}
