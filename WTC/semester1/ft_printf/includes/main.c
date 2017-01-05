/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 08:12:13 by rojones           #+#    #+#             */
/*   Updated: 2016/06/03 09:38:52 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int	ft_printf(const char *format, ...);

int main()
{
	int	r1 = 0;
	int	r2 = 0;
	int	j = -10;
	int	i = -41;


	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	r1 = printf("this is a test\n", "String");
	r2 = ft_printf("this is a test\n", "String");
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);

	puts("+++++++++++++++++++++++++++++++++ s +++++++++++++++++++++++++++++++");
	r1 = printf("this =%s= is a test\n", "String");
	r2 = ft_printf("this =%s= is a test\n", "String");
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++++++++ c +++++++++++++++++++++++++++++++");
	r1 = printf("this =%c= is a test\n", 'h');
	r2 = ft_printf("this =%c= is a test\n", 'h');
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++++++++ d +++++++++++++++++++++++++++++++");
	r1 = printf("this =%d= is a test\n", i);
	r2 = ft_printf("this =%d= is a test\n", i);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%d= is a test\n", 2147483647);
	r2 = ft_printf("this =%d= is a test\n", 2147483647);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%d= is a test\n", 1000);
	r2 = ft_printf("this =%d= is a test\n", 1000);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%d= is a test\n", 0);
	r2 = ft_printf("this =%d= is a test\n", 0);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%ld= is a test\n", -1000);
	r2 = ft_printf("this =%ld= is a test\n", -1000);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++++++++ i +++++++++++++++++++++++++++++++");
	r1 = printf("this = %i = is a test\n", j);
	r2 = ft_printf("this = %i = is a test\n", j);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%i= is a test\n", 2147483647);
	r2 = ft_printf("this =%i= is a test\n", 2147483647);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%i= is a test\n", 1000);
	r2 = ft_printf("this =%i= is a test\n", 1000);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%i= is a test\n", 0);
	r2 = ft_printf("this =%i= is a test\n", 0);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++++++++ o +++++++++++++++++++++++++++++++");
	r1 = printf("this =%o= is a test\n", i);
	r2 = ft_printf("this =%o= is a test\n", i);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%o= is a test\n", 42);
	r2 = ft_printf("this =%o= is a test\n", 42);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%o= is a test\n", 0);
	r2 = ft_printf("this =%o= is a test\n", 0);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++++++++ u +++++++++++++++++++++++++++++++");
	r1 = printf("this =%u= is a test\n", i);
	r2 = ft_printf("this =%u= is a test\n", i);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%u= is a test\n", 42);
	r2 = ft_printf("this =%u= is a test\n", 42);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%u= is a test\n", 0);
	r2 = ft_printf("this =%u= is a test\n", 0);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++++++++ x +++++++++++++++++++++++++++++++");
	r1 = printf("this =%x= is a test\n", i);
	r2 = ft_printf("this =%x= is a test\n", i);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%x= is a test\n", 42);
	r2 = ft_printf("this =%x= is a test\n", 42);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%x= is a test\n", 0);
	r2 = ft_printf("this =%x= is a test\n", 0);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++++++++ p +++++++++++++++++++++++++++++++");
	r1 = printf("this =%p= is a test\n", j);
	r2 = ft_printf("this =%p= is a test\n", j);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%#p= is a test\n", j);
	r2 = ft_printf("this =%#p= is a test\n", j);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++++++++ X +++++++++++++++++++++++++++++++");
	r1 = printf("this =%X= is a test\n", i);
	r2 = ft_printf("this =%X= is a test\n", i);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%X= is a test\n", 42);
	r2 = ft_printf("this =%X= is a test\n", 42);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%X= is a test\n", 0);
	r2 = ft_printf("this =%X= is a test\n", 0);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++++++++ D +++++++++++++++++++++++++++++++");
	r1 = printf("this =%D= is a test\n", i);
	r2 = ft_printf("this =%D= is a test\n", i);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%D= is a test\n", 42);
	r2 = ft_printf("this =%D= is a test\n", 42);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%D= is a test\n", 0);
	r2 = ft_printf("this =%D= is a test\n", 0);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++++++++ O +++++++++++++++++++++++++++++++");
	r1 = printf("this =%O= is a test\n", i);
	r2 = ft_printf("this =%O= is a test\n", i);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%O= is a test\n", 42);
	r2 = ft_printf("this =%O= is a test\n", 42);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%O= is a test\n", 0);
	r2 = ft_printf("this =%O= is a test\n", 0);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++++++++ U +++++++++++++++++++++++++++++++");
	r1 = printf("this =%U= is a test\n", i);
	r2 = ft_printf("this =%U= is a test\n", i);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%U= is a test\n", 42);
	r2 = ft_printf("this =%U= is a test\n", 42);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%U= is a test\n", 0);
	r2 = ft_printf("this =%U= is a test\n", 0);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++++++++ S +++++++++++++++++++++++++++++++");
	r1 = printf("*this %S is a test*\n", L"String");
	r2 = ft_printf("!this %S is a test!\n", L"String");
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++++++++ C +++++++++++++++++++++++++++++++");
	r1 = printf("*this =%C= is a test*\n", 'h');
	r2 = ft_printf("!this =%C= is a test!\n", 'h');
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++ num format ++++++++++++++++++++++++++++");
	r1 = printf("this =%8d= is a test\n", 1000);
	r2 = ft_printf("this =%8d= is a test\n", 1000);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%-8d= is a test\n", 1000);
	r2 = ft_printf("this =%-8d= is a test\n", 1000);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%.8d= is a test\n", 1000);
	r2 = ft_printf("this =%.8d= is a test\n", 1000);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%+#o= is a test\n", 1000);
	r2 = ft_printf("this =%+#o= is a test\n", 1000);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%#+x= is a test\n", 1000);
	r2 = ft_printf("this =%#+x= is a test\n", 1000);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%#X= is a test\n", 1000);
	r2 = ft_printf("this =%#X= is a test\n", 1000);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%#10.6x= is a test\n", 1000);
	r2 = ft_printf("this =%#10.6x= is a test\n", 1000);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%+5d= is a test\n", 1000);
	r2 = ft_printf("this =%+5d= is a test\n", 1000);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%-08d= is a test\n", 1000);
	r2 = ft_printf("this =%-08d= is a test\n", 1000);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%+8d= is a test\n", 1000);
	r2 = ft_printf("this =%+8d= is a test\n", 1000);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%+-8d= is a test\n", 1000);
	r2 = ft_printf("this =%+-8d= is a test\n", 1000);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%+08d= is a test\n", 1000);
	r2 = ft_printf("this =%+08d= is a test\n", 1000);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%+.8d= is a test\n", 1000);
	r2 = ft_printf("this =%+.8d= is a test\n", 1000);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++ S&C format ++++++++++++++++++++++++++++");
	r1 = printf("this =%10s= is a test\n", "String");
	r2 = ft_printf("this =%10s= is a test\n", "String");
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%-10s= is a test\n", "String");
	r2 = ft_printf("this =%-10s= is a test\n", "String");
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =% s= is a test\n", "String");
	r2 = ft_printf("this =% s= is a test\n", "String");
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%010s= is a test\n", "String");
	r2 = ft_printf("this =%010s= is a test\n", "String");
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%+s= is a test\n", "String");
	r2 = ft_printf("this =%+s= is a test\n", "String");
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%5c= is a test\n", 'h');
	r2 = ft_printf("this =%5c= is a test\n", 'h');
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%-5c= is a test\n", 'h');
	r2 = ft_printf("this =%-5c= is a test\n", 'h');
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%05c= is a test\n", 'h');
	r2 = ft_printf("this =%05c= is a test\n", 'h');
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%#s= is a test\n", "String");
	r2 = ft_printf("this =%#s= is a test\n", "String");
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%#c= is a test\n", 'h');
	r2 = ft_printf("this =%#c= is a test\n", 'h');
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++ multiple args +++++++++++++++++++++++++++");
	r1 = printf("this %s is a test %s %o %u %x %d\n", "String","So are the folowing numbers", 42, 42, 42, -42);
	r2 = ft_printf("this %s is a test %s %o %u %x %d\n", "String","So are the folowing numbers", 42, 42, 42, -42);
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);
	puts("*******************************************************************");
	r1 = printf("this =%#c= is a test %s\n", 'h', "so is this");
	r2 = ft_printf("this =%#c= is a test %s\n", 'h', "so is this");
	if(r1 == r2)
		puts("return corect");
	else
		printf("correct return = %d, actual return = %d\n",r1,r2);

	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("++++++++++++++++++++++++++++++l++++++++++++++++++++++++++++++++++++");
	printf("this %lo is a test\n", (unsigned long)(1000));
	printf("this %lu is a test\n", (unsigned long)1000);
	printf("this %lx is a test\n", (unsigned long)1000);
	puts("=====================================================================");
	ft_printf("this %lo is a test\n", (unsigned long)1000);
	ft_printf("this %lu is a test\n", (unsigned long)1000);
	ft_printf("this %lx is a test\n", (unsigned long)1000);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("++++++++++++++++++++++++++++++ll+++++++++++++++++++++++++++++++++++");
	printf("this %llo is a test\n", (unsigned long long)1000);
	printf("this %llu is a test\n", (unsigned long long)1000);
	printf("this %llx is a test\n", (unsigned long long)1000);
	puts("=====================================================================");
	ft_printf("this %llo is a test\n", (unsigned long long)1000);
	ft_printf("this %llu is a test\n", (unsigned long long)1000);
	ft_printf("this %llx is a test\n", (unsigned long long)1000);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("++++++++++++++++++++++++++++++h++++++++++++++++++++++++++++++++++++");
	printf("this %ho is a test\n", (unsigned short)(100));
	printf("this %hu is a test\n", (unsigned short)(100));
	printf("this %hx is a test\n", (unsigned short)(100));
	puts("=====================================================================");
	ft_printf("this %ho is a test\n", (unsigned short)(100));
	ft_printf("this %hu is a test\n", (unsigned short)(100));
	ft_printf("this %hx is a test\n", (unsigned short)(100));
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("++++++++++++++++++++++++++++++hh+++++++++++++++++++++++++++++++++++");
	printf("this %hho is a test\n", (unsigned char)(80));
	printf("this %hhu is a test\n", (unsigned char)(80));
	printf("this %hhx is a test\n", (unsigned char)(80));
	puts("=====================================================================");
	ft_printf("this %hho is a test\n", (unsigned char)(80));
	ft_printf("this %hhu is a test\n", (unsigned char)(80));
	ft_printf("this %hhx is a test\n", (unsigned char)(80));
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("++++++++++++++++++++++++++++++j++++++++++++++++++++++++++++++++++++");
	printf("this %jo is a test\n", (uintmax_t)1000);
	printf("this %ju is a test\n", (uintmax_t)1000);
	printf("this %jx is a test\n", (uintmax_t)1000);
	puts("=====================================================================");
	ft_printf("this %jo is a test\n", (uintmax_t)1000);
	ft_printf("this %ju is a test\n", (uintmax_t)1000);
	ft_printf("this %jx is a test\n", (uintmax_t)1000);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("++++++++++++++++++++++++++++++z++++++++++++++++++++++++++++++++++++");
	printf("this %zo is a test\n", (size_t)1000);
	printf("this %zu is a test\n", (size_t)1000);
	printf("this %zx is a test\n", (size_t)1000);
	puts("=====================================================================");
	ft_printf("this %zo is a test\n", (size_t)1000);
	ft_printf("this %zu is a test\n", (size_t)1000);
	ft_printf("this %zx is a test\n", (size_t)1000);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("Game over");
}
