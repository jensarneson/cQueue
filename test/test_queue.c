#include "vendor/unity.h"
#include "../src/queue.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void TEST_ASSERT_QUEUE_EQUALS(size_t len, QData *expected, Queue *q)
{
  TEST_ASSERT_NOT_NULL_MESSAGE(q, "queue is null");
  for (size_t i = 0; i < len; ++i) {
    QResult result = qNext(q);
    TEST_ASSERT_MESSAGE(result.hasData, "queue is shorter than expected");
    TEST_ASSERT_EQUAL_INT(expected[i], result.u.data);
  }
  // Make sure that is all.
  TEST_ASSERT_FALSE(qNext(q).hasData);
}

static void qFromBuffer(Queue *q, size_t len, QData *buffer)
{
  TEST_ASSERT_NOT_NULL_MESSAGE(q, "expected Queue got NULL");
  for (size_t i = 0; i < len; ++i) {
    qAdd(q, buffer[i]);
  }
}

static void test_queue_next(void)
{
  Queue *q = mkQueue();
  TEST_ASSERT_NOT_NULL_MESSAGE(q, "Failed to allocate queue");
  QData expected[12] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
  qFromBuffer(q, 12, expected);
  TEST_ASSERT_QUEUE_EQUALS(12, expected, q);
  qDestroy(q, NULL);
}

int main(void)
{
   UnityBegin("test/test_queue.c");

   RUN_TEST(test_queue_next);

   return UnityEnd();
}
