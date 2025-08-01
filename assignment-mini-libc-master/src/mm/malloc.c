// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *ptr = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	if ( ptr == (void*)-1 )
	{
		return NULL;
	}
	int rez = mem_list_add(ptr, size);
	if(rez == 0)
	{
		return ptr;
	}
	return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *ptr = malloc(size*nmemb);
	if(ptr == NULL)
	{
		return NULL;
	}
	memset(ptr, 0, size*nmemb);
	return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	struct mem_list *new_a;
	new_a = mem_list_find(ptr);
	munmap(ptr, new_a->len);
	mem_list_del(ptr);
}
void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	struct mem_list *new_a;
	new_a = mem_list_find(ptr);
    void *rez = mremap(ptr, new_a->len, size, MREMAP_MAYMOVE);
	if ( rez == (void*)-1 )
	{
	return NULL;
	}
	new_a->len = size;
	new_a->start = rez;
	return rez;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	void *new_ptr = realloc(ptr, size*nmemb);
	if ( new_ptr == NULL )
	{
		return NULL;
	}
	memset(new_ptr, 0, size*nmemb);
	return new_ptr;
}
