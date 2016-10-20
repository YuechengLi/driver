/*
 * Atmel WILC3000 802.11 b/g/n and Bluetooth Combo driver
 *
 * Copyright (c) 2015 Atmel Corportation
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef WILC_WLAN_H
#define WILC_WLAN_H

#include "wilc_type.h"

#define ISWILC3000(id)   (((id & 0xfffff000) == 0x300000) ? 1 : 0)

/*
 * externs
 */
void chip_sleep_manually(u32 u32SleepTime, int source);

/*
 * Mac eth header length
 */
#define DRIVER_HANDLER_SIZE		4
#define MAX_MAC_HDR_LEN			26 /* QOS_MAC_HDR_LEN */
#define SUB_MSDU_HEADER_LENGTH		14
#define SNAP_HDR_LEN			8
#define ETHERNET_HDR_LEN		14
#define WORD_ALIGNMENT_PAD		0

#define ETH_ETHERNET_HDR_OFFSET	(MAX_MAC_HDR_LEN \
				+ SUB_MSDU_HEADER_LENGTH \
				+ SNAP_HDR_LEN \
				- ETHERNET_HDR_LEN \
				+ WORD_ALIGNMENT_PAD)
/*
 * transmitting mgmt frames received from host
 */
#define HOST_HDR_OFFSET			4
#define ETHERNET_HDR_LEN		14
#define IP_HDR_LEN			20
#define IP_HDR_OFFSET			ETHERNET_HDR_LEN
#define UDP_HDR_OFFSET			(IP_HDR_LEN + IP_HDR_OFFSET)
#define UDP_HDR_LEN			8
#define UDP_DATA_OFFSET			(UDP_HDR_OFFSET + UDP_HDR_LEN)
#define ETH_CONFIG_PKT_HDR_LEN		UDP_DATA_OFFSET
#define ETH_CONFIG_PKT_HDR_OFFSET	(ETH_ETHERNET_HDR_OFFSET \
					+ ETH_CONFIG_PKT_HDR_LEN)

/*ATWILCSW-404*/
#define PKT_STATUS_NEW		0
#define PKT_STATUS_BUFFERED	1
/*
 * Endian Conversion
 */
#define BYTE_SWAP(val) ((((val) & 0x000000FF) << 24) + \
			(((val) & 0x0000FF00) << 8)  + \
			(((val) & 0x00FF0000) >> 8)  +	\
			(((val) & 0xFF000000) >> 24))

/*
 * Register Defines
 */
#define WILC_PERIPH_REG_BASE		0x1000
#define WILC_CHIPID			(WILC_PERIPH_REG_BASE)
#define WILC_GLB_RESET_0		(WILC_PERIPH_REG_BASE + 0x400)
#define WILC_PIN_MUX_0			(WILC_PERIPH_REG_BASE + 0x408)
#define WILC_HOST_TX_CTRL		(WILC_PERIPH_REG_BASE + 0x6c)
#define WILC_HOST_RX_CTRL_0		(WILC_PERIPH_REG_BASE + 0x70)
#define WILC_HOST_RX_CTRL_1		(WILC_PERIPH_REG_BASE + 0x74)
#define WILC_HOST_VMM_CTL		(WILC_PERIPH_REG_BASE + 0x78)
#define WILC_HOST_RX_CTRL		(WILC_PERIPH_REG_BASE + 0x80)
#define WILC_HOST_RX_EXTRA_SIZE		(WILC_PERIPH_REG_BASE + 0x84)
#define WILC_HOST_TX_CTRL_1		(WILC_PERIPH_REG_BASE + 0x88)
#define WILC_INTERRUPT_CORTUS_0		(WILC_PERIPH_REG_BASE + 0xa8)
#define WILC_MISC			(WILC_PERIPH_REG_BASE + 0x428)
#define WILC_INTR_REG_BASE		(WILC_PERIPH_REG_BASE + 0xa00)
#define WILC_INTR_ENABLE		(WILC_INTR_REG_BASE)
#define WILC_INTR2_ENABLE		(WILC_INTR_REG_BASE + 4)
#define WILC_INTR_POLARITY		(WILC_INTR_REG_BASE + 0x10)
#define WILC_INTR_TYPE			(WILC_INTR_REG_BASE + 0x20)
#define WILC_INTR_CLEAR			(WILC_INTR_REG_BASE + 0x30)
#define WILC_INTR_STATUS		(WILC_INTR_REG_BASE + 0x40)
#define WILC_VMM_TBL_SIZE		64
#define WILC_VMM_TX_TBL_BASE		(0x150400)
#define WILC_VMM_RX_TBL_BASE		(0x150500)
#define WILC_VMM_BASE			0x150000
#define WILC_VMM_CORE_CTL		(WILC_VMM_BASE)
#define WILC_VMM_TBL_CTL		(WILC_VMM_BASE + 0x4)
#define WILC_VMM_TBL_ENTRY		(WILC_VMM_BASE + 0x8)
#define WILC_VMM_TBL0_SIZE		(WILC_VMM_BASE + 0xc)
#define WILC_VMM_TO_HOST_SIZE		(WILC_VMM_BASE + 0x10)
#define WILC_VMM_CORE_CFG		(WILC_VMM_BASE + 0x14)
#define WILC_VMM_TBL_ACTIVE		(WILC_VMM_BASE + 040)
#define WILC_VMM_TBL_STATUS		(WILC_VMM_BASE + 0x44)
#define WILC_SPI_REG_BASE		0xe800
#define WILC_SPI_CTL			(WILC_SPI_REG_BASE)
#define WILC_SPI_MASTER_DMA_ADDR	(WILC_SPI_REG_BASE + 0x4)
#define WILC_SPI_MASTER_DMA_COUNT	(WILC_SPI_REG_BASE + 0x8)
#define WILC_SPI_SLAVE_DMA_ADDR		(WILC_SPI_REG_BASE + 0xc)
#define WILC_SPI_SLAVE_DMA_COUNT	(WILC_SPI_REG_BASE + 0x10)
#define WILC_SPI_TX_MODE		(WILC_SPI_REG_BASE + 0x20)
#define WILC_SPI_PROTOCOL_CONFIG	(WILC_SPI_REG_BASE + 0x24)
#define WILC_SPI_INTR_CTL		(WILC_SPI_REG_BASE + 0x2c)

