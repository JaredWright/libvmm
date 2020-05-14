#ifndef LIBVMM_VCPU_X64_INTEL_IO_PORT_HPP
#define LIBVMM_VCPU_X64_INTEL_IO_PORT_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <libvmm/type/vcpu_delegate.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

/// @brief Enable vmexits for io port accesses at the specified port number
///     during vcpu execution. 
///
/// @param port_number The port number to enable vmexits for
void enable_io_port_vmexit(vcpu_context &vc, uint16_t port_number) noexcept;

/// @brief Enable vmexits for a range of io port accesses with port numbers
///     from @param begin to @param end (inclusive) during vcpu execution. 
///
/// @expects begin <= end
///
/// @param begin The lower bound of port numbers to enable vmexits for
/// @param end The upper bound of port numbers to enable vmexits for
void enable_io_port_vmexit_range(vcpu_context &vc, uint16_t begin, uint16_t end) noexcept;

/// @brief Disable vmexits for io port accesses at the specified port number
///     during vcpu execution. 
///
/// @param port_number The port number to disable vmexits for
void disable_io_port_vmexit(vcpu_context &vc, uint16_t port_number) noexcept;

/// @brief Disable vmexits for a range of io port accesses with port numbers
///     from @param begin to @param end (inclusive) during vcpu execution. 
///
/// @expects begin <= end
///
/// @param begin The lower bound of port numbers to enable vmexits for
/// @param end The upper bound of port numbers to enable vmexits for
void disable_io_port_vmexit_range(vcpu_context &vc, uint16_t begin, uint16_t end) noexcept;

/// @brief Set a vmexit handler that will be called for all vmexits caused
///     by an io port access while a vcpu is executing.
///
/// @param func The delegate function to be called
void set_io_port_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

/// @brief Returns the size of the value being read in or written out to an
///     io port, that caused a vmexit to occur while a vcpu was executing
///
/// @return The size (in bytes) of the value read in from or written to an
///     io port when a vmexit occurred
uint64_t get_io_port_vmexit_size(vcpu_context &vc) noexcept;

/// @brief Returns true if the current vmexit execution context was
///     triggered as a result of an "in" operation from an io port
///
/// @return True if io port in caused the current vmexit, else false
bool is_io_port_vmexit_in(vcpu_context &vc) noexcept;

/// @brief Returns true if the current vmexit execution context was
///     triggered as a result of an "out" operation to an io port
///
/// @return True if io port out caused the current vmexit, else false
bool is_io_port_vmexit_out(vcpu_context &vc) noexcept;

/// @brief Returns the port number of an io instruction that caused a
///     vmexit to occur while a vcpu was executing
///
/// @return The io port number that caused a vmexit to occur
uint16_t get_io_port_vmexit_port_number(vcpu_context &vc) noexcept;

/// @brief Returns the value being read in from or written out to an io
///     port, that caused a vmexit to occur while a vcpu was executing
///
/// @return The value read in from or written out to an io port when a
///     vmexit occurred
uint64_t get_io_port_vmexit_value(vcpu_context &vc) noexcept;

/// @brief TODO
///
void pass_through_io_port(vcpu_context &vc) noexcept;

/// @brief TODO
///
/// @param value The value to be written to or read from the io port
void provide_io_port_result(vcpu_context &vc, uint64_t value) noexcept;

}

#endif
