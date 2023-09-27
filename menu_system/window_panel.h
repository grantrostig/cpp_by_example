#ifndef WINDOW_PANEL_H
#define WINDOW_PANEL_H
#include "menu_option.h"

using std::cin, std::cout, std::endl, std::cerr;

/* Used when starting a new output operation.
 * used_xy denotes the initial output
 * todo: it is assumed to fit in the panel, should check, but what to do if it won't!?
 */
void pagination_reset( State_menu & state, Panel_dimensions const & used_content);

/*
 * Verify that the proposed content will fit in the panel.
 * next_xy : the number of lines, and the max length of any one of those lines.
 */
InteractionResult pagination( State_menu & state, Panel_dimensions const & proposed_content);

#endif // WINDOW_PANEL_H
