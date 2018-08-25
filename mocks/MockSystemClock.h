/*
 * MockSystemClock.h
 *
 *  Created on: Aug 24, 2018
 *      Author: diebm
 */

#ifndef MOCKS_MOCKSYSTEMCLOCK_H_
#define MOCKS_MOCKSYSTEMCLOCK_H_

#include <ISystemClock.h>

namespace ranetos {

class MockSystemClock: public ISystemClock {
	unsigned long millisecondsValue;
public:
	MockSystemClock() {
		millisecondsValue = 0;
	}
	virtual ~MockSystemClock() {}

	virtual unsigned long milliseconds() {
		return getMillisecondsValue();
	}

	unsigned long getMillisecondsValue() const {
		return millisecondsValue;
	}

	void setMillisecondsValue(unsigned long millisecondsValue) {
		this->millisecondsValue = millisecondsValue;
	}
};

} /* namespace ranetos */

#endif /* MOCKS_MOCKSYSTEMCLOCK_H_ */
