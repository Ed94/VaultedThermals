/*
VaultedThermals Include Interface



Summary:
This header acts as a table of contents for the library.

The libraries files are organized based on the Khronos Vulkan Specification manual:
https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html

Each file Starting from the number 2 represents a chapter/category of the manual.
Files may have non-specification within them.

Content related directly to the Vulkan API will have a link to its respective specification.

Files that do not follow specification are labeled with an NS-# in their comment below.

Features that would be nice to have:
Have support for object model enforcement. 
*/



#pragma once



// NS-1: Platform detection and includes the C-API vulkan header.
#include "VaultedThermals/VT_Platform.hpp"

/* 2: Fundamental Typedefs, Common Object Types, Non-Specification Types.

https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#fundamentals
*/
#include "VaultedThermals/VT_Types.hpp"

// NS-2: Unsorted global enum definitions.
#include "VaultedThermals/VT_Enums.hpp"

// NS-3: Unsorted constants.
#include "VaultedThermals/VT_Constants.hpp"

/* 1: Command function pointers, application instancing.

https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#initialization
*/
#include "VaultedThermals/VT_Initalization.hpp"



#include "VaultedThermals/VT_Layer.hpp"
#include "VaultedThermals/VT_Debug.hpp"
#include "VaultedThermals/VT.hpp"
#include "VaultedThermals/VT_PhysicalDevice.hpp"
#include "VaultedThermals/VT_LogicalDevice.hpp"
#include "VaultedThermals/VT_Surface.hpp"
#include "VaultedThermals/VT_SwapChain.hpp"
#include "VaultedThermals/VT_ImageView.hpp"
#include "VaultedThermals/VT_ShaderModule.hpp"
#include "VaultedThermals/VT_Pipeline.hpp"
