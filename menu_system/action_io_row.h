#ifndef ACTION_IO_ROW_H
#define ACTION_IO_ROW_H
#include <string>
#include <vector>
#include <any>
#include <variant>
#include "state_menu.h"
#include "interaction_result.h"
#include "io_table.h"

InteractionResult action_io_row_list( State_menu & state, IO_table & table );
InteractionResult action_io_row_select( State_menu & state, IO_table & table  );
InteractionResult action_io_row_create( State_menu & state, IO_table & table  );
InteractionResult action_io_row_read( State_menu & state, IO_table & table  );
InteractionResult action_io_row_update( State_menu & state, IO_table & table  );
InteractionResult action_io_row_delete( State_menu & state, IO_table & table  );

#endif // ACTION_IO_ROW_H
