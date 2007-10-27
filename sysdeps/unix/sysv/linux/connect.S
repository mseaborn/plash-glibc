#define	socket	kernel_connect
#define __socket kernel___libc_connect
#define SOCKOP_kernel_connect SOCKOP_connect
#define	NARGS	3
#define NEED_CANCELLATION
#include <socket.S>
strong_alias (kernel___libc_connect, kernel___connect_internal)
weak_alias (kernel___libc_connect, kernel___connect)
