LINUXINCLUDE += -I$(SSG_MODULE_ROOT)/ \
                -I$(SSG_MODULE_ROOT)/linux/ \
                -include $(SSG_MODULE_ROOT)/config/sec-kernel_defconfig.h
ifeq ($(CONFIG_ARCH_SA8155),y)
include $(SSG_MODULE_ROOT)/config/sec-kernel_auto_defconfig.conf
obj-$(CONFIG_QSEECOM) += qseecom_dlkm.o
qseecom_dlkm-objs := qseecom/qseecom.o
else
ifeq ($(CONFIG_ARCH_QTI_VM), y)
include $(SSG_MODULE_ROOT)/config/sec-kernel_defconfig_tvm.conf
else
include $(SSG_MODULE_ROOT)/config/sec-kernel_defconfig.conf
endif
obj-$(CONFIG_QCOM_SMCINVOKE) += smcinvoke_dlkm.o
smcinvoke_dlkm-objs := smcinvoke/smcinvoke_kernel.o smcinvoke/smcinvoke.o
endif

obj-$(CONFIG_QTI_TZ_LOG) += tz_log_dlkm.o
tz_log_dlkm-objs := tz_log/tz_log.o

obj-$(CONFIG_CRYPTO_DEV_QCEDEV) += qcedev-mod_dlkm.o
qcedev-mod_dlkm-objs := crypto-qti/qce50.o crypto-qti/qcedev.o crypto-qti/qcedev_smmu.o crypto-qti/compat_qcedev.o

obj-$(CONFIG_CRYPTO_DEV_QCRYPTO) += qcrypto-msm_dlkm.o
qcrypto-msm_dlkm-objs := crypto-qti/qcrypto.o

obj-$(CONFIG_HDCP_QSEECOM) += hdcp_qseecom_dlkm.o
hdcp_qseecom_dlkm-objs := hdcp/hdcp_qseecom.o

obj-$(CONFIG_HW_RANDOM_MSM_LEGACY) += qrng_dlkm.o
qrng_dlkm-objs := qrng/msm_rng.o
