#include <stdio.h>
/**
 * myStartupFun - Apply the constructor attributes to myStartupFun() so that it
 * is executed before main()
 */
void myStartupFun(void) __attribute__((constructor));

/**
 * myStartupFun - implementation of myStartupFun
 */
void myStartupFun(void)
{
printf("You're best! and yet, you must allow.\n");
printf("I bore my house upon my back!\n");
}
