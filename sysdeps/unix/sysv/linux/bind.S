#define	socket	kernel_bind
#define SOCKOP_kernel_bind SOCKOP_bind
#define	NARGS	3
#define NO_WEAK_ALIAS	1
#include <socket.S>
weak_alias (kernel_bind, kernel___bind)
