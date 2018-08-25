/*
 * Timer.h
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <ISystemClock.h>

namespace ranetos {

class Timer {
	unsigned long timeOut;
	unsigned long timeSet;
	bool off;
	ranetos::ISystemClock & systemClock;
public:
	Timer(ranetos::ISystemClock & systemClock): systemClock(systemClock){
		timeOut = 0;
		timeSet = 0;
		off = false;
	}
	virtual ~Timer() {}

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

#endif /* TIMER_H_ */
