# Copyright 2023 Proyectos y Sistemas de Mantenimiento SL (eProsima).
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

###############################################################################
# XML validation
###############################################################################
message(STATUS "Configuring CLI xml validation...")

# Copy the neccessary files over to the build directory
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/profileAll.xml
    ${CMAKE_CURRENT_BINARY_DIR}/xmldocuments/profileAll.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/profileDataReader.xml
    ${CMAKE_CURRENT_BINARY_DIR}/xmldocuments/profileDataReader.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/profileDataWriter.xml
    ${CMAKE_CURRENT_BINARY_DIR}/xmldocuments/profileDataWriter.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/profileDomainParticipant.xml
    ${CMAKE_CURRENT_BINARY_DIR}/xmldocuments/profileDomainParticipant.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/profileTransportDescriptor.xml
    ${CMAKE_CURRENT_BINARY_DIR}/xmldocuments/profileTransportDescriptor.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/profileLog.xml
    ${CMAKE_CURRENT_BINARY_DIR}/xmldocuments/profileLog.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/profileTypes.xml
    ${CMAKE_CURRENT_BINARY_DIR}/xmldocuments/profileTypes.xml COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/XMLTesterExample.xml
    ${CMAKE_CURRENT_BINARY_DIR}/xmldocuments/XMLTesterExample.xml COPYONLY)


# Check XML profile validation against schema
add_test(NAME xml.validate_samples COMMAND fastdds xml validate xmldocuments)

# Check the XML from examples (that follows the xsd schema, avoid static discovery xmls)
add_test(NAME xml.validate_examples_1 COMMAND fastdds xml validate ../../examples/cpp/dds/DynamicHelloWorldExample)
add_test(NAME xml.validate_examples_2 COMMAND fastdds xml validate ../../examples/cpp/dds/TypeLookupService)

# Check the XML from tests (that follows the xsd schema, avoid static discovery xmls or bad structured on purpose xmls)
add_test(NAME xml.validate_tests_blackbox_1 COMMAND fastdds xml validate ../blackbox/discovery_participant_flags.xml)
add_test(NAME xml.validate_tests_blackbox_2 COMMAND fastdds xml validate ../blackbox/partitions.xml)
add_test(NAME xml.validate_tests_blackbox_3 COMMAND fastdds xml validate ../blackbox/persistence.xml)
add_test(NAME xml.validate_tests_blackbox_4 COMMAND fastdds xml validate ../blackbox/StatisticsDomainParticipant.xml)
add_test(NAME xml.validate_tests_communication COMMAND fastdds xml validate ../communication)
add_test(NAME xml.validate_tests_dds COMMAND fastdds xml validate ../dds)
add_test(NAME xml.validate_tests_unittest_1 COMMAND fastdds xml validate ../unittest/dds)
add_test(NAME xml.validate_tests_unittest_2 COMMAND fastdds xml validate ../unittest/dynamic_types)
add_test(NAME xml.validate_tests_unittest_3 COMMAND fastdds xml validate ../unittest/xmlparser/log_inactive.xml)
add_test(NAME xml.validate_tests_unittest_4 COMMAND fastdds xml validate ../unittest/xmlparser/test_xml_profiles.xml)
add_test(NAME xml.validate_tests_unittest_5 COMMAND fastdds xml validate ../unittest/xmlparser/tls_config.xml)
add_test(NAME xml.validate_tests_unittest_6 COMMAND fastdds xml validate ../unittest/xmlparser/log_node_file_append.xml)
add_test(NAME xml.validate_tests_unittest_7 COMMAND fastdds xml validate ../unittest/xmlparser/UDP_transport_descriptors_config.xml)
add_test(NAME xml.validate_tests_unittest_8 COMMAND fastdds xml validate ../unittest/xmlparser/log_def_file.xml)
add_test(NAME xml.validate_tests_unittest_9 COMMAND fastdds xml validate ../unittest/xmlparser/log_stdouterr_two_thresholds.xml)
add_test(NAME xml.validate_tests_unittest_10 COMMAND fastdds xml validate ../unittest/xmlparser/test_xml_profiles_rooted.xml)
add_test(NAME xml.validate_tests_unittest_11 COMMAND fastdds xml validate ../unittest/xmlparser/test_xml_root_library_settings.xml)
add_test(NAME xml.validate_tests_unittest_12 COMMAND fastdds xml validate ../unittest/xmlparser/test_xml_duration.xml)
add_test(NAME xml.validate_tests_unittest_13 COMMAND fastdds xml validate ../unittest/xmlparser/SHM_transport_descriptors_config.xml)
add_test(NAME xml.validate_tests_unittest_14 COMMAND fastdds xml validate ../unittest/xmlparser/log_stdouterr.xml)
add_test(NAME xml.validate_tests_unittest_15 COMMAND fastdds xml validate ../unittest/xmlparser/test_xml_security_profiles.xml)
if(PERFORMANCE_TESTS)
    add_test(NAME xml.validate_tests_performance COMMAND fastdds xml validate ../performance)
endif()
if(PROFILING_TESTS)
    add_test(NAME xml.validate_tests_profiling COMMAND fastdds xml validate ../profiling)
endif()
if(SYSTEM_TESTS)
    add_test(NAME xml.validate_tests_system COMMAND fastdds xml validate ../system)
endif()