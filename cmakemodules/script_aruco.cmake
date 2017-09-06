# Check for Aruco (Only in Linux for now)
# Aruco package uses pkg-config. Does not have it's own cmake module
# ===================================================
SET(CMAKE_MRPT_HAS_ARUCO 0)

IF(NOT CMAKE_MRPT_HAS_ARUCO)

  # Invoke pkg-config for getting the configuration:
  IF(PKG_CONFIG_FOUND)
    PKG_CHECK_MODULES(ARUCO ${_QUIET} aruco)
    IF (ARUCO_FOUND)
      SET(CMAKE_MRPT_HAS_ARUCO 1)
      MESSAGE(STATUS "ARUCO_LIBRARIES    : ${ARUCO_LIBRARIES}")
      MESSAGE(STATUS "ARUCO_INCLUDE_DIRS : ${ARUCO_INCLUDE_DIRS}")
      MESSAGE(STATUS "ARUCO_LIBRARY_DIRS : ${ARUCO_LIBRARY_DIRS}")
      MESSAGE(STATUS "ARUCO_LDFLAGS      : ${ARUCO_LDFLAGS}")

    ELSE(ARUCO_FOUND)
      SET(CMAKE_MRPT_HAS_ARUCO 0)
    ENDIF (ARUCO_FOUND)
  ENDIF(CONFIG_FOUND)

ENDIF(NOT CMAKE_MRPT_HAS_ARUCO)
