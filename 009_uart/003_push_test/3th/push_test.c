/**
  *********************************************************************************************************
  * @File               : push_test.c 
  * @Author             : kang.yunjie 
  * @version            : V1.0 
  * @Date               : 2018-08-05 20:09:12 
  * @Brief              : push_test
  *********************************************************************************************************
  * @attention          : 
  *                       
  *********************************************************************************************************
  */

#include <stdio.h>
#include <stdarg.h>

struct person {
	char*	name;
	int		age;
	char		score;
	int		id;
};

/**********************************************************************************************************
 @Function               int push_test(const char *format, ...)
 @Description            push_test
 @Input                  void
 @Return                 void
**********************************************************************************************************/
int push_test(const char *format, ...)
{
	int i;
	struct person per;
	char c;
	double d;
	va_list p;
	
	va_start(p, format);
	
	printf("arg1 : %s\n", format);
	
	i = va_arg(p, int);
	printf("arg2 : %d\n", i);
	
	per = va_arg(p, struct person);
	printf("arg3 :\n\t.name = %s,\n\t.age = %d,\n\t.score = %c,\n\t.id = %d\n", per.name, per.age, per.score, per.id);
	
	c = va_arg(p, int);
	printf("arg4 : %c\n", c);
	
	d = va_arg(p, double);
	printf("arg5 : %lf\n", d);
	
	va_end(p);
	
	return 0;
}

/**********************************************************************************************************
 @Function               void
 @Description            main
 @Input                  void
 @Return                 void
**********************************************************************************************************/
int main(int argc, char const *argv[])
{
	struct person per = {"Kang.yunjie", 10, 'A', 123};
	
	printf("sizeof(char   )=%d\n",sizeof(char   ));
	printf("sizeof(int    )=%d\n",sizeof(int    ));
	printf("sizeof(char  *)=%d\n",sizeof(char  *));
	printf("sizeof(char **)=%d\n",sizeof(char **));
	printf("sizeof(struct  person)=%d\n",sizeof(struct  person));
	
	push_test("abcde", 123, per, 'C', 2.79);
	
	return 0;
}

/********************************************** END OF FLEE **********************************************/
