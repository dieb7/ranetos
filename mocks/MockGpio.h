/*
 * MockGpio.h
 *
 *  Created on: Aug 24, 2018
 *      Author: diebm
 */

#ifndef MOCKS_MOCKGPIO_H_
#define MOCKS_MOCKGPIO_H_

#include <IGpio.h>

namespace ranetos {

class MockGpio: public IGpio {
	bool output;
	bool on;
public:
	MockGpio() {
		output = true;
		on = false;
	}
	virtual ~MockGpio() {}

	bool isOutput() {
		return output;
	}
	void setOutput(bool output) {
		this->output = output;
	}
	bool isOn() {
		return on;
	}
	void setOn(bool on) {
		this->on = on;
	}
};

} /* namespace ranetos */

#endif /* MOCKS_MOCKGPIO_H_ */
