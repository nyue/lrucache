CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ENABLE_TESTING()

PROJECT ( LRUCache )

FIND_PACKAGE ( OpenMP )

ADD_DEFINITIONS ( -std=c++0x )

ADD_EXECUTABLE ( LRUCacheTest
  LRUCacheTest.cpp
)

ADD_EXECUTABLE ( LRUCacheThreadingTest
  LRUCacheThreadingTest.cpp
)

TARGET_LINK_LIBRARIES ( LRUCacheThreadingTest
  gomp
  )

SET_TARGET_PROPERTIES ( LRUCacheThreadingTest PROPERTIES COMPILE_FLAGS ${OpenMP_CXX_FLAGS} )

ADD_TEST ( Test01 LRUCacheTest )
ADD_TEST ( Test02 LRUCacheThreadingTest )

INSTALL ( FILES
  LRUCache.hpp
  DESTINATION
  include
  )
