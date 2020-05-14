target_sources(libvmm PRIVATE
    start.s
    start_vmm.cpp
    event/libvmm_vcpu_event.cpp
)

if(${LIBVMM_TARGET_ARCH} STREQUAL "x86_64")
    target_sources(libvmm PRIVATE
        vcpu/intel/intel_cpuid.cpp
        vcpu/intel/intel_cr0.cpp
        vcpu/intel/intel_cr3.cpp
        vcpu/intel/intel_cr4.cpp
        vcpu/intel/intel_ept.cpp
        vcpu/intel/intel_execute.cpp
        vcpu/intel/intel_general_register_x64.cpp
        vcpu/intel/intel_init_signal.cpp
        vcpu/intel/intel_interrupt.cpp
        vcpu/intel/intel_instruction_pointer.cpp
        vcpu/intel/intel_interrupt_window.cpp
        vcpu/intel/intel_io_port.cpp
        vcpu/intel/intel_monitor_trap.cpp
        vcpu/intel/intel_nmi.cpp
        vcpu/intel/intel_nmi_window.cpp
        vcpu/intel/intel_rdmsr.cpp
        vcpu/intel/intel_sipi_signal.cpp
        vcpu/intel/intel_vmcall.cpp
        vcpu/intel/intel_vmexit.cpp
        vcpu/intel/intel_vpid.cpp
        vcpu/intel/intel_wrmsr.cpp
        vcpu/intel/intel_xcr0.cpp
        vcpu/intel/intel_cr4.cpp
    )
endif()
