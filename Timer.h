/*
 * Timer.h
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#ifndef RANETOS_TIMER_H_
#define RANETOS_TIMER_H_

#include "ISystemClock.h"

namespace ranetos {
/**
 * Keeps track of time in milliseconds using an ISystemClock instance.
 */
class Timer {
	unsigned long timeOut;
	unsigned long timeSet;
	bool off;
	ranetos::ISystemClock& systemClock;
public:
	explicit Timer(ranetos::ISystemClock& systemClock) :
			systemClock(systemClock) {
		timeOut = 0;
		timeSet = 0;
		off = false;
	}
	virtual ~Timer() {
	}
	/**
	 * Gets time out value in milliseconds.
	 * @return time out value in milliseconds
	 */
	unsigned long getTimeOut() const {
		return timeOut;
	}
	/**
	 * Sets the time out value in milliseconds.
	 * @param timeOut value in milliseconds
	 */
	void setTimeOut(unsigned long timeOut) {
		this->timeOut = timeOut;
	}
	/**
	 * Check if the timer is off.
	 * @return true if timer is off
	 */
	bool isOff() const {
		return off;
	}
	/**
	 * Sets the timer off or on.
	 * @param off true to turn timer off, false to turn it on
	 */
	void setOff(bool off) {
		this->off = off;
	}
	/**
	 * Time when the timer was started.
	 * @return time in milliseconds when the timer started
	 */
	unsigned long getTimeSet() const {
		return timeSet;
	}
	/**
	 * Sets the start time value in milliseconds.
	 * @param timeSet time when the timer started in milliseconds
	 */
	void setTimeSet(unsigned long timeSet) {
		this->timeSet = timeSet;
	}
	/**
	 * Start the timer after, set the timeout value first.
	 */
	void start();
	/**
	 * Check if the timer has timed out.
	 * @returns true if timed out
	 */
	bool timedOut();
};

} /* namespace ranetos */

#endif /* RANETOS_TIMER_H_ */
