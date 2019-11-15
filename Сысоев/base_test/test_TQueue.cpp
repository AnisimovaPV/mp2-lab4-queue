#include "TQueue.h"
#include <gtest.h>


TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> q(5));
}
TEST(TQueue, throws_when_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(-1));
}
TEST(TQueue, throws_when_cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(TQueue<int> q(MaxQueueSize + 1));
}
TEST(TQueue, can_check_queue_is_empty)
{
	TQueue<int> q(5);
	EXPECT_TRUE(1==q.IsEmpty());
}
TEST(TQueue, can_check_queue_is_full)
{
	TQueue<int> q(5);
	for (int i = 0; i < 5; i++)
		q.Push(i);
	EXPECT_TRUE(1 == q.IsFull());
}
TEST(TQueue, take_element_on_pop_with_corrected_value)
{
	TQueue<int> q(5);
	for (int i = 0; i < 5; i++)
		q.Push(i+10);
	EXPECT_TRUE(10 == q.Pop());
}

TEST(TQueue, different_memories_two_queues)
{
	TQueue<int> q1(5), q2(6);
	EXPECT_TRUE(&q1 != &q2);
}