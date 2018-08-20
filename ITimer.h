/*
 * ITimer.h
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#ifndef ITIMER_H_
#define ITIMER_H_

namespace ranetos {

class ITimer {
	unsigned long timeOut;
	unsigned long timeSet;
	bool off;
public:
	ITimer() {
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

	void start() {
		this->setTimeSet(this->currentMillis());
		this->setOff(false);
	}

	bool timedOut() {
		if (this->isOff()) {
			return false;
		}
		return this->getTimeSet() + this->getTimeOut() < this->currentMillis();
	}

	virtual unsigned long currentMillis() = 0;
};

} /* namespace ranetos */

#endif /* ITIMER_H_ */
