/***************************************************************************
*
*   Filename: circbuf.h
*   Description: Header file for circbuf.c
*                    
*   Author: Dylan Way
*       
****************************************************************************/
#ifndef _CIRCBUF_H
#define _CIRCBUF_H

/* Included libraries */
#include <stdlib.h>

/* Defines section */
// Circular buffer definition from class lecture
typedef struct CircBuf {
    void * buffer;    // Beginning of buffer in memory
    void * buf_end;   // End of the buffer in memory
    void * head;      // Pointer to oldest
    void * tail;      // Pointer to newest
    size_t size;      // Size of the buffer (number of total items)
    size_t item_size  // Size of each item (bytes)
    size_t num_items; // Current number of items
} CircBuf_t;

// Enum for the circular buffer states
enum buffer_states 
{
    EMPTY,
    PARTFILL,
    FULL
} buf_state;

/* Function prototype Section */
// Checks if the circular buffer is full. Returns 1 if full, otherwise returns 0.
int8_t buffer_full(CircBuf *cb);

// Checks if the circular buffer is empty. Returns 1 if empty, otherwise returns 0.
int8_t buffer_empty(CircBuf *cb);

// Adds an item to the circular buffer if the buffer is not full. If full, returns an error.
int8_t add_buffer_item(CircBuf *cb, void *item);

// Removes an item from the circular buffer if the buffer is not empty. If empty, returns an error.
int8_t remove_buffer_item(CircBuf *cb, void *item);

#endif
