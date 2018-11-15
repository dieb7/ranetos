/*
 * IGpio.h
 *
 *  Created on: Aug 24, 2018
 *      Author: diebm
 */

#ifndef RANETOS_IGPIO_H_
#define RANETOS_IGPIO_H_

namespace ranetos {
/**
 * Interface for implementing GPIOs.
 */
class IGpio {
public:
	IGpio() {
	}
	virtual ~IGpio() {
	}
	/**
	 * Check if the GPIO is an output or not.
	 * @return true if ouput
	 */
	virtual bool isOutput() = 0;
	/**
	 * Sets the GPIO as an output or input.
	 * @param output a boolean set GPIO as output or not
	 */
	virtual void setOutput(bool output) = 0;
	/**
	 * Check if GPIO is on
	 * @return true if is on, false if not
	 */
	virtual bool isOn() = 0;
	/**
	 * Sets the GPIO on or off
	 * @param on value for the GPIO
	 */
	virtual void setOn(bool on) = 0;
};

} /* namespace ranetos */

#endif /* RANETOS_IGPIO_H_ */
