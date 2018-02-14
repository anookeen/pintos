/* Verifies that lowering a thread's priority so that it is no
   longer the highest-priority thread in the system causes it to
   yield immediately. */

#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/init.h"
#include "threads/thread.h"

//static thread_func changing_thread;
static void changing_thread (void *aux UNUSED);
void
test_priority_change (void) 
{
  /* This test does not work with the MLFQS. */
  ASSERT (!thread_mlfqs);
  msg ("Creating a high-priority thread 2.");int priority=PRI_DEFAULT+1;
  tid_t p1=thread_create ("thread 2", priority, changing_thread,NULL);
//if(thread_get_priority()<priority){
//thread_yield();
//}
  msg ("Thread 2 should have just lowered its priority.");
  thread_set_priority (PRI_DEFAULT - 2);//thread_yield();
  msg ("Thread 2 should have just exited.");
}

static void
changing_thread (void *aux UNUSED) 
{
int priority=thread_get_priority(); 
msg ("Thread 2 now lowering priority.");
  thread_set_priority (PRI_DEFAULT - 1);
//if(thread_get_priority()<priority){
//thread_yield();}
  msg ("Thread 2 exiting.");
}
