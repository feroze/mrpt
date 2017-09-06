# Check for Aruco (Only in Linux for now)
# Aruco package uses pkg-config. Does not have it's own cmake module
# ===================================================
SET(CMAKE_MRPT_HAS_ARUCO 0)

IF(NOT CMAKE_MRPT_HAS_ARUCO)

  # Invoke pkg-config for getting the configuration:
  IF(PKG_CONFIG_FOUND)
    PKG_CHECK_MODULES(PKG_ARUCO ${_QUIET} aruco)
    IF (PKG_ARUCO_FOUND)
      SET(CMAKE_MRPT_HAS_ARUCO 1)
      MESSAGE(STATUS "ARUCO_LIBRARIES    : ${PKG_ARUCO_LIBRARIES}")
      MESSAGE(STATUS "ARUCO_INCLUDE_DIRS : ${PKG_ARUCO_INCLUDE_DIRS}")
      MESSAGE(STATUS "ARUCO_LIBRARY_DIRS : ${PKG_ARUCO_LIBRARY_DIRS}")
      MESSAGE(STATUS "ARUCO_LDFLAGS      : ${PKG_ARUCO_LDFLAGS}")
    ELSE(PKG_ARUCO_FOUND)
      SET(CMAKE_MRPT_HAS_ARUCO 0)
    ENDIF (PKG_ARUCO_FOUND)
  ENDIF(PKG_CONFIG_FOUND)

ENDIF(NOT CMAKE_MRPT_HAS_ARUCO)
