#pragma once

#include <map>
#include <vector>
#include <string>
#include <stdint.h>


#define JSON_INNER_MAP 0
#define JSON_INNER_LIST 1
#define JSON_INNER_STRING 2


namespace Json {
    class Json {
    private:
        std::map<std::string, Json> inner_map;
        std::vector<Json> inner_list;
        std::string inner_str;

        uint8_t type;
    public:
        uint32_t serialize(const std::string& _ser_dat);
        std::string deserialize() const;

        uint32_t size() const;
        bool empty() const;

        void push_back(const Json& _obj);
        void emplace_back(const std::string& _dat);
        
        Json& operator[](uint32_t _idx);
        Json& operator[](const std::string& _key);

        operator std::string() const { return this->deserialize(); }

        Json() : inner_map({}), inner_list(0), inner_str("") {}
        Json(const std::string& _ser_dat) : inner_map({}), inner_list(0), inner_str("") { this->serialize(_ser_dat); }
    };
}
