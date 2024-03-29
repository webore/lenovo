/* linux/drivers/video/samsung/s5p-dsim.h
 *
 * Header file for Samsung MIPI-DSIM driver.
 *
 * Copyright (c) 2009 Samsung Electronics
 * InKi Dae <inki.dae@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Modified by Samsung Electronics (UK) on May 2010
 *
*/

#ifndef _S5P_DSIM_H
#define _S5P_DSIM_H

#include <linux/device.h>

typedef enum {
	Ack = 0x02,
	EoTp = 0x08,
	GenShort1B = 0x11,
	GenShort2B = 0x12,
	GenLong = 0x1a,
	DcsLong = 0x1c,
	DcsShort1B = 0x21,
	DcsShort2B = 0x22,
} dsim_read_id;

struct mipi_lcd_driver {
	s8	name[64];

	s32	(*pre_init)(void);
	s32	(*init)(void);
	void	(*display_on)(struct device *dev);
	s32	(*set_link)(void *pd, u32 dsim_base,
		u8 (*cmd_write)(u32 dsim_base, u32 data0, u32 data1, u32 data2),
		u8 (*cmd_read)(u32 dsim_base, u32 data0, u32 data1, u32 data2));
	s32	(*probe)(struct device *dev);
	s32	(*remove)(struct device *dev);
	void	(*shutdown)(struct device *dev);
	s32	(*suspend)(void);
	s32	(*resume)(struct device *dev);

	bool	(*partial_mode_status)(struct device *dev);
	int     (*partial_mode_on)(struct device *dev, u8 display);
	int     (*partial_mode_off)(struct device *dev);
	void	(*display_off)(struct device *dev);
	int	(*is_panel_on)(void);
};

int s5p_dsim_register_lcd_driver(struct mipi_lcd_driver *lcd_drv);
void s5p_dsim_read_rx_fifo(unsigned int dsim_base , u32* pbuf, u32* psize);
void s5p_dsim_clr_state(unsigned int dsim_base, DSIM_INTSRC eIntSrc);
 u8 s5p_dsim_wait_state(unsigned int dsim_base, DSIM_INTSRC  eIntSrc);
 void s5p_dsim_frame_done_interrupt_enable(u8 enable);
#endif /* _S5P_DSIM_LOWLEVEL_H */
