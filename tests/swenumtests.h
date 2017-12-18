#ifndef SWENUMTESTS_H
#define SWENUMTESTS_H

#include "src/swenum.h"
#include "cassert"

SW_ENUM(
	TestEnum, signed char, char,
	ZERO = 100,
	ONE,
	TWO = 2,
	THREE = -3
)
int ARRAY_FOR_TESTS[4] = {100, 101, 2, -3};
std::string STRING_ARRAY_FOR_TESTS[4] = {"ZERO", "ONE", "TWO", "THREE"};

void swEnumBitsOperationsTest(int testEnum) {
	std::cout << "swEnumBitsOperationsTest: " << std::endl;
	assert((testEnum & TestEnum::TWO) == TestEnum::TWO);
	std::cout << "AND TWO = " << (testEnum & TestEnum::TWO) << std::endl;
}

void swEnumIncrement(TestEnum& testEnum) {
	std::cout << "swEnumIncrement: " << std::endl;
	for(int i = testEnum.valueIndex(); i < testEnum.size(); ++i, ++ testEnum) {
		assert(testEnum == ARRAY_FOR_TESTS[i]);
		std::cout << testEnum << std::endl;
	}
}

void swEnumDecrement(TestEnum& testEnum) {
	std::cout << "swEnumDecrement:" << std::endl;
	for(int i = testEnum.valueIndex(); i >= 0; -- i, -- testEnum) {
		assert(testEnum == ARRAY_FOR_TESTS[i]);
		std::cout << testEnum << std::endl;
	}
}

void swEnumSwitch(TestEnum& testEnum) {
	std::cout << "swEnumSwitch:" << std::endl;
	assert(testEnum == ARRAY_FOR_TESTS[testEnum.valueIndex()]);
	switch (testEnum) {
		case TestEnum::ZERO:
			std::cout << "val ZERO = " << TestEnum::ZERO << " strVal = " << testEnum.stringValue() << std::endl;
			break;
		case TestEnum::ONE:
			std::cout << "val ONE = " << TestEnum::ONE << " strVal = " << testEnum.stringValue() << std::endl;
			break;
		case TestEnum::TWO:
			std::cout << "val TWO = " << TestEnum::TWO << " strVal = " << testEnum.stringValue() << std::endl;
			break;
		case TestEnum::THREE:
			std::cout << "val THREE = " << TestEnum::THREE << " strVal = " << testEnum.stringValue() << std::endl;
			break;
	}
}

void swEnumValCompare(TestEnum& testEnum) {
	std::cout << "swEnumValCompare:" << std::endl;
	std::cout << "val = " << testEnum << " equals val: ";
	assert(testEnum == ARRAY_FOR_TESTS[testEnum.valueIndex()]);
	if(testEnum == TestEnum::ZERO) {
		std::cout << "ZERO" << std::endl;
	}else if(testEnum == TestEnum::ONE) {
		std::cout << "ONE" << std::endl;
	}else if(testEnum == TestEnum::TWO) {
		std::cout << "TWO" << std::endl;
	}else if(testEnum == TestEnum::THREE) {
		std::cout << "THREE" << std::endl;
	}else {
		std::cout << "ERROR!!!!!!!!!!" << std::endl;
	}
}

void swEnumStringCompare(TestEnum& testEnum) {
	std::cout << "swEnumStringCompare:" << std::endl;
	std::cout << "val = " << testEnum << " equals string: ";
	assert(testEnum.stringValue() == STRING_ARRAY_FOR_TESTS[testEnum.valueIndex()]);
	if(testEnum == "ZERO") {
		std::cout << "ZERO" << std::endl;
	}else if(testEnum == "ONE") {
		std::cout << "ONE" << std::endl;
	}else if(testEnum == "TWO") {
		std::cout << "TWO" << std::endl;
	}else if(testEnum == "THREE") {
		std::cout << "THREE" << std::endl;
	}else {
		std::cout << "ERROR!!!!!!!!!!" << std::endl;
	}
}

void mainTest() {
	TestEnum testEnum1;
	assert(testEnum1 == TestEnum::ZERO);
	std::cout << "create testEnum1 = " << testEnum1 << std::endl;
	testEnum1 = TestEnum::TWO;
	assert(testEnum1 == TestEnum::TWO);
	std::cout << "assignment TestEnum::TWO, testEnum1 = " << testEnum1 << std::endl;
	swEnumIncrement(testEnum1);
	swEnumValCompare(testEnum1);
	swEnumSwitch(testEnum1);

	TestEnum testEnum2;
	assert(testEnum2 == TestEnum::ZERO);
	std::cout << std::endl << "create testEnum2 = " << testEnum2 << std::endl;
	testEnum2 = testEnum1;
	assert(testEnum2 == testEnum1);
	std::cout << "assignment from testEnum1, testEnum2 = " << testEnum2 << std::endl;
	swEnumDecrement(testEnum2);
	swEnumValCompare(testEnum2);
	swEnumStringCompare(testEnum2);

	TestEnum testEnum3 = TestEnum::THREE;
	assert(testEnum3 == TestEnum::THREE);
	std::cout << std::endl << "create testEnum3 with the value TestEnum::THREE, testEnum3 = " << testEnum3 << std::endl;
	swEnumDecrement(testEnum3);
	swEnumSwitch(testEnum3);
	swEnumIncrement(testEnum3);
	swEnumStringCompare(testEnum3);

	std::cout << std::endl;
	swEnumBitsOperationsTest(TestEnum::TWO | testEnum2 | testEnum3);

	std::cout << "sizeof(testEnum3) = " << sizeof(testEnum3) << std::endl;
}

#endif // SWENUMTESTS_H
