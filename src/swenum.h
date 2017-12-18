#ifndef SWENUM_H
#define SWENUM_H

#include "iosfwd"
#include "string"

template <typename EnumType>
struct SwEnumDeleteAssign {
	explicit constexpr SwEnumDeleteAssign(EnumType value): _value(value)	{}

	template <typename Any>
	constexpr const SwEnumDeleteAssign& operator = (Any) const {return *this;}
	constexpr operator EnumType() const {return _value;}

	private:
		EnumType _value;
};

#define SW_ENUM_NO_CHANGE(...) __VA_ARGS__
#define SW_ENUM_GLUT_ID(name, count) name##count
#define SW_ENUM__CALL_MACROS(macros, ...) macros(__VA_ARGS__)

#define SW_ENUM_DEL_ASSIGN_1(value)(SwEnumDeleteAssign<enumType>)value
#define SW_ENUM_DEL_ASSIGN_2(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_1(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_3(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_2(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_4(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_3(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_5(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_4(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_6(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_5(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_7(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_6(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_8(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_4(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_9(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_8(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_10(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_9(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_11(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_10(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_12(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_11(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_13(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_12(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_14(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_13(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_15(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_14(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_16(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_15(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_17(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_16(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_18(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_17(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_19(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_18(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_20(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_19(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_21(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_20(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_22(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_21(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_23(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_22(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_24(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_23(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_25(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_24(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_26(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_25(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_27(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_26(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_28(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_27(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_29(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_28(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_30(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_29(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_31(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_30(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_32(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_31(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_33(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_32(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_34(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_33(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_35(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_34(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_36(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_35(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_37(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_36(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_38(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_37(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_39(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_38(__VA_ARGS__))
#define SW_ENUM_DEL_ASSIGN_40(value, ...) SW_ENUM_NO_CHANGE((SwEnumDeleteAssign<enumType>)value, SW_ENUM_DEL_ASSIGN_39(__VA_ARGS__))

#define SW_ENUM_TO_STRING_1(value) std::string(#value, toStringWithoutAssign(#value, 0))
#define SW_ENUM_TO_STRING_2(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_1(__VA_ARGS__))
#define SW_ENUM_TO_STRING_3(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_2(__VA_ARGS__))
#define SW_ENUM_TO_STRING_4(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_3(__VA_ARGS__))
#define SW_ENUM_TO_STRING_5(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_4(__VA_ARGS__))
#define SW_ENUM_TO_STRING_6(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_5(__VA_ARGS__))
#define SW_ENUM_TO_STRING_7(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_6(__VA_ARGS__))
#define SW_ENUM_TO_STRING_8(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_4(__VA_ARGS__))
#define SW_ENUM_TO_STRING_9(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_8(__VA_ARGS__))
#define SW_ENUM_TO_STRING_10(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_9(__VA_ARGS__))
#define SW_ENUM_TO_STRING_11(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_10(__VA_ARGS__))
#define SW_ENUM_TO_STRING_12(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_11(__VA_ARGS__))
#define SW_ENUM_TO_STRING_13(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_12(__VA_ARGS__))
#define SW_ENUM_TO_STRING_14(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_13(__VA_ARGS__))
#define SW_ENUM_TO_STRING_15(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_14(__VA_ARGS__))
#define SW_ENUM_TO_STRING_16(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_15(__VA_ARGS__))
#define SW_ENUM_TO_STRING_17(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_16(__VA_ARGS__))
#define SW_ENUM_TO_STRING_18(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_17(__VA_ARGS__))
#define SW_ENUM_TO_STRING_19(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_18(__VA_ARGS__))
#define SW_ENUM_TO_STRING_20(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_19(__VA_ARGS__))
#define SW_ENUM_TO_STRING_21(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_20(__VA_ARGS__))
#define SW_ENUM_TO_STRING_22(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_21(__VA_ARGS__))
#define SW_ENUM_TO_STRING_23(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_22(__VA_ARGS__))
#define SW_ENUM_TO_STRING_24(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_23(__VA_ARGS__))
#define SW_ENUM_TO_STRING_25(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_24(__VA_ARGS__))
#define SW_ENUM_TO_STRING_26(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_25(__VA_ARGS__))
#define SW_ENUM_TO_STRING_27(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_26(__VA_ARGS__))
#define SW_ENUM_TO_STRING_28(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_27(__VA_ARGS__))
#define SW_ENUM_TO_STRING_29(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_28(__VA_ARGS__))
#define SW_ENUM_TO_STRING_30(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_29(__VA_ARGS__))
#define SW_ENUM_TO_STRING_31(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_30(__VA_ARGS__))
#define SW_ENUM_TO_STRING_32(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_31(__VA_ARGS__))
#define SW_ENUM_TO_STRING_33(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_32(__VA_ARGS__))
#define SW_ENUM_TO_STRING_34(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_33(__VA_ARGS__))
#define SW_ENUM_TO_STRING_35(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_34(__VA_ARGS__))
#define SW_ENUM_TO_STRING_36(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_35(__VA_ARGS__))
#define SW_ENUM_TO_STRING_37(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_36(__VA_ARGS__))
#define SW_ENUM_TO_STRING_38(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_37(__VA_ARGS__))
#define SW_ENUM_TO_STRING_39(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_38(__VA_ARGS__))
#define SW_ENUM_TO_STRING_40(value, ...) SW_ENUM_NO_CHANGE(std::string(#value, toStringWithoutAssign(#value, 0)), SW_ENUM_TO_STRING_39(__VA_ARGS__))


