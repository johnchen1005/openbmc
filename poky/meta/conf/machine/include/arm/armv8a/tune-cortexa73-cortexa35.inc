#
# Tune Settings for big.LITTLE Cortex-A73 - Cortex-A35
#
DEFAULTTUNE ?= "cortexa73-cortexa35"

TUNEVALID[cortexa73-cortexa35] = "Enable big.LITTLE Cortex-A73.Cortex-A35 specific processor optimizations"
MACHINEOVERRIDES =. "${@bb.utils.contains("TUNE_FEATURES", "cortexa73-cortexa35", "cortexa73-cortexa35:", "", d)}"
TUNE_CCARGS .= "${@bb.utils.contains("TUNE_FEATURES", "cortexa73-cortexa35", " -mcpu=cortex-a73.cortex-a35", "", d)}"

require conf/machine/include/arm/arch-armv8a.inc

# cortexa73.cortexa35 implies crc support
AVAILTUNES                                          += "cortexa73-cortexa35 cortexa73-cortexa35-crypto"
ARMPKGARCH_tune-cortexa73-cortexa35                  = "cortexa73-cortexa35"
ARMPKGARCH_tune-cortexa73-cortexa35-crypto           = "cortexa73-cortexa35-crypto"
TUNE_FEATURES_tune-cortexa73-cortexa35               = "${TUNE_FEATURES_tune-armv8a-crc} cortexa73-cortexa35"
TUNE_FEATURES_tune-cortexa73-cortexa35-crypto        = "${TUNE_FEATURES_tune-cortexa73-cortexa35} crypto"
PACKAGE_EXTRA_ARCHS_tune-cortexa73-cortexa35         = "${PACKAGE_EXTRA_ARCHS_tune-armv8a-crc} cortexa73-cortexa35"
PACKAGE_EXTRA_ARCHS_tune-cortexa73-cortexa35-crypto  = "${PACKAGE_EXTRA_ARCHS_tune-armv8a-crc-crypto} cortexa73-cortexa35 cortexa73-cortexa35-crypto"
BASE_LIB_tune-cortexa73-cortexa35                    = "lib64"
BASE_LIB_tune-cortexa73-cortexa35-crypto             = "lib64"