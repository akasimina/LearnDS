//
//  Zuma.hpp
//  DS
//
//  Created by 周子朋 on 2023/4/2.
//

#ifndef Zuma_hpp
#define Zuma_hpp

#include <iostream>
using namespace std;

struct Ball{
    char data = ' ';
    Ball* pri = NULL;
    Ball* next = NULL;
};

/* 插入函数, 返回插入位置的Ball指针*/
Ball* InsertBall(int index, char data, Ball* header);

/* 删除函数, 返回前向指针*/
Ball* DeleteIt(Ball* pointer);

/* 递归计数*/
int RecursiveCountN(Ball* pointer, char data); /*后向*/
int RecursiveCountP(Ball* pointer, char data); /* 前向*/

/* 展示函数*/
void displayLink(Ball* header);


#endif /* Zuma_hpp */
