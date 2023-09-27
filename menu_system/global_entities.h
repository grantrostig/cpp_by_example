#ifndef GLOBAL_ENTITIES_H
#define GLOBAL_ENTITIES_H

#define IO_ROW_FIELDS_NUM_MAX 		20 // zero origin, so human number is: this value + 1
#define IO_ROW_FIELDS_NUM_PERSON 	8 // zero origin, so human number is: this value + 1
static_assert ( IO_ROW_FIELDS_NUM_MAX >= IO_ROW_FIELDS_NUM_PERSON );

#endif // GLOBAL_ENTITIES_H
