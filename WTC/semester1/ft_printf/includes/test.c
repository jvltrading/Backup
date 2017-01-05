
#include <libc.h>

int ft_printf(const char *format, ...);

int main(void)
{
	int r1 = 0;
	int r2 = 0;
	puts("++++++++++++++++++++++++++++++++ s ++++++++++++++++++++++++++++++++");
	r1 = printf("   *%s*\n", "string");
	r2 = ft_printf("   !%s!\n", "string");
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++++++++ S +++++++++++++++++++++++++++++++");
	r1 = printf("*this  %S is a test*\n", L"String");
	r2 = ft_printf("!this  %S is a test!\n", L"String");
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("*this %S is a test*\n", L"StringString");
	r2 = ft_printf("!this %S is a test!\n", L"StringString");
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("* *%S ** \n", L"string String");
	r2 = ft_printf("! !%S !! \n", L"string String");
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++++++++ C +++++++++++++++++++++++++++++++");
	r1 = printf("*this =%C= is a test*\n", L'h');
	r2 = ft_printf("!this =%C= is a test!\n", L'h');
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
}
