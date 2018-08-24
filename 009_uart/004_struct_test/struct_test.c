/**
  *********************************************************************************************************
  * @File               : struct_test.c 
  * @Author             : kang.yunjie 
  * @version            : V1.0 
  * @Date               : 2018-08-05 21:25:14 
  * @Brief              : struct_test
  *********************************************************************************************************
  * @attention          : 
  *                       
  *********************************************************************************************************
  */

#include <stdio.h>

/*
由于在x86(32位机器)平台下，GCC编译器默认按4字节对齐，	
如：结构体4字节对齐,即结构体成员变量所在的内存地址是4的整数倍。

可以通过使用gcc中的__attribute__选项来设置指定的对齐大小。

1）：
__attribute__ ((packed))，让所作用的结构体取消在编译过程中的优化对齐，
按照实际占用字节数进行对齐。

2）：
__attribute((aligned (n)))，让所作用的结构体成员对齐在n字节边界上。
如果结构体中有成员变量的字节长度大于n，
则按照最大成员变量的字节长度来对齐。
*/

struct person {
	char*	name;
	int		age;
	char		score;
	int		id;
};

struct person1 {
	char*	name;
	int		age;
	char		score;
	int		id;
}__attribute__ ((packed));

struct person2 {
	char*	name;
	int		age;
	char		score;
	int		id;
}__attribute((aligned (4)));

/**********************************************************************************************************
 @Function               void
 @Description            main
 @Input                  void
 @Return                 void
**********************************************************************************************************/
int main(int argc, char const *argv[])
{
	struct  person per={"www.100ask.org",10,'A',123};
	
	printf("sizeof(char   )=%d\n",sizeof(char   ));
	printf("sizeof(int    )=%d\n",sizeof(int    ));
	printf("sizeof(char  *)=%d\n",sizeof(char  *));
	printf("sizeof(char **)=%d\n",sizeof(char **));
	printf("sizeof(struct  person)=%d\n",sizeof(struct  person));
	printf("sizeof(struct  person1)=%d\n",sizeof(struct  person1));
	printf("sizeof(struct  person2)=%d\n",sizeof(struct  person2));

	printf("&per.name  =%p,per.name  =%s\n",&per.name ,per.name);
	printf("&per.age   =%p,per.age   =%d\n",&per.age  ,per.age);
	printf("&per.score =%p,per.score =%d\n",&per.score,per.score);
	printf("&per.id    =%p,per.id    =%d\n",&per.id   ,per.id);
	
	return 0;
}

/********************************************** END OF FLEE **********************************************/
