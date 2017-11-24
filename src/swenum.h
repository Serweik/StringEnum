#ifndef SWENUM_H
#define SWENUM_H

#include "iostream"
#include "map"
#include "vector"
#include "string"

#define SET_SW_ENUM_INITVAL(initVal, ...) initVal
#define DECLARE_SW_ENUM(enum_type, ...)\
	class enum_type {\
		public:\
			enum enumType{__VA_ARGS__};\
			enum_type() {}\
			enum_type(const enumType& value) {enumImpl = value;}\
			std::string stringValue() const {return map.at(enumImpl);}\
			static int size() {return map.size();}\
			friend bool operator == (const enum_type& left, const enum_type& right);\
			friend bool operator == (const enum_type& left, const enumType& rightEnumImpl);\
			friend bool operator == (const enum_type& left, const std::string& string);\
			friend bool operator == (const std::string& string, const enum_type& right);\
			friend bool operator < (const enum_type& left, const enum_type& right);\
			friend bool operator < (const enum_type& left, const enumType& rightEnumImpl);\
			friend bool operator <= (const enum_type& left, const enum_type& right);\
			friend bool operator <= (const enum_type& left, const enumType& rightEnumImpl);\
			friend std::ostream& operator << (std::ostream& stream, const enum_type& right);\
			operator int() const {return enumImpl;}\
			enum_type& operator = (const enum_type& right) {enumImpl = right.enumImpl; return *this;}\
			enum_type& operator = (const enumType& rightEnumImpl) {enumImpl = rightEnumImpl; return *this;}\
			enum_type& operator ++ ();\
			enum_type operator ++ (int);\
			enum_type& operator -- ();\
			enum_type operator -- (int);\
		private:\
			enumType enumImpl = SET_SW_ENUM_INITVAL(__VA_ARGS__);\
			static std::map<enumType, std::string> map;\
			template<typename... VALUES>\
			static std::map<enumType, std::string> createEnumMap(const char* stringValues, VALUES... values) {\
				std::vector<enumType> keys{values...};\
				std::vector<std::string> vals = parseEnumStringValues(stringValues);\
				auto itKeys = keys.cbegin();\
				auto itVals = vals.cbegin();\
				std::map<enumType, std::string> map;\
				for (; itKeys != keys.cend(); ++ itKeys, ++ itVals) {\
					map.emplace(*itKeys, *itVals);\
				}\
				return map;\
			}\
			static std::vector<std::string> parseEnumStringValues(const std::string &stringValues) {\
				std::vector<std::string> vals;\
				size_t start = 0, end = 0;\
				while((end = stringValues.find(',', start)) != std::string::npos) {\
					vals.push_back(stringValues.substr(start, end - start));\
					start = end + 2;\
				}\
				vals.push_back(stringValues.substr(start));\
				return vals;\
			}\
	};\
	std::map<enum_type::enumType, std::string> enum_type::map = createEnumMap(#__VA_ARGS__, __VA_ARGS__);\
	bool operator == (const enum_type& left, const enum_type& right) {return left.enumImpl == right.enumImpl;}\
	bool operator == (const enum_type& left, const enum_type::enumType& rightEnumImpl) {return left.enumImpl == rightEnumImpl;}\
	bool operator == (const enum_type& left, const std::string& string) {return left.stringValue() == string;};\
	bool operator == (const std::string& string, const enum_type& right) {return right.stringValue() == string;};\
	bool operator < (const enum_type& left, const enum_type& right) {return left.enumImpl < right.enumImpl;}\
	bool operator < (const enum_type& left, const enum_type::enumType& rightEnumImpl) {return left.enumImpl < rightEnumImpl;};\
	bool operator <= (const enum_type& left, const enum_type& right) {return left.enumImpl <= right.enumImpl;}\
	bool operator <= (const enum_type& left, const enum_type::enumType& rightEnumImpl) {return left.enumImpl <= rightEnumImpl;};\
	std::ostream& operator << (std::ostream& stream, const enum_type& right) {stream << right.stringValue(); return stream;}\
	enum_type& enum_type::operator ++ () {\
		auto it = map.find(enumImpl);\
		++it;\
		if(it != map.end())\
			enumImpl = it->first;\
		return *this;\
	}\
	enum_type enum_type::operator ++ (int) {\
		enum_type temp = *this;\
		++ *this;\
		return temp;\
	}\
	enum_type& enum_type::operator -- () {\
		auto it = map.find(enumImpl);\
		if(it != map.begin())\
			--it;\
			enumImpl = it->first;\
		return *this;\
	}\
	enum_type enum_type::operator -- (int) {\
		enum_type temp = *this;\
		-- *this;\
		return temp;\
	}\

#endif // SWENUM_H
