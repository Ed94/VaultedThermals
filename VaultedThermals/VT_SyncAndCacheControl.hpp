/*
@file VT_SyncAndCacheControl

@brief Vaulted Thermals: Synchronization and Cache Control

@details
<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#synchronization">Specification</a> 
*/



#pragma once



// VT
#include "VT_Vaults.hpp"
#include "VT_Platform.hpp"
#include "VT_CPP_STL.hpp"
#include "VT_Enums.hpp"
#include "VT_Backend.hpp"
#include "VT_Types.hpp"
#include "VT_Constants.hpp"
#include "VT_Memory_Corridors.hpp"
#include "VT_PhysicalDevice.hpp"
#include "VT_Initialization.hpp"
#include "VT_LogicalDevice.hpp"
#include "VT_Memory.hpp"
#include "VT_Sampler.hpp"
#include "VT_Resource.hpp"



#ifndef VT_Option__Use_Short_Namespace
	namespace VaultedThermals
#else
	namespace VT
#endif
{
	namespace Vault_1
	{
		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#synchronization-events">Specification</a> 
		 */
		struct Event
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkEvent">Specification</a>  */
			using Handle = VkEvent;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkEventCreateInfo">Specification</a>  */
			struct CreateInfo : Vault_0::VKStruct_Base<VkEventCreateInfo, EStructureType::Event_CreateInfo>
			{
				using CreateFlags = Bitmask<EUndefined, VkEventCreateFlags>;

				      EType       SType;
				const void*       Next ;
				      CreateFlags Flags;
			};

			/**
			 * @brief.
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateEvent">Specification</a> 
			 * 
			 * \param _device
			 * \param _createInfo
			 * \param _allocator
			 * \param _event
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle        _device    ,
				const Event::CreateInfo&           _createInfo,
				const Memory::AllocationCallbacks* _allocator ,
				      Handle*                      _event
			)
			{
				return EResult(vkCreateEvent(_device, _createInfo, _allocator->operator const VkAllocationCallbacks*(), _event));
			}

			/**
			 * @brief 
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyEvent">Specification</a> 
			 * 
			 * \param _device
			 * \param _event
			 * \param _allocator
			 */
			static void Destroy
			(
				      LogicalDevice::Handle        _device   ,
				      Handle                       _event    ,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				vkDestroyEvent(_device, _event, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetEventStatus">Specification</a> 
			 * 
			 * \param device
			 * \param event
			 * \return 
			 */
			static EResult GetStatus(LogicalDevice::Handle _device, Handle _event)
			{
				vkGetEventStatus(_device, _event);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkResetEvent">Specification</a> 
			 * 
			 * \param _device
			 * \param _event
			 * \return 
			 */
			static EResult Reset(LogicalDevice::Handle _device, Handle _event)
			{
				vkResetEvent(_device, _event);
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkSetEvent">Specification</a> 
			 * 
			 * \param _device
			 * \param _event
			 * \return 
			 */
			static EResult Set(LogicalDevice::Handle _device, Handle _event)
			{
				vkSetEvent(_device, _event);
			}
		};

		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#synchronization-fences">Specification</a> 
		 */
		struct Fence
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFence">Specification</a>  */
			using Handle = VkFence;

			using EExternalHandleTypeFlag = EExternalFenceHandleTypeFlag;

			static constexpr Handle NullHandle = Handle(EHandle::Null);

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFenceCreateFlags">Specification</a> 
			 */
			using CreateFlags = Bitmask<EFenceCreateFlag, VkFenceCreateFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExternalFenceHandleTypeFlags">Specification</a>  */
			using ExternalHandleFlags = Bitmask<EExternalFenceHandleTypeFlag, VkExternalFenceHandleTypeFlags>;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFenceCreateInfo">Specification</a> 
			 */
			struct CreateInfo : Vault_0::VKStruct_Base<VkFenceCreateInfo, EStructureType::Fence_CreateInfo>
			{
				      EType       SType;
				const void*       Next ;
				      CreateFlags Flags;
			};

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDeviceEventInfoEXT">Specification</a> 
			*/
			struct DeviceEventInfo : Vault_0::VKStruct_Base<VkDeviceEventInfoEXT, EStructureType::Device_EventInfo_EXT>
			{
				      EType            SType      ;
				const void*            Next       ;
				      EDeviceEventType DeviceEvent;
			};

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkDisplayEventInfoEXT">Specification</a> 
			*/
			struct DisplayEventInfo : Vault_0::VKStruct_Base<VkDisplayEventInfoEXT, EStructureType::Display_EventInfo_EXT>
			{
				      EType             SType       ;
				const void*             Next        ;
				      EDisplayEventType DisplayEvent;
			};

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExportFenceWin32HandleInfoKHR">Specification</a> 
			*/
			struct ExportableWin32 : Vault_0::VKStruct_Base<VkExportFenceWin32HandleInfoKHR, EStructureType::ExportFence_Win32Handle_Info_KHR>
			{
				      EType                SType     ;
				const void*                Next      ;
				const SECURITY_ATTRIBUTES* Attributes;
				      DWORD                DW_Access ;
				      LPCWSTR              Name      ;
			};

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFenceGetFdInfoKHR">Specification</a> 
			*/
			struct GetPOSIX_FileDescriptorInfo : Vault_0::VKStruct_Base<VkFenceGetFdInfoKHR, EStructureType::Fence_Get_FD_Info_KHR>
			{
				      EType                        SType     ;
				const void*                        Next      ;
				      Handle                       Fence     ;
					  EExternalHandleTypeFlag HandleType;
			};

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFenceGetWin32HandleInfoKHR">Specification</a> 
			*/
			struct GetWin32HandleInfo : Vault_0::VKStruct_Base<VkFenceGetWin32HandleInfoKHR, EStructureType::Fence_GetWin32Handle_Info_KHR>
			{
				      EType                        SType     ;
				const void*                        Next      ;
				      Handle                       Fence     ;
					  EExternalHandleTypeFlag HandleType;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImportFenceFdInfoKHR">Specification</a>
			 */
			struct ImportFencePOSIX_FileDescriptorInfo : Vault_0::VKStruct_Base<VkImportFenceFdInfoKHR, EStructureType::ImportFence_FD_Info_KHR>
			{
				      EType                        SType         ;
				const void*                        Next          ;
				      Handle                       Fence         ;
				      FenceImportFlags             Flags         ;
					  EExternalHandleTypeFlag HandleType    ;
				      int                          FileDescriptor;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImportFenceWin32HandleInfoKHR">Specification</a> 
			 */
			struct ImportFenceWin32HandleInfo : Vault_0::VKStruct_Base<VkImportFenceWin32HandleInfoKHR, EStructureType::ImportFence_Win32Handle_Info_KHR>
			{
				      EType                        SType     ;
				const void*                        Next      ;
				      Handle                       Fence     ;
					  FenceImportFlags             Flags     ;
					  EExternalHandleTypeFlag HandleType;
				      HANDLE                       Handle    ;
				      LPCWSTR                      Name      ;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExportFenceCreateInfo">Specification</a> 
			 */
			struct ExportCreateInfo : Vault_0::VKStruct_Base<VkExportFenceCreateInfo, EStructureType::ExportFence_CreateInfo>
			{
				      EType               SType      ;
				const void*               Next       ;
				      ExternalHandleFlags HandleTypes;
			};


			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateFence">Specification</a> 
			 * 
			 * \param _logicalDevice
			 * \param _createInfo
			 * \param _allocator
			 * \param _fence
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle        _logicalDevice,
				const CreateInfo&                  _createInfo   ,
				const Memory::AllocationCallbacks* _allocator    ,
				      Handle&                      _fence
			)
			{
				return EResult(vkCreateFence(_logicalDevice, _createInfo, _allocator->operator const VkAllocationCallbacks*(), &_fence));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyFence">Specification</a> 
			 * 
			 * \param _logicalDevice
			 * \param _fence
			 * \param _allocator
			 */
			static void Destroy
			(
				      LogicalDevice::Handle        _logicalDevice,
				      Fence::Handle                _fence        ,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				vkDestroyFence(_logicalDevice, _fence, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetFenceStatus">Specification</a> 
			 * 
			 * \param _logicalDevice
			 * \param _fence
			 * \return 
			 */
			static EResult GetStatus(LogicalDevice::Handle _logicalDevice, Fence::Handle _fence)
			{
				return EResult(vkGetFenceStatus(_logicalDevice, _fence));
			}

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetFenceWin32HandleKHR">Specification</a>  
			* \return 
			*/
			static EResult GetWin32Handle
			(
				      LogicalDevice::Handle _device            ,
				const GetWin32HandleInfo&   _getWin32HandleInfo,
				      HANDLE*               _handle
			)
			{
				return EResult(vkGetFenceWin32HandleKHR(_device, _getWin32HandleInfo, _handle));
			}

			/**
			* @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetFenceFdKHR">Specification</a>  
			* 
			* \param device
			* \param pGetFdInfo
			* \param pFd
			* \return 
			*/
			static EResult GetPOSIX_FileDescriptor
			(
				      LogicalDevice::Handle        _device        ,
				const GetPOSIX_FileDescriptorInfo& _fdInfo        ,
				      int*                         _fileDescriptor
			)
			{
				return EResult(vkGetFenceFdKHR(_device, _fdInfo, _fileDescriptor));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkImportFenceFdKHR">Specification</a>
			 * 
			 * \param _device
			 * \param _importInfo
			 * \return 
			 */
			static EResult ImportFence_POSIX_FileDescriptor
			(
				      LogicalDevice::Handle                _device    ,
				const ImportFencePOSIX_FileDescriptorInfo& _importInfo
			)
			{
				return EResult(vkImportFenceFdKHR(_device, _importInfo));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkImportFenceWin32HandleKHR">Specification</a> 
			 * 
			 * \param device
			 * \param pImportFenceWin32HandleInfo
			 * \return 
			 */
			static EResult ImportFenceWin32Handle
			(
				      LogicalDevice::Handle       _device    ,
				const ImportFenceWin32HandleInfo& _importInfo
			)
			{
				return EResult(vkImportFenceWin32HandleKHR(_device, _importInfo));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkRegisterDeviceEventEXT">Specification</a> 
			 * 
			 * \param device
			 * \param pDeviceEventInfo
			 * \param pAllocator
			 * \param pFence
			 * \return 
			 */
			static EResult RegisterDeviceEvent
			(
				      LogicalDevice::Handle        _device         ,
				const DeviceEventInfo&             _deviceEventInfo,
				const Memory::AllocationCallbacks* _allocator      ,
				      Handle&                      _fence
			)
			{
				return EResult(vkRegisterDeviceEventEXT(_device, _deviceEventInfo, _allocator->operator const VkAllocationCallbacks*(), &_fence));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkRegisterDisplayEventEXT">Specification</a> 
			 * 
			 * \param device
			 * \param display
			 * \param pDisplayEventInfo
			 * \param pAllocator
			 * \param pFence
			 * \return 
			 */
			static EResult RegisterDisplayEvent
			(
				      LogicalDevice::Handle        _device          ,
				      Display::Handle              _display         ,
				const DisplayEventInfo&            _displayEventInfo,
				const Memory::AllocationCallbacks* _allocator       ,
				      Handle&                      _fence
			)
			{
				return EResult(vkRegisterDisplayEventEXT(_device, _display, _displayEventInfo, _allocator->operator const VkAllocationCallbacks*(), &_fence));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkResetFences">Specification</a> 
			 * 
			 * \param _logicalDevice
			 * \param _fences
			 * \param _fenceCount
			 * \return 
			 */
			static EResult Reset(LogicalDevice::Handle _logicalDevice, Fence::Handle* _fences, uint32 _fenceCount)
			{
				return EResult(vkResetFences(_logicalDevice, _fenceCount, _fences));
			}

			/**
			 * 
			 * @brief .
			 * 
			 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkWaitForFences">Specification</a> 
			 * 
			 * \param device
			 * \param fenceCount
			 * \param pFences
			 * \param waitAll
			 * \param timeout
			 * \return 
			 */
			static EResult WaitForFences
			(
				      LogicalDevice::Handle _device    ,
				      uint32                _fenceCount,
				const Fence::Handle*        _fences    ,
				      Bool                  _waitAll   ,
				      uInt64                _timeout
			)
			{
				return EResult(vkWaitForFences(_device, _fenceCount, _fences, _waitAll, _timeout));
			}
		};


		/**
		 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#synchronization-semaphores">Specification</a> 
		 */
		struct Semaphore
		{
			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphore">Specification</a> .
			 */
			using Handle = VkSemaphore;

			using EExternalHandleType = EExternalSemaphoreHandleTypeFlag;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreImportFlags">Specification</a>  */
			using ImportFlags = Bitmask<ESemaphoreImportFlag, VkSemaphoreImportFlags>;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreWaitFlags">Specification</a>  */
			using WaitFlags = Bitmask<ESemaphoreWaitFlag, VkSemaphoreWaitFlags>;

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreCreateInfo">Specification</a> 
			 */
			struct CreateInfo : Vault_0::VKStruct_Base<VkSemaphoreCreateInfo, EStructureType::Semaphore_CreateInfo>
			{
				using CreateFlags = Bitmask<EUndefined, VkSemaphoreCreateFlags>;

				      EType       SType;
				const void*       Next ;
				      CreateFlags Flags;
			};

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExportSemaphoreCreateInfo">Specification</a> 
			 */
			struct ExportCreateInfo : Vault_0::VKStruct_Base<VkExportSemaphoreCreateInfo, EStructureType::Export_Semaphore_CreateInfo_KHR>
			{
				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExternalSemaphoreHandleTypeFlags">Specification</a>  */
				using ExternalHandleTypeFlags = Bitmask<EExternalSemaphoreHandleTypeFlag, VkExternalSemaphoreHandleTypeFlags>;

				      EType                   SType      ;
				const void*                   Next       ;
				      ExternalHandleTypeFlags HandleTypes;

				/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkExportSemaphoreWin32HandleInfoKHR">Specification</a>  */
				struct Win32HandleInfo : Vault_0::VKStruct_Base<VkExportSemaphoreWin32HandleInfoKHR, EStructureType::ExportSemaphore_Win32Handle_Info_KHR>
				{
					      EType                SType     ;
					const void*                Next      ;
					const SECURITY_ATTRIBUTES* Attributes;
					      DWORD                DWAccess  ;
					      LPCWSTR              Name      ;
				};
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreGetFdInfoKHR">Specification</a>  */
			struct GetPOSIX_FileDescriptorInfo : Vault_0::VKStruct_Base<VkSemaphoreGetFdInfoKHR, EStructureType::Semaphore_Get_FD_Info_KHR>
			{
				      EType               SType     ;
				const void*               Next      ;
				      Handle              Semaphore ;
				      EExternalHandleType HandleType;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreGetWin32HandleInfoKHR">Specification</a>  */
			struct GetWin32HandleInfo : Vault_0::VKStruct_Base<VkSemaphoreGetWin32HandleInfoKHR, EStructureType::Semaphore_GetWin32Handle_Info_KHR>
			{
				      EType               SType     ;
				const void*               Next      ;
				      Handle              Semaphore ;
				      EExternalHandleType HandleType;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImportSemaphoreFdInfoKHR">Specification</a>  */
			struct ImportPOSIX_FileDescriptorInfo : Vault_0::VKStruct_Base<VkImportSemaphoreFdInfoKHR, EStructureType::ImportSemaphore_FD_Info_KHR>
			{
				      EType               SType         ;
				const void*               Next          ;
				      Handle              Semaphore     ;
				      ImportFlags         Flags         ;
				      EExternalHandleType HandleType    ;
				      int                 FileDescriptor;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkImportSemaphoreWin32HandleInfoKHR">Specification</a>  */
			struct ImportWin32HandleInfo : Vault_0::VKStruct_Base<VkImportSemaphoreWin32HandleInfoKHR, EStructureType::ImportSemaphore_Win32Handle_Info_KHR>
			{
				      EType               SType     ;
				const void*               Next      ;
				      Handle              Semaphore ;
				      ImportFlags         Flags     ;
				      EExternalHandleType HandleType;
				      HANDLE              Handle    ;
				      LPCWSTR             Name      ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreSignalInfo">Specification</a>  */
			struct SignalInfo : Vault_0::VKStruct_Base<VkSemaphoreSignalInfo, EStructureType::Semaphore_SignalInfo>
			{
				      EType  SType    ;
				const void*  Next     ;
				      Handle Semaphore;
				      uInt64 Value    ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreTypeCreateInfo">Specification</a>  */
			struct TypeSpecifiedCreateInfo : Vault_0::VKStruct_Base<VkSemaphoreTypeCreateInfo, EStructureType::SemaphoreType_CreateInfo>
			{
				      EType  SType        ;
				const void*  Next         ;
				      Handle SemaphoreType;
				      uInt64 InitialValue ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSemaphoreWaitInfo">Specification</a>  */
			struct WaitInfo : Vault_0::VKStruct_Base<VkSemaphoreWaitInfo, EStructureType::Semaphore_WaitInfo>
			{
				      EType     SType         ;
				const void*     Next          ;
				      WaitFlags Flags         ;
				      uint32    SemaphoreCount;
				const Handle*   Semaphores    ;
				const uInt64*   Values        ;
			};


			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateSemaphore">Specification</a> 
			 * 
			 * \param device
			 * \param pCreateInfo
			 * \param pAllocator
			 * \param pSemaphore
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle        _device    ,
				const CreateInfo&                  _createInfo,
				const Memory::AllocationCallbacks* _allocator ,
				      Handle&                      _semaphore
			)
			{
				return EResult(vkCreateSemaphore(_device, _createInfo.operator const VkSemaphoreCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_semaphore));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroySemaphore">Specification</a> 
			 * 
			 * \param _device
			 * \param _semaphore
			 * \param _allocator
			 */
			static void Destroy
			(
				      LogicalDevice::Handle        _device   ,
				      Handle                       _semaphore,
				const Memory::AllocationCallbacks* _allocator
			)
			{
				vkDestroySemaphore(_device, _semaphore, _allocator->operator const VkAllocationCallbacks*());
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetSemaphoreCounterValue">Specification</a> 
			 * 
			 * \param device
			 * \param semaphore
			 * \param pValue
			 * \return 
			 */
			static EResult GetCounterValue
			(
				LogicalDevice::Handle _device   ,
				Handle                _semaphore,
				uInt64&               _value
			)
			{
				return EResult(vkGetSemaphoreCounterValue(_device, _semaphore, &_value));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetSemaphoreFdKHR">Specification</a> 
			 * 
			 * \param device
			 * \param pGetFdInfo
			 * \param pFd
			 * \return 
			 */
			static EResult GetPOSIX_FileDescriptor
			(
				      LogicalDevice::Handle        _device        ,
				const GetPOSIX_FileDescriptorInfo& _getInfo       ,
				      int*                         _fileDescriptor
			)
			{
				return EResult(vkGetSemaphoreFdKHR(_device, _getInfo, _fileDescriptor));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkGetSemaphoreWin32HandleKHR">Specification</a> 
			 * 
			 * \param device
			 * \param pGetWin32HandleInfo
			 * \param pHandle
			 * \return 
			 */
			static EResult GetWin32Handle
			(
				      LogicalDevice::Handle _device ,
				const GetWin32HandleInfo&   _getInfo,
				      HANDLE*               _handle
			)
			{
				return EResult(vkGetSemaphoreWin32HandleKHR(_device, _getInfo, _handle));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkImportSemaphoreFdKHR">Specification</a> 
			 * 
			 * \param device
			 * \param pImportSemaphoreFdInfo
			 * \return 
			 */
			static EResult ImportPOSIX_FileDescriptor(LogicalDevice::Handle _device, const ImportPOSIX_FileDescriptorInfo& _importPOSIX_Info)
			{
				return EResult(vkImportSemaphoreFdKHR(_device, _importPOSIX_Info));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkImportSemaphoreWin32HandleKHR">Specification</a> 
			 * 
			 * \param device
			 * \param pImportSemaphoreWin32HandleInfo
			 * \return 
			 */
			static EResult ImportWin32Handle(LogicalDevice::Handle _device, const ImportWin32HandleInfo& _importHandleInfo)
			{
				return EResult(vkImportSemaphoreWin32HandleKHR(_device, _importHandleInfo));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkSignalSemaphore">Specification</a> 
			 * 
			 * \param device
			 * \param pSignalInfo
			 * \return 
			 */
			static EResult Signal(LogicalDevice::Handle _device, const SignalInfo& _signalInfo)
			{
				return EResult(vkSignalSemaphore(_device, _signalInfo));
			}

			/**
			 * @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkWaitSemaphores">Specification</a>.
			 * 
			 * \param _device
			 * \param _waitInfo
			 * \param timeout
			 * \return 
			 */
			static EResult WaitFor
			(
				      LogicalDevice::Handle _device  ,
				const WaitInfo&             _waitInfo,
				      uInt64                _timeout
			)
			{
				return EResult(vkWaitSemaphores(_device, _waitInfo, _timeout));
			}
		};
	}

	namespace Vault_2
	{
		struct Fence : public Vault_1::Fence
		{

		};
	}
}