#define WILC_SPI_PROTOCOL_OFFSET	\
	(WILC_SPI_PROTOCOL_CONFIG - WILC_SPI_REG_BASE)

#define WILC_AHB_DATA_MEM_BASE		0x30000
#define WILC_AHB_SHARE_MEM_BASE		0xd0000
#define WILC_VMM_TBL_RX_SHADOW_BASE	WILC_AHB_SHARE_MEM_BASE
#define WILC_VMM_TBL_RX_SHADOW_SIZE	(256)
#define WILC_GP_REG_0			0x149c
#define WILC_GP_REG_1			0x14a0
#define rCOEXIST_CTL			(0x161E00)
#define rGLOBAL_MODE_CONTROL		(0x1614)
#define rPWR_SEQ_MISC_CTRL		(0x3008)
#define rCOE_AUTO_PS_ON_NULL_PKT 	(0x160468)
#define rCOE_AUTO_PS_OFF_NULL_PKT (0x16046C)
#define rPA_CONTROL				(0x9804)
#define rHAVE_SDIO_IRQ_GPIO_BIT		(0)
#define rHAVE_SLEEP_CLK_SRC_RTC_BIT	(2)
#define rHAVE_SLEEP_CLK_SRC_XO_BIT	(3)
#define rFILTER_WIFI_LOGS_BIT		(8)
#define rHAVE_ANT_SWTCH_SNGL_GPIO_CTRL_BIT	(9)
#define rHAVE_ANT_SWTCH_DUAL_GPIO_CTRL_BIT	(10)

#define WILC_HAVE_SDIO_IRQ_GPIO		(1 << rHAVE_SDIO_IRQ_GPIO_BIT)
#define WILC_HAVE_SLEEP_CLK_SRC_RTC	(1 << rHAVE_SLEEP_CLK_SRC_RTC_BIT)
#define WILC_HAVE_SLEEP_CLK_SRC_XO	(1 << rHAVE_SLEEP_CLK_SRC_XO_BIT)
#define WILC_FILTER_WIFI_LOGS		(1 << rFILTER_WIFI_LOGS_BIT)
#define WILC_HAVE_ANT_SWTCH_SNGL_GPIO_CTRL (1 << rHAVE_ANT_SWTCH_SNGL_GPIO_CTRL_BIT)
#define WILC_HAVE_ANT_SWTCH_DUAL_GPIO_CTRL (1 << rHAVE_ANT_SWTCH_DUAL_GPIO_CTRL_BIT)

/*
 * Wlan Defines
 */
#define WILC_CFG_PKT		1
#define WILC_NET_PKT		0
/*
 * transmitting mgmt frames received from host
 */
#ifdef WILC_AP_EXTERNAL_MLME
#define WILC_MGMT_PKT		2
#endif	/* WILC_AP_EXTERNAL_MLME */
#define WILC_CFG_SET		1
#define WILC_CFG_QUERY		0
#define WILC_CFG_RSP		1
#define WILC_CFG_RSP_STATUS	2
#define WILC_CFG_RSP_SCAN	3
#ifdef WILC_SDIO
#define WILC_PLL_TO		4
#else
#define WILC_PLL_TO		2
#endif	/* WILC_SDIO */
#define ABORT_INT		(1 << 31)