#define SW_ENUM_COUNT_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20,\
		_21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, count, ...) count

#define SW_ENUM_COUNT(...) SW_ENUM_NO_CHANGE(SW_ENUM_COUNT_IMPL(__VA_ARGS__, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30,\
		29, 28, 27, 26, 25, 24,	23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))

#define SW_ENUM_CREATE_VALUES(macrosName, ...)	SW_ENUM__CALL_MACROS(SW_ENUM_GLUT_ID, macrosName, SW_ENUM_COUNT(__VA_ARGS__))(__VA_ARGS__)

/*
 *	Enum_type - name of class wrapper for the enum.
 *	typeOfEnumValues - type of values in the enum.
 *	typeOfIndex - type of index field in the class wrapper. Determines how many bytes in sizeof(Enum_type instance object).
 */
#define SW_ENUM(Enum_type, typeOfEnumValues, typeOfIndex, ...)\
	class Enum_type {\
		public:\
			enum enumType : typeOfEnumValues {__VA_ARGS__};\
			Enum_type() {}\
			Enum_type(const enumType& value) {indexCurrentVal = findIndexByEnumValue(value);}\
			const std::string& stringValue() const {return getStringValue(indexCurrentVal);}\
			static typeOfIndex size() {return numberOfValues;}\
			typeOfIndex valueIndex() const {return indexCurrentVal;}\
			friend bool operator == (const Enum_type& left, const Enum_type& right){return left.indexCurrentVal == right.indexCurrentVal;}\
			friend bool operator == (const Enum_type& left, const enumType& rightEnumImpl){return getValue(left.indexCurrentVal) == rightEnumImpl;}\
			friend bool operator == (const Enum_type& left, const std::string& string){return left.stringValue() == string;};\
			friend bool operator == (const std::string& string, const Enum_type& right){return right.stringValue() == string;};\
			friend bool operator < (const Enum_type& left, const Enum_type& right){return getValue(left.indexCurrentVal) < getValue(right.indexCurrentVal);}\
			friend bool operator < (const Enum_type& left, const enumType& rightEnumImpl){return getValue(left.indexCurrentVal) < rightEnumImpl;};\
			friend bool operator <= (const Enum_type& left, const Enum_type& right){return getValue(left.indexCurrentVal) <= getValue(right.indexCurrentVal);}\
			friend bool operator <= (const Enum_type& left, const enumType& rightEnumImpl){return getValue(left.indexCurrentVal) <= rightEnumImpl;};\
			friend std::ostream& operator << (std::ostream& stream, const Enum_type& right){stream << right.stringValue(); return stream;}\
			operator int() const {return getValue(indexCurrentVal);}\
			Enum_type& operator = (const Enum_type& right) {indexCurrentVal = right.indexCurrentVal; return *this;}\
			Enum_type& operator = (const enumType& rightEnumImpl) {indexCurrentVal = findIndexByEnumValue(rightEnumImpl); return *this;}\
			Enum_type& operator ++ (){\
				if(indexCurrentVal + 1 < numberOfValues)\
					++ indexCurrentVal;\
				return *this;\
			}\
			Enum_type operator ++ (int){\
				Enum_type temp = *this;\
				++ *this;\
				return temp;\
			}\
			Enum_type& operator -- (){\
				if(indexCurrentVal > 0)\
					-- indexCurrentVal;\
				return *this;\
			}\
			Enum_type operator -- (int){\
				Enum_type temp = *this;\
				-- *this;\
				return temp;\
			}\
		private:\
			static const typeOfIndex numberOfValues = SW_ENUM_COUNT(__VA_ARGS__);\
			typeOfIndex indexCurrentVal = 0;\
			typeOfIndex findIndexByEnumValue (const enumType& value) const {\
				typeOfIndex index = indexCurrentVal;\
				for(typeOfIndex i = 0; i < numberOfValues; ++ i) {\
					if(getValue(i) == value) {\
						index = i; break;\
					}\
				}\
				return index;\
			}\
			constexpr static unsigned int toStringWithoutAssign(const char* string, unsigned int index) {\
				return string[index] == '\0' ? index :\
					   string[index] == '='  ? index :\
					   string[index] == ' '  ? index :\
					   toStringWithoutAssign(string, index + 1);\
			}\
			static enumType getValue(typeOfIndex index) {\
				static const enumType valuesArray[numberOfValues] = {SW_ENUM_CREATE_VALUES(SW_ENUM_DEL_ASSIGN_, __VA_ARGS__)};\
				return valuesArray[index];\
			}\
			static const std::string& getStringValue(typeOfIndex index) {\
				static const std::string stringValuesArray[numberOfValues] = {SW_ENUM_CREATE_VALUES(SW_ENUM_TO_STRING_, __VA_ARGS__)};\
				return stringValuesArray[index];\
			}\
	};

#endif // SWENUM_H
