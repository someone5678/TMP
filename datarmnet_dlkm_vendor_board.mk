#Build rmnet core
DATA_DLKM_BOARD_PLATFORMS_LIST := lahaina
ifneq ($(TARGET_BOARD_AUTO),true)
ifeq ($(call is-board-platform-in-list,$(DATA_DLKM_BOARD_PLATFORMS_LIST)),true)
BOARD_VENDOR_KERNEL_MODULES += $(KERNEL_MODULES_OUT)/rmnet_core.ko
PRODUCT_PACKAGES += rmnet_core.ko
endif
endif

