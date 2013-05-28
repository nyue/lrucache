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
 
// Sample test file
// compile with g++ -o LRUCacheTest LRUCacheTest.cpp
#include "LRUCache.hpp"
namespace lru
{
	typedef std::string String;
	void test()
	{
		lru::Cache<String, String> cache(3,0);
		cache.insert("hello", "world");
		cache.insert("foo", "bar");
#ifndef __APPLE__
		cache.dumpDebug(std::cout<<"--> After 2 inserts"<<std::endl);
#endif // __APPLE__
		
		std::cout<<"checking refresh : "<<cache.get("hello")<<std::endl;
#ifndef __APPLE__
		cache.dumpDebug(std::cout<<"--> After refeshing oldest key"<<std::endl);
#endif // __APPLE__
		
		cache.insert("hello1", "world1");
		cache.insert("foo1", "bar1");
#ifndef __APPLE__
		cache.dumpDebug(std::cout<<"--> After adding two more"<<std::endl);
#endif // __APPLE__
	}
}

int main(int argc, char **argv)
{
	lru::test();
	return 0;
}
