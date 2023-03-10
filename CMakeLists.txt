cmake_minimum_required(VERSION 3.12)

# Set some basic project attributes
project (Osal
		VERSION 0.0.0.1
		DESCRIPTION "OSAL VxWorks")
		
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

file(GLOB SOURCES "src/*/*.cpp")

add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Create a simple configuration header
configure_file(config.h.in config.h)

include_directories("${PROJECT_BINARY_DIR}" include)

message("CMAKE_PROJECT_VERSION = ${CMAKE_PROJECT_VERSION}")

IF(EXISTS "${WIND_CC_SYSROOT}/secureLoader/privatekey.pem")
	IF(EXISTS "${WIND_CC_SYSROOT}/secureLoader/publiccert.pem")
		add_custom_command(TARGET ${MY_TARGET} POST_BUILD
			COMMAND echo "start singtool command ..."
			COMMAND signtool --strip=all --key=${WIND_CC_SYSROOT}/secureLoader/privatekey.pem --cert=${WIND_CC_SYSROOT}/secureLoader/publiccert.pem --type=ELF ${MY_TARGET}
			COMMENT  "end singtool command ..."
		)
	ENDIF()
ENDIF()
