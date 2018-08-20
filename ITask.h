/*
 * ITask.h
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#ifndef ITASK_H_
#define ITASK_H_

namespace ranetos {

class ITask {
public:
	ITask() {}
	virtual ~ITask() {}

	virtual void work() = 0;
};

} /* namespace ranetos */

#endif /* ITASK_H_ */
