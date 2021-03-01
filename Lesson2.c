#include <stdio.h>

//第二节：时间：2021-02-25
//课程内容函数指针与指针运算

//t1:多级指针练习，
void t1MultiPoint() {
    //原始数据变量
    int number = 100;
    printf("number value = %d,number address=%p\n", number, &number);

    //一级指针,value=指向变量的地址
    int *p_number = &number;
    printf("p_number value = %p,p_number address=%p, p_number address value=%d\n", p_number, &p_number, *p_number);
    //二级指针,value=指向一级指针变量的地址
    int **pp_number = &p_number;
    printf("pp_number value = %p,pp_number address=%p, pp_number address value=%d\n", pp_number, &pp_number,
           **pp_number);
    //三级指针,value=指向二级指针变量的地址
    int ***ppp_number = &pp_number;
    printf("ppp_number value = %p,ppp_number address=%p, ppp_number address value=%d\n", ppp_number, &ppp_number,
           ***ppp_number);

    //所有指针类型的大小都是一样的和编译器一样，编译器位数/8
    printf("p_number size %llu\npp_number size %llu\nppp_number size %llu,", sizeof(p_number), sizeof pp_number,
           sizeof ppp_number);
}

//t2：数组基本操作：数组地址，长度计算，索引遍历，指针遍历，遍历修改值
void t2Array() {
    //数组创建必须指定长度
    int array[] = {1, 2, 3, 5};
    //数组变量名称
    int *arr = array;

    //数组地址指向第一个元素的地址。
    // 数组变量名称value=数组变量名称的地址=第一个元素的地址

    //arr value 000000000061FDD0
    printf("arr value %p\n", arr);
    //array value 000000000061FDD0
    printf("array value %p\n", array);
    //array address 000000000061FDD0
    printf("array address %p\n", &array);
    //array[0] address 000000000061FDD0
    printf("array[0] address %p\n", &array[0]);


    //c数组内部不支持获取长度操作，需要显示计算
    int arrayLength = sizeof(array) / sizeof(int);
    //数组的长度
    printf("array size:%llu,length==%d\n", sizeof array, arrayLength);

    int index = 0;
    printf("array index search==\n");
    for (index = 0; index < arrayLength; ++index) {
        printf("array[%d]==%d  ", index, array[index]);
    }

    printf("\narray point search==\n");
    for (index = 0; index < arrayLength; ++index) {
        printf("array[%d]==%d  addr=%p", index, *(array + index),array+index);
    }

    printf("\nemptyArray init ==\n");
    int emptyArray[4];
    for (index = 0; index < 4; ++index) {
        emptyArray[index] = index;
    }
    for (index = 0; index < 4; ++index) {
        printf("emptyArray[%d]==%d  ", index, *(array + index));
    }
}

void add(int num1, int num2) {
    printf("add function result:%d\n", num1 + num2);
}

void minus(int num1, int num2) {
    printf("minus function result:%d\n", num1 - num2);
}

//t3:函数指针练习(传入一个函数的作为参数，实现类似java的回调)
void t3FunctionPoint(void (*method)(int, int), int num1, int num2) {
    //函数指针声明：类型 (*方法名)(参数类型列表)
    method(num1, num2);
}


int main() {
//    t1MultiPoint();
//    t2Array();

    void (*callAddMethod)(int, int) =add;
    t3FunctionPoint(callAddMethod, 10, 2);
    t3FunctionPoint(add,10,2);

    void (*callMinusMethod)(int, int) =minus;
    t3FunctionPoint(callMinusMethod, 10, 2);
    t3FunctionPoint(minus,10,2);

    return 0;
}
