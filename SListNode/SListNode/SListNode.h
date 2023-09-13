#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <Windows.h>

// 1、无头+单向+非循环链表增删查改实现
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x);
// 单链表打印
void SListPrint(SListNode* plist);
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x);
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x);
// 单链表的尾删
void SListPopBack(SListNode** pplist);
// 单链表头删
void SListPopFront(SListNode** pplist);
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x);
// 单链表在pos位置之前插入x
void SListInsert(SListNode** pplist, SListNode* pos, SLTDateType x);
// 单链表删除pos位置的值
void SListErase(SListNode** pplist, SListNode* pos);