/*
 * E0 and later Interrupt flags.
 * IRQ Status word
 * 15:0 = DMA count in words
 * 16: INT0 flag
 * 17: INT1 flag
 * 18: INT2 flag
 * 19: INT3 flag
 * 20: INT4 flag
 * 21: INT5 flag
 */
#define IRG_FLAGS_OFFSET	16
#define IRQ_DMA_WD_CNT_MASK	((1ul << IRG_FLAGS_OFFSET) - 1)
#define INT_0			(1 << (IRG_FLAGS_OFFSET))
#define INT_1			(1 << (IRG_FLAGS_OFFSET + 1))
#define INT_2			(1 << (IRG_FLAGS_OFFSET + 2))
#define INT_3			(1 << (IRG_FLAGS_OFFSET + 3))
#define INT_4			(1 << (IRG_FLAGS_OFFSET + 4))
#define INT_5			(1 << (IRG_FLAGS_OFFSET + 5))
#define MAX_NUM_INT		(6)

/*
 * E0 and later Interrupt flags.
 * IRQ Clear word
 * 0: Clear INT0
 * 1: Clear INT1
 * 2: Clear INT2
 * 3: Clear INT3
 * 4: Clear INT4
 * 5: Clear INT5
 * 6: Select VMM table 1
 * 7: Select VMM table 2
 * 8: Enable VMM
 */
#define CLR_INT0		(1 << 0)
#define CLR_INT1		(1 << 1)
#define CLR_INT2		(1 << 2)
#define CLR_INT3		(1 << 3)
#define CLR_INT4		(1 << 4)
#define CLR_INT5		(1 << 5)
#define SEL_VMM_TBL0		(1 << 6)
#define SEL_VMM_TBL1		(1 << 7)
#define EN_VMM			(1 << 8)

#define DATA_INT_EXT		INT_0
#define PLL_INT_EXT		INT_1
#define ALL_INT_EXT		(DATA_INT_EXT | PLL_INT_EXT)
#define NUM_INT_EXT		(2)

#define DATA_INT_CLR		CLR_INT0
#define PLL_INT_CLR		CLR_INT1
#define SLEEP_INT_CLR		CLR_INT2

#define ENABLE_RX_VMM		(SEL_VMM_TBL1 | EN_VMM)
#define ENABLE_TX_VMM		(SEL_VMM_TBL0 | EN_VMM)

/*
 * time for expiring the semaphores of
 * cfg packets
 */
#define CFG_PKTS_TIMEOUT	2000

/*
 * Tx/Rx Queue Structure
 */
struct txq_entry_t {
	struct txq_entry_t *next;
	struct txq_entry_t *prev;
	int type;
	uint8_t q_num;
	int tcp_PendingAck_index;
	uint8_t *buffer;
	int buffer_size;
	void *priv;
	int status;
	void (*tx_complete_func)(void *, int);
};

struct rxq_entry_t {
	struct rxq_entry_t *next;
	uint8_t *buffer;
	int buffer_size;
};

/*
 * Configuration Structure
 */
#define MAX_CFG_FRAME_SIZE 1468

struct wilc_cfg_frame {
	uint8_t ether_header[14];
	uint8_t ip_header[20];
	uint8_t udp_header[8];
	uint8_t wid_header[8];
	uint8_t frame[MAX_CFG_FRAME_SIZE];
};

struct wilc_cfg_rsp {
	int type;
	uint32_t seq_no;
};

struct wilc_cfg_func {
	int (*cfg_wid_set)(uint8_t *, uint32_t, uint16_t, uint8_t *, int);
	int (*cfg_wid_get)(uint8_t *, uint32_t, uint16_t);
	int (*cfg_wid_get_val)(uint16_t, uint8_t *, uint32_t);
	int (*rx_indicate)(uint8_t *, int, struct wilc_cfg_rsp *);
	int (*cfg_init)(void);
};
void chip_sleep_manually(unsigned int u32SleepTime , int source);

void wilc_host_sleep_notify( int source);
void wilc_host_wakeup_notify(int source);
#define NQUEUES 4
#define VO_AC_COUNT_POS		25
#define VO_AC_ACM_STAT_POS	24
#define VI_AC_COUNT_POS		17
#define VI_AC_ACM_STAT_POS	16
#define BE_AC_COUNT_POS		9
#define BE_AC_ACM_STAT_POS	8
#define BK_AC_COUNT_POS		2	
#define BK_AC_ACM_STAT_POS	1
#endif
