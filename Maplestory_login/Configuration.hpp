//
//  Configuration.hpp
//  Maplestory_login
//
//  Created by Jacob on 5/20/25.
//

#ifndef Configuration_hpp
#define Configuration_hpp

#include "Template/Point.hpp"
#include "Template/Singleton.hpp"
#include "Template/TypeMap.hpp"

#include <cstdint>
#include <stdio.h>
#include <type_traits>
#include <functional>
namespace ms
{
// Manages the 'Settings' file which contains configurations set by user behaviour.
    template <class T>
    class Configuration : public Singleton<Configuration<T> > {
    public:
        // Add the settings which will be used and load them.
        Configuration();
        // Save.
        ~Configuration();
        
        // Load all settings. If something is missing, set the default value. Can be used for reloading.
        void load();
        // Save the current settings.
        void save() const;
        // Get private member SHOW_FPS
        bool get_show_fps() const;
        // Get private member TITLE
        std::string get_title() const;
        // Get private member VERSION
        std::string get_version() const;
        // Get private member JOINLINK
        std::string get_joinlink() const;
        // Get private member WEBSITE
        std::string get_website() const;
        // Get private member FINDID
        std::string get_findid() const;
        // Get private member FINDPASS
        std::string get_findpass() const;
        // Get private member RESETPIC
        std::string get_resetpic() const;
        // Set private member MACS
        void set_macs(char* macs);
        // Set private member HWID
        void set_hwid(char* hwid, char* volumeSerialNumber);
        // Set private member MAXWIDTH
        void set_max_width(std::int16_t max_width);
        // Set private member MAXHEIGHT
        void set_max_height(std::int16_t max_height);
        // Get private member MACS
        std::string get_macs();
        // Get private member HWID
        std::string get_hwid();
        // Get the Hard Drive Volume Serial Number
        std::string get_vol_serial_num();
        // Get the max width allowed
        std::int16_t get_max_width();
        // Get the max height allowed
        std::int16_t get_max_height();
        // Get the shop's "Right-click to sell item" boolean
        bool get_rightclicksell();
        // Set the shop's "Right-click to sell item" boolean
        void set_rightclicksell(bool value);
        // Whether to show the weekly maple star in Maple Chat
        bool get_show_weekly();
        // Set whether to show the weekly maple star in Maple Chat
        void set_show_weekly(bool value);
        // Whether to show the start screen
        bool get_start_shown();
        // Set whether to show the start screen
        void set_start_shown(bool value);
        // Get the character's selected world
        std::uint8_t get_worldid();
        // Set the character's selected world
        void set_worldid(std::uint8_t id);
        // Get the character's selected channel
        std::uint8_t get_channelid();
        // Set the character's selected channel
        void set_channelid(std::uint8_t id);
        
        // Base class for an entry in the settings file.
        class Entry
        {
        protected:
            Entry(const char* n, const char* v) : name(n), value(v) {}
            
            std::string name;
            std::string value;
            
        private:
            friend class Configuration;
            
            std::string to_string() const
            {
                return name + " = " + value;
            }
        };
        
        // Setting which converts to a bool.
        class BoolEntry : public Entry
        {
        public:
            void save(bool b);
            bool load() const;
            
        protected:
            using Entry::Entry;
        };
        
        // Setting which uses the raw string.
        class StringEntry : public Entry
        {
        public:
            void save(std::string str);
            std::string load() const;
            
        protected:
            using Entry::Entry;
        };
        
        // Setting which converts to a Point<int16_t>.
        class PointEntry : public Entry
        {
        public:
            void save(Point<int16_t> p);
            Point<int16_t> load() const;
            
        protected:
            using Entry::Entry;
        };
        
        // Setting which converts to an integer type.
        template <class T>
        class IntegerEntry : public Entry
        {
        public:
            void save(T num)
            {
                value = std::to_string(num);
            }
            
            T load() const
            {
                return string_conversion::or_zero<T>(value);
            }
            
        protected:
            using Entry::Entry;
        };
        
        // Setting which converts to a byte.
        class ByteEntry : public IntegerEntry<std::uint8_t>
        {
        protected:
            using IntegerEntry::IntegerEntry;
        };
        
        // Setting which converts to a short.
        class ShortEntry : public IntegerEntry<std::uint16_t>
        {
        protected:
            using IntegerEntry::IntegerEntry;
        };
        
        // Setting which converts to an int.
        class IntEntry : public IntegerEntry<std::int32_t>
        {
        protected:
            using IntegerEntry::IntegerEntry;
        };
        
        // Setting which converts to a long.
        class LongEntry : public IntegerEntry<uint64_t>
        {
        protected:
            using IntegerEntry::IntegerEntry;
        };
        
    private:
        template <typename T>
        friend struct Setting;
        
        const char* FILENAME = "Settings";
        const char* TITLE = "MapleStory";
        const char* VERSION = "204.1";
        const char* JOINLINK = "https://www.nexon.com/account/en/create";
        const char* WEBSITE = "http://maplestory.nexon.net/";
        const char* FINDID = "https://www.nexon.com/account/en/login";
        const char* FINDPASS = "https://www.nexon.com/account/en/reset-password";
        const char* RESETPIC = "https://www.nexon.com/account/en/login";
        const bool SHOW_FPS = false;
        bool rightclicksell = false;
        bool show_weekly = true;
        bool start_shown = false;
        std::string MACS;
        std::string HWID;
        std::int16_t MAXWIDTH;
        std::int16_t MAXHEIGHT;
        std::string VolumeSerialNumber;
        std::uint8_t worldid;
        std::uint8_t channelid;
        TypeMap<Entry> settings;
    };
}

#endif /* Configuration_hpp */
