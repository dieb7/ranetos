/*
 * OneShotGpio.h
 *
 *  Created on: Aug 25, 2018
 *      Author: diebm
 */

#ifndef ONESHOTGPIO_H_
#define ONESHOTGPIO_H_

#include "IGpio.h"

namespace ranetos {
/**
 * Wraps a IGpio object, once it is on and the value checked it will return
 * false for subsequent check until the wrapped IGpio object changes state.
 */
class OneShotGpio: public IGpio {
	IGpio& gpio;
public:
	enum State {
		OFF_STATE, ON_STATE, CHECKED_STATE
	};

	explicit OneShotGpio(IGpio& gpio) :
			gpio(gpio), currentState(OFF_STATE) {
	}
	virtual ~OneShotGpio() {
	}

	bool isOutput() {
		return gpio.isOutput();
	}
	void setOutput(bool output) {
		gpio.setOutput(output);
	}
	bool isOn();
	void setOn(bool on) {
		gpio.setOn(on);
	}
	State getCurrentState() {
		return currentState;
	}

private:
	State currentState;
};

} /* namespace ranetos */

#endif /* ONESHOTGPIO_H_ */
