/*
 * Queue.h
 *
 *  Created on: Apr. 19, 2019
 *      Author: diebm
 */

#ifndef RANETOS_QUEUE_H_
#define RANETOS_QUEUE_H_

namespace ranetos {

#include <stddef.h>

template <class T, size_t N>
class Queue {
	T items[N + 1];
	size_t head;
	size_t tail;
public:
	Queue() {
		head = 0;
		tail = 0;
	}

	virtual ~Queue() {}

	size_t size() {
		return N;
	}

	bool empty() {
		return head == tail;
	}

	bool full() {
		if (head < tail) {
			return (N + 1) - (tail - head) == 1;
		} else {
			return (head - tail) == 1;
		}
	}

	bool push(T item) {
		if (!full()) {
			items[tail++] = item;
			if (tail == (N + 1)) {
				tail = 0;
			}
			return true;
		}
		return false;
	}

	bool pop(T &item) {
		if (!empty()) {
			item = items[head++];
			if (head == (N + 1)) {
				head = 0;
			}
			return true;
		}
		return false;
	}
};

} /* namespace ranetos */

#endif /* RANETOS_QUEUE_H_ */
