#ifndef STATUS_STATUS_H
#define STATUS_STATUS_H


#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

#define MAXSIZE 100       //顺序表可能达到的最大长度,但后续可动态扩充
#define MAXQSIZE 100
#define MAXSTRLEN 255     //用户可在255以内定义最长串长

typedef int Status;       //Status是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType;     //ElemType为可定义的数据类型，此设为int类型
typedef char SElemType;
typedef char QElemType;


#endif //STATUS_STATUS_H