#include "objects.h"
#include <stdint.h>


uint32_t objectSize(void)
{
    return sizeof(object_t);
}

object_t * objectCreate(void * _allocated_memory,object_kind_t _kind)
{
    object_t * object = (object_t*)_allocated_memory;
    if (_allocated_memory == NULL)
    {
        printf("objectCreate ERROR: Received NULLPTR!\n");
        return NULL;
    }

    object->kind=_kind;
    return object;
}

void objectDestroy(object_t * _object_to_destroy)
{
    free((void*)_object_to_destroy);

    return ;
}