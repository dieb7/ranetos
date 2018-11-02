/*
 * InvertGpio.h
 *
 *  Created on: Nov. 2, 2018
 *      Author: diebm
 */

#ifndef INVERTGPIO_H_
#define INVERTGPIO_H_

#include <IGpio.h>

namespace ranetos {

class InvertGpio: public IGpio {
	IGpio & gpio;
public:
	InvertGpio(IGpio & gpio): gpio(gpio) {
	}
	virtual ~InvertGpio() {
	}

	bool isOutput() {
		return gpio.isOutput();
	}

	void setOutput(bool output) {
		gpio.setOutput(output);
	}

	bool isOn() {
		return !gpio.isOn();
	}

	void setOn(bool on) {
		gpio.setOn(!on);
	}
};

} /* namespace ranetos */

#endif /* INVERTGPIO_H_ */
