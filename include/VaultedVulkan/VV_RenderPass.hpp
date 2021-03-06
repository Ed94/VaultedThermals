/*!
@file VV_RenderPass.hpp

@brief Vaulted Vulkan: Render Pass

@details

<a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#renderpass">Specification</a> 
*/



#pragma once



// VT
#include "VV_Vaults.hpp"
#include "VV_APISpecGroups.hpp"
#include "VV_Platform.hpp"
#include "VV_CPP_STL.hpp"
#include "VV_Enums.hpp"
#include "VV_Backend.hpp"
#include "VV_Types.hpp"
#include "VV_Constants.hpp"
#include "VV_Memory_Backend.hpp"
#include "VV_PhysicalDevice.hpp"
#include "VV_Initialization.hpp"
#include "VV_LogicalDevice.hpp"
#include "VV_Memory.hpp"
#include "VV_Sampler.hpp"
#include "VV_Resource.hpp"
#include "VV_SyncAndCacheControl.hpp"
#include "VV_Shaders.hpp"
#include "VV_Pipelines.hpp"



#ifndef VV_Option__Use_Long_Namespace
namespace VV
#else
namespace VaultedVulkan
#endif
{
	namespace V1
	{
		/**
		@addtogroup Vault_1
		@{
		*/

		/**
		 * @brief Render passes operate in conjunction with framebuffers. Framebuffers represent a collection of specific memory attachments that a render pass instance uses.
		 * 
		 * @details
		 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#_framebuffers">Specification</a>
		 * 
		 * @ingroup APISpec_Render_Pass
		 */
		struct Framebuffer
		{
			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFramebuffer">Specification</a>  
			@ingroup APISpec_Render_Pass
			*/
			using Handle = VkFramebuffer;
			
			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFramebufferCreateFlags">Specification</a>  
			@ingroup APISpec_Render_Pass
			*/
			using CreateFlags = Bitfield<EFrameBufferCreateFlag, VkFramebufferCreateFlags>;

			/** 
			@brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkFramebufferCreateInfo">Specification</a>  
			@ingroup APISpec_Render_Pass
			*/
			struct CreateInfo : V0::VKStruct_Base<VkFramebufferCreateInfo, EStructureType::Framebuffer_CreateInfo>
			{
				using RenderPass_Handle = VkRenderPass;   // RenderPass::Handle not defined yet. (Defined later in the file)

				      EType              SType           = STypeEnum;
				const void*              Next            = nullptr  ;
				      CreateFlags        Flags          ;
				      RenderPass_Handle  RenderPass     ;
				      ui32               AttachmentCount = 0        ;
				const ImageView::Handle* Attachments     = nullptr  ;
				      ui32               Width          ;
				      ui32               Height         ;
				      ui32               Layers         ;
			};

			/**
			 * @brief Creates a framebuffer.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkCreateFramebuffer">Specification</a> 
			 * 
			 * @ingroup APISpec_Render_Pass
			 * 
			 * \param _deviceHanle
			 * \param _creationSpec
			 * \param _allocator
			 * \param _framebuffer
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle        _deviceHanle ,
				const CreateInfo&                  _creationSpec,
				const Memory::AllocationCallbacks* _allocator   ,
				      Handle&                      _framebuffer
			)
			{
				return EResult(vkCreateFramebuffer(_deviceHanle, _creationSpec.operator const VkFramebufferCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_framebuffer));
			}

			/**
			 * @brief Destroy a framebuffer.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyFramebuffer">Specification</a> 
			 * 
			 * @ingroup APISpec_Render_Pass
			 * 
			 * \param _deviceHandle
			 * \param _framebuffer
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _framebuffer, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyFramebuffer(_deviceHandle, _framebuffer, _allocator->operator const VkAllocationCallbacks*());
			}
		};

		/**
		 * @brief A render pass represents a collection of attachments, subpasses, and dependencies between the subpasses, and describes how the attachments are used over the course of the subpasses.
		 * 
		 * @details <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#renderpass">Specification</a> 
		 * 
		 * @ingroup APISpec_Render_Pass
		 */
		struct RenderPass
		{
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkRenderPass">Specification</a> @ingroup APISpec_Render_Pass */
			using Handle = VkRenderPass;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAttachmentDescriptionFlags">Specification</a> @ingroup APISpec_Render_Pass */
			using AttachmentDescriptionFlags = Bitfield<EAttachmentDescriptionFlag, VkAttachmentDescriptionFlags>;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubpassDescriptionFlags">Specification</a> @ingroup APISpec_Render_Pass */
			using SubpassDesriptionFlags     = Bitfield<ESubpassDescriptionFlag   , VkSubpassDescriptionFlags   >;
			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkRenderPassCreateFlags">Specification</a> @ingroup APISpec_Render_Pass */
			using CreateFlags                = Bitfield<EUndefined                , VkRenderPassCreateFlags     >;

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAttachmentDescription">Specification</a> @ingroup APISpec_Render_Pass */
			struct AttachmentDescription : V0::VKStruct_Base<VkAttachmentDescription>
			{
				AttachmentDescriptionFlags Flags         ;
				EFormat                    Format        ;
				ESampleCount               Samples       ;
				EAttachmentLoadOperation   LoadOp        ;
				EAttachmentStoreOperation  StoreOp       ;
				EAttachmentLoadOperation   StencilLoadOp ;
				EAttachmentStoreOperation  StencilStoreOp;
				EImageLayout               InitialLayout ;
				EImageLayout               FinalLayout   ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkAttachmentReference">Specification</a> @ingroup APISpec_Render_Pass */
			struct AttachmentReference : V0::VKStruct_Base<VkAttachmentReference>
			{
				ui32       Attachment;
				EImageLayout Layout    ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkRenderPassBeginInfo">Specification</a> @ingroup APISpec_Render_Pass */
			struct BeginInfo : V0::VKStruct_Base<VkRenderPassBeginInfo, EStructureType::RenderPass_BeginInfo>
			{
				      EType               SType           = STypeEnum;
				const void*               Next            = nullptr  ;
				      RenderPass::Handle  RenderPass     ;
				      Framebuffer::Handle Framebuffer    ;
				      Rect2D              RenderArea     ;
				      ui32                ClearValueCount;
				const ClearValue*         ClearValues     = nullptr  ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubpassDescription">Specification</a> @ingroup APISpec_Render_Pass */
			struct SubpassDescription : V0::VKStruct_Base<VkSubpassDescription>
			{
				      SubpassDesriptionFlags Flags                  ;
				      EPipelineBindPoint     PipelineBindPoint      ;
				      ui32                   InputAttachmentCount   ;
				const AttachmentReference*   InputAttachments        = nullptr;
				      ui32                   ColorAttachmentCount   ;
				const AttachmentReference*   ColorAttachments        = nullptr;
				const AttachmentReference*   ResolveAttachments      = nullptr;
				const AttachmentReference*   DepthStencilAttachment  = nullptr;
				      ui32                   PreserveAttachmentCount;
				const ui32*                  PreserveAttachments     = nullptr;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkSubpassDependency">Specification</a> @ingroup APISpec_Render_Pass */
			struct SubpassDependency : V0::VKStruct_Base<VkSubpassDependency>
			{
				ui32                 SourceSubpass        ;
				ui32                 DestinationSubpass   ;
				Pipeline::StageFlags SourceStageMask      ;
				Pipeline::StageFlags DestinationStageMask ;
				AccessFlags          SourceAccessMask     ;
				AccessFlags          DestinationAccessMask;
				DependencyFlags      DependencyFlags      ;
			};

			/** @brief <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkRenderPassCreateInfo">Specification</a> @ingroup APISpec_Render_Pass */
			struct CreateInfo : V0::VKStruct_Base<VkRenderPassCreateInfo, EStructureType::RenderPass_CreateInfo>
			{
				      EType                  SType           = STypeEnum;
				const void*                  Next            = nullptr  ;
				      CreateFlags            Flags          ;
				      ui32                   AttachmentCount = 0        ;
				const AttachmentDescription* Attachments     = nullptr  ;
				      ui32                   SubpassCount    = 0        ;
				const SubpassDescription*    Subpasses       = nullptr  ;
				      ui32                   DependencyCount = 0        ;
				const SubpassDependency*     Dependencies    = nullptr  ;
			};

			/**
			 * @brief Create a render pass.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#renderpass-creation">Specification</a> 
			 * 
			 * @ingroup APISpec_Render_Pass
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _allocator
			 * \param _renderPass
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle        _deviceHandle,
				const CreateInfo&                  _createInfo  ,
				const Memory::AllocationCallbacks* _allocator   ,
				      Handle&                      _renderPass
			)
			{
				return EResult(vkCreateRenderPass(_deviceHandle, _createInfo.operator const VkRenderPassCreateInfo*(), _allocator->operator const VkAllocationCallbacks*(), &_renderPass));
			}

			/**
			 * @brief Destroy a render pass.
			 * 
			 * @details
			 * <a href="https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#vkDestroyRenderPass">Specification</a> 
			 * 
			 * @ingroup APISpec_Render_Pass
			 * 
			 * \param _deviceHandle
			 * \param _renderPass
			 * \param _allocator
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _renderPass, const Memory::AllocationCallbacks* _allocator)
			{
				vkDestroyRenderPass(_deviceHandle, _renderPass, _allocator->operator const VkAllocationCallbacks*());
			}
		};

		/** @} */
	}

	namespace V2
	{
		/**
		@addtogroup Vault_2
		@{
		*/

		/**
		@brief Render passes operate in conjunction with framebuffers. Framebuffers represent a collection of specific memory attachments that a render pass instance uses.
		*/
		struct Framebuffer : public V1::Framebuffer
		{
			using Parent = V1::Framebuffer;

			/**
			 * @brief Creates a framebuffer.
			 * 
			 * @details
			 * 
			 * \param _deviceHanle
			 * \param _creationSpec
			 * \param _framebuffer
			 * \return 
			 */
			static EResult Create(LogicalDevice::Handle _deviceHanle, const CreateInfo& _creationSpec, Handle& _framebuffer)
			{
				return Parent::Create(_deviceHanle, _creationSpec, Memory::DefaultAllocator, _framebuffer);
			}

			using Parent::Create;

			/**
			 * @brief Destroy a framebuffer.
			 * 
			 * @details
			 * 
			 * \param _deviceHandle
			 * \param _framebuffer
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _framebuffer)
			{
				Parent::Destroy(_deviceHandle, _framebuffer, Memory::DefaultAllocator);
			}

			using Parent::Destroy;
		};

		/**
		@brief A render pass represents a collection of attachments, subpasses, and dependencies between the subpasses, and describes how the attachments are used over the course of the subpasses.
		*/
		struct RenderPass : public V1::RenderPass
		{
			using Parent = V1::RenderPass;


			/**
			@brief Offers a default constructor.
			*/
			struct SubpassDescription : public Parent::SubpassDescription
			{
				SubpassDescription()
				{
					InputAttachmentCount    = 0;
					InputAttachments        = nullptr;
					ColorAttachmentCount    = 0;
					ColorAttachments        = nullptr;
					ResolveAttachments      = nullptr;
					DepthStencilAttachment  = nullptr;
					PreserveAttachmentCount = 0;
					PreserveAttachments     = nullptr;
				}
			};

			/**
			 * @brief Create a render pass. (Default Allocator)
			 * 
			 * @details
			 * 
			 * @ingroup 
			 * 
			 * \param _deviceHandle
			 * \param _createInfo
			 * \param _renderPass
			 * \return 
			 */
			static EResult Create
			(
				      LogicalDevice::Handle _deviceHandle,
				const CreateInfo&           _createInfo  ,
				      Handle&               _renderPass
			)
			{
				return Parent::Create(_deviceHandle, _createInfo, Memory::DefaultAllocator, _renderPass);
			}

			using Parent::Create;

			/**
			 * @brief Destroy a render pass. (Default Allocator)
			 * 
			 * @details
			 * 
			 * @ingroup 
			 * 
			 * \param _deviceHandle
			 * \param _renderPass
			 */
			static void Destroy(LogicalDevice::Handle _deviceHandle, Handle _renderPass)
			{
				Parent::Destroy(_deviceHandle, _renderPass, Memory::DefaultAllocator);
			}

			using Parent::Destroy;
		};

		/** @} */
	}

	namespace V3
	{
		/**
		@addtogroup Vault_3
		@{
		*/

		/**
		@brief Render passes operate in conjunction with framebuffers. Framebuffers represent a collection of specific memory attachments that a render pass instance uses.

		@details
		This object represents a device created object on the host. As such ownership is tied to this host object.
		Due to this design, the object has no copy-construction allowed. Instead, default move constructor and assignment has been defined.
		*/
		class Framebuffer : public V2::Framebuffer
		{
		public:
			using Parent = V2::Framebuffer;

			/**
			@brief Default constructor.
			*/
			Framebuffer() : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(nullptr)
			{}

			/**
			@brief Logical device specified.
			*/
			Framebuffer(const LogicalDevice& _device) : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(&_device)
			{}

			/**
			@brief Logical device and allocator specified.
			*/
			Framebuffer(const LogicalDevice& _device, const Memory::AllocationCallbacks& _allocator) : handle(Null<Handle>), allocator(&_allocator), device(&_device)
			{}

			/**
			@brief Performs a move operation to transfer ownership of the device object to this host object.
			*/
			Framebuffer(Framebuffer&& _other) noexcept :
				handle(_other.handle), allocator(_other.allocator), device(_other.device)
			{
				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;
			}

			/**
			@brief Destroy the framebuffer.
			*/
			~Framebuffer()
			{
				if (handle != Null<Handle>) Destroy();
			}

			/**
			@brief Create the framebuffer.
			*/
			EResult Create(const CreateInfo& _info)
			{
				if (device == nullptr) return EResult::Not_Ready;

				return Parent::Create(*device, _info, allocator, handle);
			}

			/**
			@brief Create the framebuffer (logical device specified).
			*/
			EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
			{
				device = &_device;

				return Parent::Create(*device, _info, handle);
			}

			/**
			@brief Create the framebuffer (logical device and allocator specified).
			*/
			EResult Create(const LogicalDevice* _device, const CreateInfo& _info, const Memory::AllocationCallbacks& _allocator)
			{
				device    = _device    ;
				allocator = &_allocator;

				return Parent::Create(*device, _info, allocator, handle);
			}

			/**
			@brief Destroy the framebuffer.
			*/
			void Destroy()
			{
				Parent::Destroy(*device, handle, allocator);

				handle = Null<Handle>;
				device = nullptr     ;
			}

			/**
			@brief Implicit conversion to give a reference to its handle.
			*/
			operator Handle&()
			{
				return handle;
			}

			/**
			@brief Implicit conversion to give a readonly reference to its handle.
			*/
			operator const Handle&() const
			{
				return handle;
			}

			/**
			@brief Implicit conversion to give a pointer to its handle.
			*/
			operator const Handle*() const
			{
				return &handle;
			}

			/**
			@brief Checks to see if its the same object by checking to see if its the same handle.
			*/
			bool operator== (const Framebuffer& _other) const
			{
				return handle == _other.handle;
			}

			/**
			@brief Performs a move assignment operation to transfer ownership of the device object to this host object.
			*/
			Framebuffer& operator= (Framebuffer&& _other) noexcept
			{
				if (this == &_other)
					return *this;

				handle    = _other.handle   ;
				allocator = _other.allocator;
				device    = _other.device   ;

				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;

				return *this;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			const LogicalDevice* device;
		};

		/**
		@brief A render pass represents a collection of attachments, subpasses, and dependencies between the subpasses, and describes how the attachments are used over the course of the subpasses.

		@details
		This object represents a device created object on the host. As such ownership is tied to this host object.
		Due to this design, the object has no copy-construction allowed. Instead, default move constructor and assignment has been defined.
		*/
		class RenderPass : public V2::RenderPass
		{
		public:
			using Parent = V2::RenderPass;

			/**
			@brief Default constructor.
			*/
			RenderPass() : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(nullptr)
			{}

			/**
			@brief Logical device specified.
			*/
			RenderPass(const LogicalDevice& _device) : handle(Null<Handle>), allocator(Memory::DefaultAllocator), device(&_device)
			{}

			/**
			@brief Logical device and allocator specified.
			*/
			RenderPass(const LogicalDevice& _device, const Memory::AllocationCallbacks& _allocator) : handle(Null<Handle>), allocator(&_allocator), device(&_device)
			{}

			/**
			@brief Performs a move operation to transfer ownership of the device object to this host object.
			*/
			RenderPass(RenderPass&& _other) noexcept :
				handle(std::move(_other.handle)), allocator(std::move(_other.allocator)), device(std::move(_other.device))
			{
				_other.handle    = Null<Handle>            ;	
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;
			}

			/**
			@brief Destroy a renderpass.
			*/
			~RenderPass()
			{
				if (handle != Null<Handle>) Destroy();
			}

			/**
			@brief Create a render pass.
			*/
			EResult Create(const CreateInfo& _info)
			{
				if (device == nullptr) return EResult::Not_Ready;

				return Parent::Create(*device, _info, handle);
			}

			/**
			@brief Create a render pass (logical device specified).
			*/
			EResult Create(const LogicalDevice& _device, const CreateInfo& _info)
			{
				device = &_device;

				return Parent::Create(*device, _info, handle);
			}

			/**
			@brief Create a render pass (logical device and allocator specified).
			*/
			EResult Create(const LogicalDevice& _device, const CreateInfo& _info, const Memory::AllocationCallbacks& _allocator)
			{
				device    = &_device   ;
				allocator = &_allocator;

				return Parent::Create(*device, _info, allocator, handle);
			}

			/**
			@brief Destroy a render pass.
			*/
			void Destroy()
			{
				Parent::Destroy(*device, handle, allocator);

				handle = Null<Handle>;
				device = nullptr     ;
			}

			/**
			@brief Implicit conversion to give a reference to its handle.
			*/
			operator Handle&()
			{
				return handle;
			}

			/**
			@brief Implicit conversion to give a readonly reference to its handle.
			*/
			operator const Handle&() const
			{
				return handle;
			}

			/**
			@brief Implicit conversion to give a pointer to its handle.
			*/
			operator const Handle*() const
			{
				return &handle;
			}

			/**
			@brief Checks to see if its the same object by checking to see if its the same handle.
			*/
			bool operator== (const RenderPass& _other)
			{
				return handle == _other.handle;
			}

			/**
			@brief Performs a move assignment operation to transfer ownership of the device object to this host object.
			*/
			RenderPass& operator= (RenderPass&& _other) noexcept
			{
				if (this == &_other)
					return *this;

				handle    = std::move(_other.handle   );
				allocator = std::move(_other.allocator);
				device    = std::move(_other.device   );

				_other.handle    = Null<Handle>            ;
				_other.allocator = Memory::DefaultAllocator;
				_other.device    = nullptr                 ;

				return *this;
			}

		protected:

			Handle handle;

			const Memory::AllocationCallbacks* allocator;

			const LogicalDevice* device;
		};

		/** @} */
	}
}
