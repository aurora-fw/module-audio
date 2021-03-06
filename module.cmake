# ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
# ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
# ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
# A Powerful General Purpose Framework
# More information in: https://aurora-fw.github.io/
#
# Copyright (C) 2017 Aurora Framework, All rights reserved.
#
# This file is part of the Aurora Framework. This framework is free
# software; you can redistribute it and/or modify it under the terms of
# the GNU Lesser General Public License version 3 as published by the
# Free Software Foundation and appearing in the file LICENSE included in
# the packaging of this file. Please review the following information to
# ensure the GNU Lesser General Public License version 3 requirements
# will be met: https://www.gnu.org/licenses/lgpl-3.0.html.

message(STATUS "Loading audio module...")

if (NOT CONFIGURED_ONCE)
	set(AURORAFW_MODULE_AUDIO_SOURCE_DIR ${AURORAFW_MODULE_AUDIO_DIR}/src)
endif()

IF(DEFINED AURORAFW_IS_BUILDING)
	AURORAFW_ADD_CMAKE_MODULE("PortAudio" CMAKE ${AURORAFW_ROOT_DIR}/cmake/portaudio)
	AURORAFW_ADD_CMAKE_MODULE("sndfile" CMAKE ${AURORAFW_ROOT_DIR}/cmake/sndfile)
ELSE()
	find_package(PortAudio REQUIRED)
	find_package(sndfile REQUIRED)
ENDIF()

include_directories(${AURORAFW_MODULE_AUDIO_DIR}/include ${OPENAL_INCLUDE_DIR})

file(GLOB_RECURSE AURORAFW_MODULE_AUDIO_HEADERS ${AURORAFW_MODULE_AUDIO_DIR}/include/*.*)
file(GLOB_RECURSE AURORAFW_MODULE_AUDIO_SOURCE ${AURORAFW_MODULE_AUDIO_SOURCE_DIR}/*.cpp)

add_library (aurorafw-audio SHARED ${AURORAFW_MODULE_AUDIO_SOURCE})
if(AURORAFW_PCH)
	add_precompiled_header(aurorafw-audio "${AURORAFW_MODULE_AUDIO_HEADERS}")
endif()

target_link_libraries(aurorafw-audio aurorafw-core aurorafw-cli ${PortAudio_LIBRARIES} ${sndfile_LIBRARIES})

set_target_properties(aurorafw-audio PROPERTIES OUTPUT_NAME aurorafw-audio)
