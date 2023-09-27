#ifndef STATE_H
#define STATE_H
#include <vector>
#include <memory>
#include <stack>
#include "state_application.h"
struct Menu;
class State_menu {  // holds all state/data used by the menu system, but not data of the user's application.
    std::shared_ptr<Menu> menu_main_sp 	   {};	// required
    std::shared_ptr<Menu> menu_edit_sp     {};	// optional, edit show as example, programmer defined meaning.
    std::shared_ptr<Menu> menu_file_sp     {};	// optional, edit show as example, programmer defined meaning.
    std::shared_ptr<Menu> menu_settings_sp {};	// optional, file shown as another example, programmer defined meaning.
    std::stack<std::shared_ptr<Menu>>  menu_stack {};
    std::shared_ptr<State_application> application_data_sp {};
    bool advanced_menu_enabled {false}; // the user is being shown the additional menu options designated as 'advanced'.
    bool is_data_saved 		   {true};  		// the menu system has unsaved data input/editing that has not been committed to disk.;	// optional, file shown as another example, programmer defined meaning.
public:
    std::shared_ptr<Menu> menu_top_sp()   const;
    void                  push_menu_sp(   std::shared_ptr<Menu> const);
    std::shared_ptr<Menu> menu_pop_top_sp();
    std::shared_ptr<Menu> menu_pop_to_sp( std::shared_ptr<Menu> const);

    bool is_menu_current_main ()    const;
    bool getAdvanced_menu_enabled() const;
    void setAdvanced_menu_enabled(  bool value);
    bool getIs_data_unsaved() 		const;
    void setIs_data_unsaved(  		bool value);

    std::shared_ptr<Menu> getMenu_main() const;
    void 				  setMenu_main(const std::shared_ptr<Menu> &);

    std::shared_ptr<Menu> getMenu_edit() const;
    void 				  setMenu_edit(const std::shared_ptr<Menu> &);

    std::shared_ptr<Menu> getMenu_file() const;
    void  				  setMenu_file(const std::shared_ptr<Menu> &);

    std::shared_ptr<Menu> getMenu_settings() const;
    void 				  setMenu_settings(const std::shared_ptr<Menu> &);

    std::shared_ptr<State_application> getApplication_data() const;
    void 				               setApplication_data( const std::shared_ptr<State_application> &);
};

#endif // STATE_H
