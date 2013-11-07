/**
 * Port macros
 */

#ifndef PORT_H
#define PORT_H

#define getPortMask(n) (1 << (n))

// Write port bits with a mask, other bits left alone
#define setPortMaskZero(port, mask) ((port) &= ~(mask))
#define setPortMaskOne(port, mask) ((port) |= (mask))

#define setPortZero(port, n) (setPortMaskZero(port, getPortMask(n)))
#define setPortOne(port, n) (setPortMaskOne(port, getPortMask(n)))

#endif
