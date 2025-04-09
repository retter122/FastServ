#pragma once

#include <map>
#include <vector>
#include <string>
#include <stdint.h>


namespace Json {
    enum class JsonType { JSON_STRING, JSON_NONE, JSON_MAP, JSON_LIST };


    class Json {
    private:
        std::map<std::string, Json> inner_map;
        std::vector<Json> inner_list;
        std::string inner_str;

        JsonType type;
    public:
        uint32_t serialize(const std::string& _ser_dat);
        std::string deserialize() const;

        uint32_t size() const;
        bool empty() const;
        JsonType get_type() const;

        void push_back(const Json& _obj);

        void emplace_back(const std::string& _dat);
        void emplace_back(const std::vector<Json>& _dat);
        void emplace_back(const std::map<std::string, Json>& _dat);

        void emplace(const std::string& _key, const Json& _val);

        std::string get_inner_as_str() const;
        std::vector<Json> get_inner_as_vector() const;
        std::map<std::string, Json> get_inner_as_map() const;
        
        Json& operator[](uint32_t _idx);
        Json& operator[](const std::string& _key);

        operator std::string() const { return this->get_inner_as_str(); }

        Json() : type(JsonType::JSON_NONE), inner_map({}), inner_list(0), inner_str("") {}

        Json(const std::string& _ser_dat) : type(JsonType::JSON_STRING), inner_map({}), inner_list(0), inner_str(_ser_dat) {}
        Json(const std::vector<Json>& _ser_vec) : type(JsonType::JSON_LIST), inner_map({}), inner_list(_ser_vec), inner_str("") {}
        Json(const std::map<std::string, Json>& _ser_map) : type(JsonType::JSON_MAP), inner_map(_ser_map), inner_list(0), inner_str("") {}
    };
}
