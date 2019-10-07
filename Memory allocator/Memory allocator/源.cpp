#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
// 内存对齐，至少应该是mem_block的大小，而且应该是4的整数倍
#define ALIGNMENT 8

// 初始化堆的大小
#define HEAP_SIZE 10000

// 控制信息结构体
struct mem_block
{
	int size;    // 本块的大小
	int is_free; // 是否已分配
};
typedef struct mem_block mem_block;

// 堆的起始地址和结束地址
void *g_heap_start = 0;
void *g_heap_end = 0;

bool g_heap_inited = false;

// 初始化堆
void init_simple_malloc()
{
	g_heap_inited = true;
	g_heap_start = malloc(HEAP_SIZE);
	if (g_heap_start == 0)
		return;
	mem_block* pos = (mem_block*)g_heap_start;
	pos->size = HEAP_SIZE;
	pos->is_free = 1;
	g_heap_end = (void*)((char*)g_heap_start + HEAP_SIZE - 1);

}

// 内部使用的分配内存函数
void *_simple_malloc(size_t size)
{
	if (g_heap_start == 0)
		return 0;
	// 调整内存大小，满足对齐要求
	size = (size + ALIGNMENT - 1) & (~(ALIGNMENT - 1));
	mem_block *pos = (mem_block*)g_heap_start;
	while ((void*)pos < g_heap_end)
	{
		// 最先适应法
		if (pos->is_free && pos->size >= sizeof(mem_block)+size)
		{
			if (pos->is_free == sizeof(mem_block)+size)
				pos->is_free = 0;
			else
			{
				// 取出需要的大小，剩下的成为堆中的一个新块
				mem_block *next_pos = (mem_block*)((char*)pos + sizeof(mem_block)+size);
				next_pos->is_free = 1;
				next_pos->size = pos->size - sizeof(mem_block)-size;
				pos->is_free = 0;
				pos->size = sizeof(mem_block)+size;
				return (void*)((char*)pos + sizeof(mem_block));
			}
			return (void*)((char*)pos + sizeof(mem_block));
		}
		else
			pos = (mem_block*)((char*)pos + pos->size);
	}
	return 0;
}

// 内部使用的合并空闲块函数
void _merge_free_blocks()
{
	mem_block *pos = (mem_block*)g_heap_start;
	while ((void*)((char*)pos + pos->size) < g_heap_end)
	{
		mem_block *next_pos = (mem_block*)((char*)pos + pos->size);
		// 若相邻的两个块都是空闲，合二为一
		if (pos->is_free && next_pos->is_free)
			pos->size = pos->size + next_pos->size;
		else
			pos = next_pos;
	}
	return;
}

// 外部使用的内存分配函数
void *simple_malloc(size_t size)
{
	if (!g_heap_inited)
		init_simple_malloc();
	void * pos = _simple_malloc(size);
	if (pos)
		return pos;
	// 若第一次分配内存失败，则进行合并空闲块，再次尝试分配
	_merge_free_blocks();
	return _simple_malloc(size);
}

// 外部使用的内存释放函数
void simple_free(void *p)
{
	mem_block * pos = (mem_block*)((char*)p - sizeof(mem_block));
	// 释放仅需标记一下
	pos->is_free = 1;
	return;
}

// 测试使用的打印堆信息函数
void print_heap_info()
{
	mem_block *pos = (mem_block*)g_heap_start;
	puts("Heap info:");
	while ((void*)pos < g_heap_end)
	{
		// 输出堆中所有控制块的起始地址，大小，使用情况
		printf("mem_block info: start_addr, %d; size, %d; is_free, %d\n", pos, pos->size, pos->is_free);
		pos = (mem_block*)((char*)pos + pos->size);
	}
	putchar('\n');
	return;
}

int main()
{
	void *p1 = simple_malloc(3000);
	// 状态一
	puts("State 1");
	print_heap_info();

	void *p2 = simple_malloc(5000);
	// 状态二
	puts("State 2");
	print_heap_info();

	void *p3 = simple_malloc(1000);
	// 状态三
	puts("State 3");
	print_heap_info();

	simple_free(p1);
	simple_free(p2);
	simple_free(p3);
	// 状态四
	puts("State 4");
	print_heap_info();

	void *p4 = simple_malloc(8000);
	// 状态五
	puts("State 5");
	print_heap_info();

	simple_free(p4);
	// 状态六
	puts("State 6");
	print_heap_info();
	system("pause");
	return 0;
}