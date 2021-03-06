CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ENABLE_TESTING()

PROJECT ( LRUCache )

FIND_PACKAGE ( OpenMP )

IF ( NOT APPLE )
  ADD_DEFINITIONS ( -std=c++0x )
ELSE ()
  FIND_PACKAGE ( Boost COMPONENTS thread system )
  INCLUDE_DIRECTORIES ( ${Boost_INCLUDE_DIR} )
ENDIF ()

ADD_EXECUTABLE ( LRUCacheTest
  LRUCacheTest.cpp
)

ADD_EXECUTABLE ( LRUCacheThreadingTest
  LRUCacheThreadingTest.cpp
)

TARGET_LINK_LIBRARIES ( LRUCacheThreadingTest
  ${Boost_LIBRARIES}
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
