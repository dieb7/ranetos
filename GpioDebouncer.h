/*
 * InputDebouncer.h
 *
 *  Created on: Aug 24, 2018
 *      Author: diebm
 */

#ifndef GPIODEBOUNCER_H_
#define GPIODEBOUNCER_H_

#include <Timer.h>
#include <IGpio.h>

namespace ranetos {

class GpioDebouncer: public IGpio {
	IGpio & input;
	Timer & timer;
	unsigned long delay;
public:
	enum State {
		OFF_STATE,
		DEBOUNCING_STATE,
		ON_STATE
	};

	GpioDebouncer(IGpio & input, Timer & timer, unsigned long delay): input(input), timer(timer) {
		this->delay = delay;
		this->input.setOutput(false);
		this->currentState = OFF_STATE;
	}
	virtual ~GpioDebouncer() {}

	bool isOutput() {
		return input.isOutput();
	}
	void setOutput(bool output) {
		input.setOutput(output);
	}
	bool isOn();
	void setOn(bool on) {
		input.setOn(on);
	}

	State getCurrentState() {
		return currentState;
	}

private:
	State currentState;
};

} /* namespace ranetos */

#endif /* GPIODEBOUNCER_H_ */
