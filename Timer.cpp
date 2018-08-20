/*
 * ITimer.cpp
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#include "ITimer.h"

namespace ranetos {

void ITimer::start() {
	this->setTimeSet(this->systemClock.milliseconds());
	off = false;
}

bool ITimer::timedOut()  {
	if (this->isOff()) {
		return false;
	}
	return this->getTimeSet() + this->getTimeOut() < this->systemClock.milliseconds();
}

} /* namespace ranetos */

