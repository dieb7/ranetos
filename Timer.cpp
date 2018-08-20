/*
 * Timer.cpp
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#include "Timer.h"

namespace ranetos {

void Timer::start() {
	this->setTimeSet(this->systemClock.milliseconds());
	off = false;
}

bool Timer::timedOut()  {
	if (this->isOff()) {
		return false;
	}
	return this->getTimeSet() + this->getTimeOut() < this->systemClock.milliseconds();
}

} /* namespace ranetos */

