/*
 * ISystemClock.h
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#ifndef ISYSTEMCLOCK_H_
#define ISYSTEMCLOCK_H_

namespace ranetos {

class ISystemClock {
public:
	ISystemClock() {}
	virtual ~ISystemClock() {}

	virtual unsigned long milliseconds() = 0;
};

} /* namespace ranetos */

#endif /* ISYSTEMCLOCK_H_ */
