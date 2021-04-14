#include <cstdio>
#include <csetjmp>
#include <iostream>
#include <cstdlib>
/*
	setjmp 跳转 
*/

static jmp_buf env;  // 存储上下文
 void b(void) {
	printf("%s():Begin.\n",__FUNCTION__);
	printf("%s():Call a().\n",__FUNCTION__);
}

 void a(void) {
	printf("%s():Begin.\n",__FUNCTION__);
	printf("%s():Call b().\n",__FUNCTION__);
	b();
	longjmp(env,21);
	printf("%s():b() returned. \n",__FUNCTION__);
	printf("%s():End.\n",__FUNCTION__);
}

int main(int argc,char **argv) {
		
	printf("%s():Begin.\n",__FUNCTION__);
	printf("%s():Call a().\n",__FUNCTION__);
	a();
	printf("%s():a() returned. \n",__FUNCTION__);
	printf("%s():End.\n",__FUNCTION__);

	/*
		main -> a -|    return main --> main -> end
				   |  			     	|
				   | 			 	    |
				   -> b -> end b --> end a

	*/
	return 0;
}
