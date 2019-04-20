#include "Queue.h"

//CppUTest includes should be after your and system includes
#include "CppUTest/TestHarness.h"

using namespace ranetos;

TEST_GROUP(Queue) {
	Queue<int, 5>* queue;

	void setup() {
		queue = new Queue<int, 5>();
	}
	void teardown() {
		delete queue;
	}
};

TEST(Queue, size) {
	LONGS_EQUAL(5, queue->size());
}

TEST(Queue, startEmpty) {
	CHECK_TRUE(queue->empty());
}

TEST(Queue, startNotFull) {
	CHECK_FALSE(queue->full());
}

TEST(Queue, pushNotEmpty) {
	queue->push(3);
	CHECK_FALSE(queue->empty());
}

TEST(Queue, simplePushPull) {
	int item = 0;

	queue->push(5);
	queue->push(4);
	queue->push(3);

	queue->pop(item);
	LONGS_EQUAL(5, item);

	queue->pop(item);
	LONGS_EQUAL(4, item);

	queue->pop(item);
	LONGS_EQUAL(3, item);
}

TEST(Queue, pullUntilEmpty) {
	int item = 0;

	queue->push(5);
	queue->push(4);
	queue->push(3);

	queue->pop(item);
	queue->pop(item);
	queue->pop(item);

	CHECK_TRUE(queue->empty());
}

TEST(Queue, pullFromEmpty) {
	int item = 0;
	CHECK_FALSE(queue->pop(item));
}

TEST(Queue, pushToFull) {
	CHECK_TRUE(queue->push(5));
	CHECK_TRUE(queue->push(4));
	CHECK_TRUE(queue->push(3));
	CHECK_TRUE(queue->push(2));
	CHECK_TRUE(queue->push(1));

	CHECK_TRUE(queue->full());

	CHECK_FALSE(queue->push(0));
}

TEST(Queue, pullFromFull) {
	int value = 0;

	queue->push(5);
	queue->push(4);
	queue->push(3);
	queue->push(2);
	queue->push(1);

	CHECK_TRUE(queue->pop(value));
	LONGS_EQUAL(5, value);

	CHECK_TRUE(queue->pop(value));
	LONGS_EQUAL(4, value);

	CHECK_TRUE(queue->pop(value));
	LONGS_EQUAL(3, value);

	CHECK_TRUE(queue->pop(value));
	LONGS_EQUAL(2, value);

	CHECK_TRUE(queue->pop(value));
	LONGS_EQUAL(1, value);
}

TEST(Queue, reuseEmptiedSpace) {
	int value = 0;

	queue->push(5);
	queue->push(4);
	queue->push(3);
	queue->push(2);
	queue->push(1);

	queue->pop(value);

	queue->push(12);

	CHECK_TRUE(queue->pop(value));
	LONGS_EQUAL(4, value);

	CHECK_TRUE(queue->pop(value));
	LONGS_EQUAL(3, value);

	CHECK_TRUE(queue->pop(value));
	LONGS_EQUAL(2, value);

	CHECK_TRUE(queue->pop(value));
	LONGS_EQUAL(1, value);

	CHECK_TRUE(queue->pop(value));
	LONGS_EQUAL(12, value);
}

TEST(Queue, reuseEmptiedSpaceMarksFullCorrectly) {
	int value = 0;

	queue->push(5);
	queue->push(4);
	queue->push(3);
	queue->push(2);
	queue->push(1);

	queue->pop(value);

	CHECK_FALSE(queue->full());

	queue->push(12);

	CHECK_TRUE(queue->full());
}

TEST(Queue, reuseEmptiedSpace2) {
	int value = 0;

	queue->push(5);
	queue->push(4);
	queue->push(3);
	queue->push(2);
	queue->push(1);

	queue->pop(value);
	queue->pop(value);

	queue->push(12);
	queue->push(13);

	CHECK_TRUE(queue->pop(value));
	LONGS_EQUAL(3, value);

	CHECK_TRUE(queue->pop(value));
	LONGS_EQUAL(2, value);

	CHECK_TRUE(queue->pop(value));
	LONGS_EQUAL(1, value);

	CHECK_TRUE(queue->pop(value));
	LONGS_EQUAL(12, value);

	CHECK_TRUE(queue->pop(value));
	LONGS_EQUAL(13, value);
}

TEST(Queue, reuseEmptiedSpaceMarksFullCorrectly2) {
	int value = 0;

	queue->push(5);
	queue->push(4);
	queue->push(3);
	queue->push(2);
	queue->push(1);

	queue->pop(value);
	queue->pop(value);

	CHECK_FALSE(queue->full());

	queue->push(12);
	queue->push(13);

	CHECK_TRUE(queue->full());
}

TEST(Queue, emptyInMidPosition) {
	int value = 0;

	queue->push(5);
	queue->push(4);
	queue->push(3);
	queue->push(2);
	queue->push(1);

	queue->pop(value);
	queue->pop(value);

	queue->push(12);
	queue->push(13);

	queue->pop(value);
	queue->pop(value);
	queue->pop(value);
	queue->pop(value);
	queue->pop(value);
	queue->pop(value);

	CHECK_TRUE(queue->empty());
}

TEST(Queue, resumeFromemptyInMidPosition) {
	int value = 0;

	queue->push(5);
	queue->push(4);
	queue->push(3);
	queue->push(2);
	queue->push(1);

	queue->pop(value);
	queue->pop(value);

	queue->push(12);
	queue->push(13);

	queue->pop(value);
	queue->pop(value);
	queue->pop(value);
	queue->pop(value);
	queue->pop(value);
	queue->pop(value);

	queue->push(14);
	queue->push(15);

	CHECK_TRUE(queue->pop(value));
	LONGS_EQUAL(14, value);

	CHECK_TRUE(queue->pop(value));
	LONGS_EQUAL(15, value);
}
