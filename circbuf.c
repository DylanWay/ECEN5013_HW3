/***************************************************************************
*
*   Filename: circbuf.c
*   Description: 
*                    
*   Author: Dylan Way
*       
****************************************************************************/
#include "circbuf.h"

// Checks if the circular buffer is full. Returns 1 if full, otherwise returns 0.
int8_t buffer_full(CircBuf *cb) {
    if( cb->num_items == cb->size ) {return 1};
    return 0;
}

// Checks if the circular buffer is empty. Returns 1 if empty, otherwise returns 0.
int8_t buffer_empty(CircBuf *cb) {
    if( cb->num_items == 0 ) {return 1};
    return 0;
}

// Adds an item to the circular buffer if the buffer is not full. If full, returns an error.
int8_t add_buffer_item(CircBuf *cb, void *item) {
    // Checks if buffer is full, returns error if true
    if( buffer_full(cb) ) {return 1};
    // Adds item to the circular buffer
    if( cb->tail == cb->buf_end ) {
        cb->tail = cb->buffer;
    }
    else {
        cb->tail = cb->tail + cb->item_size;
    }
    *cb->tail = *item;
    return 0;
}

// Removes an item from the circular buffer if the buffer is not empty. If empty, returns an error.
int8_t remove_buffer_item(CircBuf *cb, void *item) {
    // Checks if buffer is empty, returns error if true
    if( buffer_empty(cb) ) {return 1};
    // Removes item from the circular buffer and writes the removed item to item pointer
    *item = *cb->head;
    if( cb->head == cb->buf_end ) {
        cb->head = cb->buffer;
    }
    else {
        cb->head = cb->head + cb->item_size;
    }
    return 0;
}
