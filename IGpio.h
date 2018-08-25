/*
 * IGpio.h
 *
 *  Created on: Aug 24, 2018
 *      Author: diebm
 */

#ifndef IGPIO_H_
#define IGPIO_H_

namespace ranetos {

class IGpio {
public:
	IGpio() {}
	virtual ~IGpio() {}

	virtual bool isOutput() = 0;
	virtual void setOutput(bool output) = 0;
	virtual bool isOn() = 0;
	virtual void setOn(bool on) = 0;
};

} /* namespace ranetos */

#endif /* IGPIO_H_ */
