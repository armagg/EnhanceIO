/*
 *  eio_setMRU.h
 *
 *  Copyright (C) 2012 STEC, Inc. All rights not specifically granted
 *   under a license included herein are reserved
 *  Amit Kale <akale@stec-inc.com>
 *  Harish Pujari <hpujari@stec-inc.com>
 *   Generic MRU implementation used mainly for cache sets
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; under version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 */

#ifndef _EIO_SETMRU_H_
#define _EIO_SETMRU_H_

#define         MRU_NULL        -1

struct mru_elem {
	index_t le_next;
	index_t le_prev;
	u_int64_t le_key;
};

struct mru_ls {
	index_t ll_head;
	index_t ll_tail;
	index_t ll_max;
	u_int64_t ll_size;
	struct mru_elem ll_elem[1];
};

int mru_init(struct mru_ls **llist, index_t max);
void mru_uninit(struct mru_ls *llist);
int mru_add(struct mru_ls *llist, index_t index, u_int64_t key);
int mru_rem(struct mru_ls *llist, index_t index);
int mru_touch(struct mru_ls *llist, index_t index, u_int64_t key);
int mru_read_head(struct mru_ls *llist, index_t *index, u_int64_t *key);
int mru_rem_head(struct mru_ls *llist, index_t *index, u_int64_t *key);

#endif                          /* _EIO_SETMRU_H_ */
