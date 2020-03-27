/* Includes ------------------------------------------------------------------*/
#include <assert.h>
#include "ring_buffer.h"


bool RingBuffer_Init(RingBuffer *ringBuffer, char *dataBuffer, size_t dataBufferSize) 
{
	assert(ringBuffer);
	assert(dataBuffer);
	assert(dataBufferSize > 0);
	
	if ((ringBuffer) && (dataBuffer) && (dataBufferSize > 0)) {
	  ringBuffer->buffer_char = dataBuffer;
	  ringBuffer->length = 0;
	  ringBuffer->capacity = dataBufferSize;
	  return true;
	}
	
	return false;
}

bool RingBuffer_Clear(RingBuffer *ringBuffer)
{
	assert(ringBuffer);
	
	if (ringBuffer) {
		ringBuffer->length = 0;
		return true;
	}
	return false;
}

bool RingBuffer_IsEmpty(const RingBuffer *ringBuffer)
{
  assert(ringBuffer);	
   if (ringBuffer->length == 0){
	
	return true;
       
   }
   return false;
   
}

size_t RingBuffer_GetLen(const RingBuffer *ringBuffer)
{
	assert(ringBuffer);
	
	if (ringBuffer) {
		return ringBuffer->length;
	}
	return 0;
	
}

size_t RingBuffer_GetCapacity(const RingBuffer *ringBuffer)
{
	assert(ringBuffer);
	
	if (ringBuffer) {
	return ringBuffer->capacity;
	}
	return 0;	
}


bool RingBuffer_PutChar(RingBuffer *ringBuffer, char c)
{
	assert(ringBuffer);
	
	if (ringBuffer) {
	    
	    
		if (ringBuffer->length >= ringBuffer->capacity)
		{
		    return false;
		}
		for (size_t i = 1 ; i <= ringBuffer->length ; i++)
		{
		    ringBuffer->buffer_char[ringBuffer->length - i + 1] = ringBuffer -> buffer_char[ringBuffer->length  - i];
		}
		ringBuffer->buffer_char[0] = c;
		ringBuffer->length = ringBuffer->length + 1;
		return true;
	}
	return false;
}

bool RingBuffer_GetChar(RingBuffer *ringBuffer, char *c)
{
	assert(ringBuffer);
	assert(c);
	
  if ((ringBuffer) && (c)) {
		int len = ringBuffer-> length;
		*c = ringBuffer->buffer_char[len-1];
		ringBuffer->length = ringBuffer->length - 1;
		ringBuffer->buffer_char[len-1] = '\0';
		return true;
	}
	return false;
}
