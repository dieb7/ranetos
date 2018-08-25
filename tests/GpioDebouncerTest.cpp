#include "../GpioDebouncer.h"

#include "MockGpio.h"
#include "Timer.h"
#include "MockSystemClock.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(GpioDebouncer) {
	ranetos::MockGpio* mockGpio;
	ranetos::Timer* timer;
	ranetos::MockSystemClock* mockSystemClock;
	ranetos::GpioDebouncer* inputDebouncer;

	void setup() {
		mockGpio = new ranetos::MockGpio();
		mockSystemClock = new ranetos::MockSystemClock();
		timer = new ranetos::Timer(*mockSystemClock);
		inputDebouncer = new ranetos::GpioDebouncer(*mockGpio, *timer, 50);
	}
	void teardown() {
		delete inputDebouncer;
		delete timer;
		delete mockSystemClock;
		delete mockGpio;
	}
};

TEST(GpioDebouncer, debounce) {
	CHECK(inputDebouncer->getCurrentState() == ranetos::GpioDebouncer::OFF_STATE);

	mockGpio->setOn(true);
	CHECK_FALSE(inputDebouncer->isOn());
	LONGS_EQUAL(50, timer->getTimeOut());
	CHECK(inputDebouncer->getCurrentState() == ranetos::GpioDebouncer::DEBOUNCING_STATE);

	mockSystemClock->setMillisecondsValue(51);
	CHECK_TRUE(inputDebouncer->isOn());
	CHECK(inputDebouncer->getCurrentState() == ranetos::GpioDebouncer::ON_STATE);

	// going back
	mockGpio->setOn(false);
	CHECK_FALSE(inputDebouncer->isOn());
	LONGS_EQUAL(50, timer->getTimeOut());
	CHECK(inputDebouncer->getCurrentState() == ranetos::GpioDebouncer::DEBOUNCING_STATE);

	mockSystemClock->setMillisecondsValue(101);
	CHECK_FALSE(inputDebouncer->isOn());
	CHECK(inputDebouncer->getCurrentState() == ranetos::GpioDebouncer::OFF_STATE);
}
