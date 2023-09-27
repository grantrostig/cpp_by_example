#include "state_menu.h"
#include <memory>
#include <cassert>
#include <stdexcept>
#include "menu.h"

std::shared_ptr<Menu> State_menu::menu_top_sp() const
{
    return menu_stack.top();
}

void State_menu::push_menu_sp (std::shared_ptr<Menu> const sp) {
    menu_stack.push( sp );
}

std::shared_ptr<Menu> State_menu::menu_pop_top_sp() {
    if ( menu_stack.size() < 1 ) throw( std::logic_error( "State_menu::menu_pop_top_sp(): Empty stack." ));
    menu_stack.pop();
    return menu_stack.top();
}

std::shared_ptr<Menu> State_menu::menu_pop_to_sp(std::shared_ptr<Menu> const sp) {
    auto current  = menu_stack.top();
    while ( sp != current ) {
        if ( menu_stack.size() > 0 )
            menu_stack.pop();
        else
            throw( std::logic_error( "State_menu::menu_pop_to_sp(): Empty stack." ));
        current = menu_stack.top();
    }
    return current;
}

bool State_menu::is_menu_current_main() const
{
    return ( menu_stack.top() == menu_main_sp );
}

std::shared_ptr<State_application> State_menu::getApplication_data() const
{
    return application_data_sp;
}

void State_menu::setApplication_data(const std::shared_ptr<State_application> &value)
{
    application_data_sp = value;
}

//std::shared_ptr<Menu> State_menu::getMenu_prior() const
//{
//    return menu_prior_sp;
//}

//void State_menu::setMenu_prior(const std::shared_ptr<Menu> &value)
//{
//    menu_prior_sp = value;
//}

//std::shared_ptr<Menu> State_menu::getMenu_current() const
//{
//    return menu_current_sp;
//}

//void State_menu::setMenu_current(const std::shared_ptr<Menu> &value)
//{
//    menu_current_sp = value;
//}

bool State_menu::getAdvanced_menu_enabled() const
{
    return advanced_menu_enabled;
}

void State_menu::setAdvanced_menu_enabled(bool value)
{
    advanced_menu_enabled = value;
}

bool State_menu::getIs_data_unsaved() const
{
    return is_data_saved;
}

void State_menu::setIs_data_unsaved(bool value)
{
    is_data_saved = value;
}

std::shared_ptr<Menu> State_menu::getMenu_main() const
{
    return menu_main_sp;
}

void State_menu::setMenu_main(const std::shared_ptr<Menu> &value)
{
    menu_main_sp = value;
}

std::shared_ptr<Menu> State_menu::getMenu_edit() const
{
    return menu_edit_sp;
}

void State_menu::setMenu_edit(const std::shared_ptr<Menu> &value)
{
    menu_edit_sp = value;
}

std::shared_ptr<Menu> State_menu::getMenu_file() const
{
    return menu_file_sp;
}

void State_menu::setMenu_file(const std::shared_ptr<Menu> &value)
{
    menu_file_sp = value;
}

std::shared_ptr<Menu> State_menu::getMenu_settings() const
{
    return menu_settings_sp;
}

void State_menu::setMenu_settings(const std::shared_ptr<Menu> &value)
{
    menu_settings_sp = value;
}

// State::State( Menu * m_ptr) {
// menu_current = std::shared_ptr<Menu>( std::move(m_ptr) );
// }
