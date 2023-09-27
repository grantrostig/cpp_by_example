Menu_System - a TUI/CLI interactive moded menu system in C++.

This sub-project shows the use and testing of the code.

This sample program implements the following menu structure:

Main Menu
  File Menu  <f>
    Load <l> {default OR specific file}
    Save <s> {current}
    Save As File Name <a> {file_name}
    Backup <S(bigger save)>

  Edit Entry Menu <e>
    Add <a> {new entry id} // should this be "c" for create?
    Select Entry Id Selection <t(entry)>
      View <v> // list all fields of an entry   
      Edit/Update <u> // "u" for update
      Delete <d> {optional/advanced warning}
    Delete All <X> {mandatory warning}

  Settings Menu <g>
    Screen Size Settings <z> {height, width}
    Show Advanced Selection Setting Switch <A> {T/F}

  List Entries <l> {}
  Search Entries <r> {criteria}
  Delete All <X> (duplicate as above)
  
*Operations supported on all? menus:

Quit <q> // quit the program with save file & data warning(s)
Terminate <T> // quit the programs without warnings
Forward One Page <f> // show another page of output
Back One Page <b> // show previous page of output
Help <h> // display help.  Available at any menu selection or prompt.
Menu <m> // display available menu selections, including universal menu operations.
Home <H> // return to main menu.

TODO: *Operations supported on specific listed menus:
Skip to End of Input: Create, Update
Back One Field:       Create, Update
Back One Page:        List Entries, Search Entries 

