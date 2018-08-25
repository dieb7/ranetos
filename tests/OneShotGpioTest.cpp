#include "OneShotGpio.h"
#include "MockGpio.h"

//CppUTest includes should be after your and system includes
#include "CppUTest/TestHarness.h"

TEST_GROUP(OneShotGpio) {
	ranetos::MockGpio* mockGpio;
	ranetos::OneShotGpio* oneShotGpio;

	void setup() {
		mockGpio = new ranetos::MockGpio();
		oneShotGpio = new ranetos::OneShotGpio(*mockGpio);
	}
	void teardown() {
		delete oneShotGpio;
		delete mockGpio;
	}
};

TEST(OneShotGpio, OneShotFSM) {
	CHECK(oneShotGpio->getCurrentState() == ranetos::OneShotGpio::State::OFF_STATE);

	mockGpio->setOn(true);

	CHECK_TRUE(oneShotGpio->isOn());
	CHECK(oneShotGpio->getCurrentState() == ranetos::OneShotGpio::State::ON_STATE);

	CHECK_FALSE(oneShotGpio->isOn());
	CHECK(oneShotGpio->getCurrentState() == ranetos::OneShotGpio::State::CHECKED_STATE);

	CHECK_FALSE(oneShotGpio->isOn());
	CHECK(oneShotGpio->getCurrentState() == ranetos::OneShotGpio::State::CHECKED_STATE);

	mockGpio->setOn(false);
	CHECK_FALSE(oneShotGpio->isOn());
	CHECK(oneShotGpio->getCurrentState() == ranetos::OneShotGpio::State::OFF_STATE);
}

