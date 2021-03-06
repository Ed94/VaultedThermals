/*!
@file VV_CPP_STL.hpp

@brief C++ STL related definitions
*/



#pragma once



// C++
#include <array>
#include <cstddef>
#include <cstdint>
#include <set>
#include <stdexcept>
#include <typeinfo>
#include <type_traits>

// VV
#include "VV_Vaults.hpp"
#include "VV_APISpecGroups.hpp"
#include "VV_Platform.hpp"



#ifndef VV_Option__Use_Long_Namespace
namespace VV
#else
namespace VaultedVulkan
#endif
{
	namespace Corridors
	{
		/**
		@addtogroup Corridors
		@{
		*/

		// Integers

		// Flexible

		using ui32 = unsigned int;
		using si32 = signed   int;

		// Strict

		// Signed

		using s8  = signed           char;
		using s16 = signed short     int ;
		using s32 = signed long      int ;
		using s64 = signed long long int ;

		// Unsigned

		using u8  = unsigned           char;
		using u16 = unsigned short     int ;
		using u32 = unsigned long      int ;
		using u64 = unsigned long long int ;

		// Floats

		using f32 = float ;
		using f64 = double;

		// Data

		using VoidPtr   =       void*  ;
		using RoVoidPtr = const void*  ;
		using PtrArray  =       void*[];

		// RawStrings

		using CStr              =       char*       ;
		using RoCStr            = const char*       ;
		using CStrArray         =       char*      *;
		using RoCStrArray       = const char*      *;   ///< Readonly c-string array.
		using RoArray_of_RoCStr = const char* const*;   ///< Array of readonly array of readonly c-string.



		/** 
		* @brief Containers used for the library are defined here.
		* 
		* @details
		* 
		* If library user decides to implement their own containers they must define containers
		* that function the same as the STL containers used here with the same names.
		*/
		#ifndef VT_Option__Use_Custom_Containers

			#include <deque>
			#include <vector>

			template<class Type>
			/**
			 * @brief Typdef of std::deque.
			 */
			using Deque = std::deque<Type>;

			template<class Type>
			/**
			 * @brief Typedef of std::vector.
			 */
			using DynamicArray = std::vector<Type>;

		#endif

		/** @} */
	}
}
