/*
 * ISystemClock.h
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#ifndef RANETOS_ISYSTEMCLOCK_H_
#define RANETOS_ISYSTEMCLOCK_H_

namespace ranetos {
/**
 * Interface for implementing a milliseconds source.
 */
class ISystemClock {
public:
	ISystemClock() {}
	virtual ~ISystemClock() {}
	/**
	 * Current system milliseconds count.
	 * @return milliseconds count
	 */
	virtual unsigned long milliseconds() = 0;
};

} /* namespace ranetos */

#endif /* RANETOS_ISYSTEMCLOCK_H_ */
