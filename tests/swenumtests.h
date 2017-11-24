#ifndef SWENUMTESTS_H
#define SWENUMTESTS_H

#include "src/swenum.h"
#include "cassert"

DECLARE_SW_ENUM (
	TestEnum,
	ZERO,
	ONE,
	TWO,
	THREE
)

int ARRAY_FOR_TESTS[4] = {0, 1, 2, 3};
std::string STRING_ARRAY_FOR_TESTS[4] = {"ZERO", "ONE", "TWO", "THREE"};

void swEnumIncrement(TestEnum& testEnum) {
	std::cout << "swEnumIncrement: ";
	for(int i = testEnum; i < testEnum.size(); ++i, ++ testEnum) {
		assert(i == ARRAY_FOR_TESTS[i]);
		std::cout << testEnum << std::endl;
	}
}

void swEnumDecrement(TestEnum& testEnum) {
	std::cout << "swEnumDecrement:" << std::endl;
	for(int i = testEnum; i >= 0; -- i, -- testEnum) {
		assert(i == ARRAY_FOR_TESTS[i]);
		std::cout << testEnum << std::endl;
	}
}

void swEnumSwitch(TestEnum& testEnum) {
	std::cout << "swEnumSwitch:" << std::endl;
	assert(testEnum == ARRAY_FOR_TESTS[testEnum]);
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
	assert(testEnum == ARRAY_FOR_TESTS[testEnum]);
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
	assert(testEnum.stringValue() == STRING_ARRAY_FOR_TESTS[testEnum]);
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
}

#endif // SWENUMTESTS_H
