/*
 * ITask.h
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#ifndef RANETOS_ITASK_H_
#define RANETOS_ITASK_H_

namespace ranetos {

class ITask {
public:
	ITask() {}
	virtual ~ITask() {}

	virtual void work() = 0;
};

} /* namespace ranetos */

#endif /* RANETOS_ITASK_H_ */
