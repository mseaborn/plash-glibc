#define	socket	kernel_getsockname
#define SOCKOP_kernel_getsockname SOCKOP_getsockname
#define	NARGS	3
#define NO_WEAK_ALIAS	1
#include <socket.S>
weak_alias (kernel_getsockname, kernel___getsockname)
