
#include <pthread.h>

#include "libc-symbols.h"


#ifndef IS_IN_rtld
#error Not in dynamic linker
#endif


/* Weak definitions which should get overridden once ld.so is
   dynamically linked with libpthread.so. */

static int rtld_pthread_mutex_lock(pthread_mutex_t *mutex)
{
  return 0;
}

static int rtld_pthread_mutex_unlock(pthread_mutex_t *mutex)
{
  return 0;
}

weak_alias(rtld_pthread_mutex_lock, pthread_mutex_lock);
weak_alias(rtld_pthread_mutex_unlock, pthread_mutex_unlock);
