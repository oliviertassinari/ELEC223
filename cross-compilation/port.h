/**
 * Port macros
 */

#ifndef PORT_H
#define PORT_H

/**
 * Tools to write bytes
 **/

#define setPortMaskZero(port, mask) ((port) &= ~(mask))
#define setPortMaskOne(port, mask) ((port) |= (mask))

#define setPortMask(port, mask, bit)                                \
  (bit ? setPortMaskOne(port, mask) : setPortMaskZero(port, mask))

#define setPort(port, offset, bit) (setPortMask(port, 1 << (offset), bit))

#define setPortGroup(port, mask, offset, bits)                          \
  (port = ((port) & ~((mask) << (offset))) | (((bits) & (mask)) << (offset)))

#endif
