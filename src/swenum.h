#ifndef SWENUM_H
#define SWENUM_H

#include "iostream"
#include "map"
#include "vector"
#include "string"

#define SET_SW_ENUM_INITVAL(initVal, ...) initVal
#define SW_ENUM(enum_type, ...)\
	class enum_type {\
		public:\
			enum enumType{__VA_ARGS__};\
			enum_type() {}\
			enum_type(const enumType& value) {enumImpl = value;}\
			std::string stringValue() const {return map.at(enumImpl);}\
			static int size() {return map.size();}\
			int valueIndex() const {return enumImpl;}\
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
	}

#include "algorithm"

template<typename enumType>
struct SwEnumValues {
	std::vector<enumType> enumVals;
	std::vector<std::string> stringVals;
};

#define VA_ARGS_TO_STRING(...) #__VA_ARGS__
#define SW_ASSIGN_ENUM(enum_type, ...)\
	class enum_type {\
		public:\
			enum enumType{__VA_ARGS__};\
			enum_type() {}\
			enum_type(const enumType& value) {indexCurrentVal = findIndexByEnumValue(value);}\
			std::string stringValue() const {return swEnumValues.stringVals.at(indexCurrentVal);}\
			static int size() {return swEnumValues.enumVals.size();}\
			int valueIndex() const {return indexCurrentVal;}\
			friend bool operator == (const enum_type& left, const enum_type& right);\
			friend bool operator == (const enum_type& left, const enumType& rightEnumImpl);\
			friend bool operator == (const enum_type& left, const std::string& string);\
			friend bool operator == (const std::string& string, const enum_type& right);\
			friend bool operator < (const enum_type& left, const enum_type& right);\
			friend bool operator < (const enum_type& left, const enumType& rightEnumImpl);\
			friend bool operator <= (const enum_type& left, const enum_type& right);\
			friend bool operator <= (const enum_type& left, const enumType& rightEnumImpl);\
			friend std::ostream& operator << (std::ostream& stream, const enum_type& right);\
			operator int() const {return swEnumValues.enumVals.at(indexCurrentVal);}\
			enum_type& operator = (const enum_type& right) {indexCurrentVal = right.indexCurrentVal; return *this;}\
			enum_type& operator = (const enumType& rightEnumImpl) {indexCurrentVal = findIndexByEnumValue(rightEnumImpl); return *this;}\
			enum_type& operator ++ ();\
			enum_type operator ++ (int);\
			enum_type& operator -- ();\
			enum_type operator -- (int);\
		private:\
			unsigned int indexCurrentVal = 0;\
			int findIndexByEnumValue(const enumType& value) {\
				int index = indexCurrentVal;\
				for(unsigned int i = 0; i < swEnumValues.enumVals.size(); ++ i) {\
					if(swEnumValues.enumVals[i] == value) {\
						index = i; break;\
					}\
				}\
				return index;\
			}\
			static SwEnumValues<enumType> swEnumValues;\
			static SwEnumValues<enumType> createEnumMap(const char* stringValues) {\
				SwEnumValues<enumType> swEnumValues;\
				std::string values(stringValues);\
				values.erase(std::remove(values.begin(), values.end(), ' '), values.end());\
				std::string strValueToken;\
				size_t start = 0, end = 0, indexAssign = 0;\
				int enumValue = 0;\
				while((end = values.find(',', start)) != std::string::npos) {\
					strValueToken = values.substr(start, end - start);\
					indexAssign = strValueToken.find('=', 0);\
					if(indexAssign != std::string::npos) {\
						swEnumValues.stringVals.push_back(strValueToken.substr(0, indexAssign));\
						enumValue = std::stoi(strValueToken.substr(indexAssign + 1));\
					}else {\
						swEnumValues.stringVals.push_back(strValueToken);\
					}\
					swEnumValues.enumVals.push_back(static_cast<enumType>(enumValue));\
					++ enumValue;\
					start = end + 1;\
				}\
				strValueToken = values.substr(start);\
				indexAssign = strValueToken.find('=', 0);\
				if(indexAssign != std::string::npos) {\
					swEnumValues.stringVals.push_back(strValueToken.substr(0, indexAssign));\
					enumValue = std::stoi(strValueToken.substr(indexAssign + 1));\
				}else {\
					swEnumValues.stringVals.push_back(strValueToken);\
				}\
				swEnumValues.enumVals.push_back(static_cast<enumType>(enumValue));\
				return swEnumValues;\
			}\
	};\
	SwEnumValues<enum_type::enumType> enum_type::swEnumValues = createEnumMap(VA_ARGS_TO_STRING(__VA_ARGS__));\
	bool operator == (const enum_type& left, const enum_type& right) {return left.indexCurrentVal == right.indexCurrentVal;}\
	bool operator == (const enum_type& left, const enum_type::enumType& rightEnumImpl) {return enum_type::swEnumValues.enumVals[left.indexCurrentVal] == rightEnumImpl;}\
	bool operator == (const enum_type& left, const std::string& string) {return left.stringValue() == string;};\
	bool operator == (const std::string& string, const enum_type& right) {return right.stringValue() == string;};\
	bool operator < (const enum_type& left, const enum_type& right) {return enum_type::swEnumValues.enumVals[left.indexCurrentVal] < enum_type::swEnumValues.enumVals[right.indexCurrentVal];}\
	bool operator < (const enum_type& left, const enum_type::enumType& rightEnumImpl) {return enum_type::swEnumValues.enumVals[left.indexCurrentVal] < rightEnumImpl;};\
	bool operator <= (const enum_type& left, const enum_type& right) {return enum_type::swEnumValues.enumVals[left.indexCurrentVal] <= enum_type::swEnumValues.enumVals[right.indexCurrentVal];}\
	bool operator <= (const enum_type& left, const enum_type::enumType& rightEnumImpl) {return enum_type::swEnumValues.enumVals[left.indexCurrentVal] <= rightEnumImpl;};\
	std::ostream& operator << (std::ostream& stream, const enum_type& right) {stream << right.stringValue(); return stream;}\
	enum_type& enum_type::operator ++ () {\
		if(indexCurrentVal + 1 < enum_type::swEnumValues.enumVals.size())\
			++ indexCurrentVal;\
		return *this;\
	}\
	enum_type enum_type::operator ++ (int) {\
		enum_type temp = *this;\
		++ *this;\
		return temp;\
	}\
	enum_type& enum_type::operator -- () {\
		if(indexCurrentVal > 0)\
			-- indexCurrentVal;\
		return *this;\
	}\
	enum_type enum_type::operator -- (int) {\
		enum_type temp = *this;\
		-- *this;\
		return temp;\
	}

#endif // SWENUM_H
