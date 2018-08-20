/*
 * ITimer.h
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#ifndef ITIMER_H_
#define ITIMER_H_

namespace ranetos {

#include "ISystemClock.h"

class ITimer {
	unsigned long timeOut;
	unsigned long timeSet;
	bool off;
	ranetos::ISystemClock & systemClock;
public:
	ITimer(ranetos::ISystemClock & systemClock): systemClock(systemClock){
		timeOut = 0;
		timeSet = 0;
		off = false;
	}
	virtual ~ITimer() {}

	unsigned long getTimeOut() const {
		return timeOut;
	}

	void setTimeOut(unsigned long timeOut) {
		this->timeOut = timeOut;
	}

	bool isOff() const {
		return off;
	}

	void setOff(bool off) {
		this->off = off;
	}

	unsigned long getTimeSet() const {
		return timeSet;
	}

	void setTimeSet(unsigned long timeSet) {
		this->timeSet = timeSet;
	}

	void start();
	bool timedOut();
};

} /* namespace ranetos */

#endif /* ITIMER_H_ */
