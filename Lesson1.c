#include <stdio.h>

//函数声明，C全局不允许有重名函数不支持函数重载
void swap();
void swapByPoint(int *a,int *b);

int main() {
    int number_int=100;
    double number_double=100.0;

    int *p_number_int=&number_int;
    double *p_number_double=&number_double;

    printf("number_int value==%d\n",number_int);
    printf("number_int value addr==%p\n\n",&number_int);
    printf("p_number_int value==%p\n",p_number_int);
    printf("p_number_int value content==%d\n\n",*p_number_int);

    printf("number_double value==%.2lf\n",number_double);
    printf("number_double value addr==%p\n\n",&number_double);
    printf("p_number_double value==%p\n",p_number_double);
    printf("p_number_double value content==%.2lf\n\n",*p_number_double);

    int number_b_int=200;
    printf("number_int value %d ,number_b_int value %d\n",number_int,number_b_int);

    swap(number_int,number_b_int);//等价于调用swapDecompile();
    printf("swap function result number_int value %d ,number_b_int value %d\n",number_int,number_b_int);

    swapByPoint(&number_int,&number_b_int);//等价于调用swapByPointDecompile();
    printf("swapByPoint function result number_int value %d ,number_b_int value %d\n",number_int,number_b_int);

    getchar();
    return 0;
}

/**
 * C函数的理解：直接把形参以及函数调用的传入值改成赋值语句写入函数的前几行即可理解值的修改
 * 值传递，不修改原始纯如数据
 * @param a
 * @param b
 */
void swap(int a,int b){
    int tempt=a;
    a=b;
    b=tempt;
}

/**
 * 值传递等价函数
 */
void swapDecompile(){
    int a=100;
    int b=200;
    int tempt=a;
    a=b;
    b=tempt;
}

/**
 * 指针传递函数
 * @param a  指针a
 * @param b 指针b
 */
void swapByPoint(int *a,int *b){
    //获取a地址值
    int tempt=*a;
    //修改a地址的值
    *a=*b;
    //修改b地址的值
    *b=tempt;
}

/**
 * 指针传递函数编译后信息
 * @param a  指针a
 * @param b 指针b
 */
void swapByPointDecompile(){

    //中间插入代码
    int number_int=100;
    int number_b_int=200;

    int *a=&number_int;
    int *b=&number_b_int;

    //获取a地址值
    int tempt=*a;
    //修改a地址的值
    *a=*b;
    //修改b地址的值
    *b=tempt;
}
