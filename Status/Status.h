#ifndef STATUS_STATUS_H
#define STATUS_STATUS_H

#include <limits.h>

#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

#define MAXSIZE 100       // 顺序表可能达到的最大长度,但后续可动态扩充
#define MAXQSIZE 100
#define CHUNKSIZE 80      // 可由用户定义的块大小
#define MAXSTRLEN 600     // 用户可在600以内定义最长串长
#define MAXTSIZE 100      // 二叉树的最大节点数
#define MAXTREESIZE 100   // 树中最多结点数

typedef int Status;       // Status是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType;     // ElemType为可定义的数据类型，此设为int类型
typedef char SElemType;
typedef char QElemType;
typedef int AtomType;
typedef int TElemType;

#define MAX_ARRAY_DIM 8   // 假设数组维数的最大值为8


#define MaxInt INT_MAX                        // 表示极大值，即∞
#define MVNum 100                        // 最大顶点数

typedef char VerTexType;                    // 假设顶点的数据类型为字符型
typedef int ArcType;                        // 假设边的权值类型为整型

typedef char VerTexType;                      // 顶点信息
typedef int OtherInfo;                        // 和边相关的信息

#define MAX_VERTEX_NUM 20
typedef int InfoType;
typedef int VertexType;

#define MAX_VERTEX_NUM 20
#define BDNum MVNum * (MVNum - 1)            // 最大边数

typedef int KeyType;

#define ENDFLAG '#'

typedef char KeysType;                    //定义关键字类型为字符型
typedef int InfoType;                    //定义其它数据项的类型
#define MAXNUM_KEY 8                    //关键字项数的最大值
#define RADIX 10                        //关键字基数，此时是十进制整数的基数
#define MAX_SPACE 10000

#define FALSE 0
#define TRUE 1
#define OK 1
//#define m 3                        // B-树的阶，暂设为3

typedef int Record;

#define NULLKEY 0                 			//单元为空的标记
#endif //STATUS_STATUS_H