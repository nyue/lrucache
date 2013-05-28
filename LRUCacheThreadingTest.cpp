/* 
 *
 * LRUCache - a templated LRU cache class that allows specification of
 * key, value and optionally the map container type (defaults to std::map)
 * By using the std::map and a linked list of keys it allows O(1) 
 * insert, delete and refresh operations
 
 * Copyright (c) 2012-22 SAURAV MOHAPATRA <mohaps@gmail.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
// OpenMP testing of threading in LRUCache
// Nicholas Yue yue.nicholas@gmail.com 
// compile with g++ -o LRUCacheTest LRUCacheTest.cpp
#include <omp.h>
#include <stdio.h>
#define LRUCACHE_REENTRANT
#include "LRUCache.hpp"

int main(int argc, char **argv)
{
	int nthreads, tid;
	const size_t numElements = 1024*1024;
	const size_t cacheSize   = 1024;
	lru::Cache<int,int> cache(cacheSize,0);
    
	/* Fork a team of threads giving them their own copies of variables */
#pragma omp parallel for private(tid)
	for (size_t i=0;i<numElements;i++)
	{
		tid = omp_get_thread_num();
		cache.insert(tid,tid*tid*tid);
		// printf("Looping for thread = %d\n", tid);
	}/* All threads join master thread and disband */
    
	return 0;
}
