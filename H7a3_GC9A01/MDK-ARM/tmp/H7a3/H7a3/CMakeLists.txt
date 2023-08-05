# CMSIS Build CMakeLists generated on 2023-08-05T16:33:05

cmake_minimum_required(VERSION 3.22)

# Target options

set(TARGET H7a3)
set(CPU Cortex-M7)
set(PRJ_DIR "c:/Users/Mr.zhou/Desktop/H7a3/MDK-ARM")
set(OUT_DIR "C:/Users/Mr.zhou/Desktop/H7a3/MDK-ARM/out/H7a3/H7a3")
set(INT_DIR "C:/Users/Mr.zhou/Desktop/H7a3/MDK-ARM/tmp/H7a3/H7a3")
set(FPU DP_FPU)
set(SECURE Non-secure)
set(BYTE_ORDER Little-endian)
set(OPTIMIZE none)
set(DEBUG on)
set(AS_FLAGS_GLOBAL "-masm=auto")
set(CC_FLAGS_GLOBAL "-fno-rtti -funsigned-char -fshort-enums -fshort-wchar -ffunction-sections -std=c99 -Wno-packed -Wno-missing-variable-declarations -Wno-missing-prototypes -Wno-missing-noreturn -Wno-sign-conversion -Wno-nonportable-include-path -Wno-reserved-id-macro -Wno-unused-macros -Wno-documentation-unknown-command -Wno-documentation -Wno-license-management -Wno-parentheses-equality")
set(CXX_FLAGS_GLOBAL "-fno-rtti -funsigned-char -fshort-enums -fshort-wchar -ffunction-sections -std=c99 -Wno-packed -Wno-missing-variable-declarations -Wno-missing-prototypes -Wno-missing-noreturn -Wno-sign-conversion -Wno-nonportable-include-path -Wno-reserved-id-macro -Wno-unused-macros -Wno-documentation-unknown-command -Wno-documentation -Wno-license-management -Wno-parentheses-equality")
set(LD_FLAGS_GLOBAL "--map --load_addr_map_info --xref --callgraph --symbols --info sizes --info totals --info unused --info veneers --list --strict --summary_stderr --info summarysizes")
set(LD_SCRIPT "c:/Users/Mr.zhou/Desktop/H7a3/MDK-ARM/H7a3_H7a3.sct")

set(DEFINES
  STM32H7A3xxQ
  _RTE_
  USE_HAL_DRIVER
)

set(INC_PATHS
  "c:/Users/Mr.zhou/Desktop/H7a3/Core/Inc"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Inc"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/CMSIS/Device/ST/STM32H7xx/Include"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/CMSIS/Include"
  "c:/Users/Mr.zhou/Desktop/H7a3/GC9A01"
  "c:/Users/Mr.zhou/Desktop/H7a3/MDK-ARM/RTE/_H7a3"
  "C:/Users/Mr.zhou/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include"
  "C:/Users/Mr.zhou/AppData/Local/Arm/Packs/Keil/STM32H7xx_DFP/3.1.1/Drivers/CMSIS/Device/ST/STM32H7xx/Include"
)

set(AS_ARM_SRC_FILES
  "c:/Users/Mr.zhou/Desktop/H7a3/MDK-ARM/startup_stm32h7a3xxq.s"
)

set(CC_SRC_FILES
  "c:/Users/Mr.zhou/Desktop/H7a3/Core/Src/dma.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Core/Src/gpio.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Core/Src/main.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Core/Src/spi.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Core/Src/stm32h7xx_hal_msp.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Core/Src/stm32h7xx_it.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Core/Src/system_stm32h7xx.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Core/Src/usart.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Core/Src/usb_otg.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi_ex.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart_ex.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/GC9A01/lcd.c"
  "c:/Users/Mr.zhou/Desktop/H7a3/GC9A01/lcd_init.c"
)

# Toolchain config map

set(REGISTERED_TOOLCHAIN_ROOT "c:/Users/Mr.zhou/.vcpkg/artifacts/fd3d78d7/compilers.arm.armclang/6.20.0/bin")
set(REGISTERED_TOOLCHAIN_VERSION "6.20.0")
set(TOOLCHAIN_VERSION_MIN "6.20.0")
include ("C:/Users/Mr.zhou/.vcpkg/artifacts/fd3d78d7/tools.open.cmsis.pack.cmsis.toolbox/2.0.0/etc/AC6.6.18.0.cmake")
include ("C:/Users/Mr.zhou/.vcpkg/artifacts/fd3d78d7/tools.open.cmsis.pack.cmsis.toolbox/2.0.0/etc/CMSIS-Build-Utils.cmake")

# Setup project

project(${TARGET} LANGUAGES AS_ARM C)

cbuild_get_running_toolchain(TOOLCHAIN_ROOT TOOLCHAIN_VERSION C)

# Global Flags

set(CMAKE_AS_ARM_FLAGS "${AS_ARM_CPU} ${AS_ARM_BYTE_ORDER} ${AS_ARM_DEFINES} ${AS_ARM_OPTIONS_FLAGS} ${AS_ARM_FLAGS} ${AS_FLAGS_GLOBAL}")
cbuild_get_system_includes(CC_SYS_INC_PATHS_LIST CC_SYS_INC_PATHS)
set(CMAKE_C_FLAGS "${CC_CPU} ${CC_BYTE_ORDER} ${CC_DEFINES} ${CC_SECURE} ${CC_OPTIONS_FLAGS} ${CC_FLAGS} ${CC_FLAGS_GLOBAL} ${CC_SYS_INC_PATHS}")
set(CMAKE_C_LINK_FLAGS "${LD_CPU} ${_LS}\"${LD_SCRIPT}\" ${LD_SECURE} ${LD_FLAGS_GLOBAL} ${LD_OPTIONS_FLAGS} ${LD_FLAGS}")

# Local Flags

foreach(SRC ${AS_ARM_SRC_FILES})
  set_source_files_properties(${SRC} PROPERTIES LANGUAGE AS_ARM)
endforeach()

# Compilation Database

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_custom_target(database COMMAND ${CMAKE_COMMAND} -E copy_if_different "${INT_DIR}/compile_commands.json" "${OUT_DIR}")

# Setup Target

add_executable(${TARGET} ${AS_ARM_SRC_FILES} ${CC_SRC_FILES})
set_target_properties(${TARGET} PROPERTIES PREFIX "" SUFFIX ".axf" OUTPUT_NAME "H7a3")
set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR} LINK_DEPENDS ${LD_SCRIPT})
target_include_directories(${TARGET} PUBLIC ${INC_PATHS})
