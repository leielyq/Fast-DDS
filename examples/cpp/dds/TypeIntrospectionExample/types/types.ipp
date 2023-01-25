// Copyright 2022 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file types.hpp
 *
 */

#ifndef _EPROSIMA_FASTDDS_EXAMPLES_CPP_DDS_TYPEINTROSPECTIONEXAMPLE_TYPES_TYPES_IPP_
#define _EPROSIMA_FASTDDS_EXAMPLES_CPP_DDS_TYPEINTROSPECTIONEXAMPLE_TYPES_TYPES_IPP_

template <DataTypeKind Data, GeneratorKind Gen>
DataType<Data, Gen>::DataType()
    : dyn_type_(generate_type_())
{
}

template <DataTypeKind Data, GeneratorKind Gen>
std::string DataType<Data, Gen>::name() const
{
    // This method is generic to avoid implementing the same code for each Generator
    // because C++ does not allow partial specialization of methods.
    switch (Data)
    {
        case DataTypeKind::HELLO_WORLD:
            return HELLO_WORLD_DATA_TYPE_NAME;

        case DataTypeKind::ARRAY:
            return ARRAY_DATA_TYPE_NAME;

        case DataTypeKind::STRUCT:
            return STRUCT_DATA_TYPE_NAME;

        case DataTypeKind::PLAIN:
            return PLAIN_DATA_TYPE_NAME;

        case DataTypeKind::KEY:
            return KEY_DATA_TYPE_NAME;

        case DataTypeKind::COMPLEX:
            return COMPLEX_DATA_TYPE_NAME;

        default:
            throw std::runtime_error("Unsupported data type");
    }
}

template <DataTypeKind Data, GeneratorKind Gen>
eprosima::fastrtps::types::DynamicData_ptr DataType<Data, Gen>::get_data(
        const unsigned int& index) const
{
    return get_data_by_type<Data>(index, dyn_type_);
}

template <DataTypeKind Data, GeneratorKind Gen>
eprosima::fastrtps::types::DynamicType_ptr DataType<Data, Gen>::get_type() const
{
    return dyn_type_;
}

#endif /* _EPROSIMA_FASTDDS_EXAMPLES_CPP_DDS_TYPEINTROSPECTIONEXAMPLE_TYPES_TYPES_IPP_ */
