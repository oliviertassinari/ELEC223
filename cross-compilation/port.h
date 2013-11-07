/**
 * Port macros
 */

#ifndef PORT_H
#define PORT_H

#define getPortMask(n) (1 << (n))

// Write port bits with a mask, other bits left alone
#define setPortMaskZero(port, mask) ((port) &= ~(mask))
#define setPortMaskOne(port, mask) ((port) |= (mask))

#define setPortMask(port, mask, value)                                  \
  (value ? setPortMaskOne(port, mask) : setPortMaskZero(port, mask))

#define setPort(port, n, value) (setPortMask(port, getPortMask(n), value))

#endif
