/*
 * InvertGpio.h
 *
 *  Created on: Nov. 2, 2018
 *      Author: diebm
 */

#ifndef RANETOS_INVERTGPIO_H_
#define RANETOS_INVERTGPIO_H_

#include "IGpio.h"

namespace ranetos {
/**
 * Wraps a IGpio object and inverts it
 */
class InvertGpio: public IGpio {
	IGpio& gpio;
public:
	explicit InvertGpio(IGpio& gpio) :
	gpio(gpio) {
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

#endif /* RANETOS_INVERTGPIO_H_ */
