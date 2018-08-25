/*
 * InputDebouncer.h
 *
 *  Created on: Aug 24, 2018
 *      Author: diebm
 */

#ifndef DEBOUNCEGPIO_H_
#define DEBOUNCEGPIO_H_

#include <Timer.h>
#include <IGpio.h>

namespace ranetos {

class DebounceGpio: public IGpio {
	IGpio & input;
	Timer & timer;
	unsigned long delay;
public:
	enum State {
		OFF_STATE,
		DEBOUNCING_STATE,
		ON_STATE
	};

	DebounceGpio(IGpio & input, Timer & timer, unsigned long delay): input(input), timer(timer) {
		this->delay = delay;
		this->input.setOutput(false);
		this->currentState = OFF_STATE;
	}
	virtual ~DebounceGpio() {}

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

#endif /* DEBOUNCEGPIO_H_ */
