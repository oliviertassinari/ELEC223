/**
 * Port macros
 */

#ifndef PORT_H
#define PORT_H

// PCONC Configures the pins of port C
#define PCONC (*(volatile uint32_t *)0x01D20010)

// PDATC The data register for port C
#define PDATC (*(volatile uint32_t *)0x01D20014)

// PUPC Pull-up disable register for port C
#define PUPC (*(volatile uint32_t *)0x01D20018)

// PCONE Configures the pins of port E
#define PCONE (*(volatile uint32_t *)0x01D20028)

// PDATE The data register for port E
#define PDATE (*(volatile uint32_t *)0x01D2002C)

// PUPE Pull-up disable register for port E
#define PUPE (*(volatile uint32_t *)0x01D20030)


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
