/*
 * Copyright (c) 2014 ETH Zurich.
 * All rights reserved.
 *
 * This file is distributed under the terms in the attached LICENSE file.
 * If you do not find this file, copies can be found by writing to:
 * ETH Zurich D-INFK, Universitaetsstrasse 6, CH-8092 Zurich. Attn: Systems Group.
 */

#ifndef LIB_XOMP_MASTER_H_
#define LIB_XOMP_MASTER_H_


/**
 * \brief initializes the Xeon Phi openMP library
 *
 * \param args struct containing the master initialization values
 *
 * \returns SYS_ERR_OK on success
 *          errval on failure
 */
errval_t xomp_master_init(struct xomp_args *args);

/**
 * \brief Spawns the worker threads on the Xeon Phi
 *
 * \param nworkers    Number of total workers this includes the Master
 *
 * \returns SYS_ERR_OK on success
 *          errval on failure
 */
errval_t xomp_master_spawn_workers(uint32_t nworkers);

/**
 * \brief Adds a memory region to be used for work
 *
 * \param frame Frame to be shared
 * \param info  information about the frame i.e. virtual address to map
 * \oaram type  Type of the frame
 *
 * \returns SYS_ERR_OK on success
 *          errval on error
 */
errval_t xomp_master_add_memory(struct capref frame,
                                uint64_t info,
                                xomp_frame_type_t type);

/**
 * \brief executes some work on each worker domains
 *
 * \param task information about the task
 *
 * \returns SYS_ERR_OK on success
 *          errval on error
 */
errval_t xomp_master_do_work(struct xomp_task *task);

/**
 * \brief builds the argument path based on the own binary name
 *
 * \param local  pointer where to store the local path
 * \param remote pointer where to store the remote path
 *
 * \returns SYS_ERR_OK on success
 */
errval_t xomp_master_build_path(char **local, char **remote);

#endif // LIB_XOMP_MASTER_H_
