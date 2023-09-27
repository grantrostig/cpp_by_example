// prepared as part of "password_manager" project
// confidential
#include <iostream>
#include <vector>
#include <variant>
using std::endl, std::cout, std::cerr;

using Int_t=int;
using Bool_t=bool;
using Float_t=float;
using String_t=std::string;

struct alignas (8) Row {  // alignas() may not be required but it makes us feel good.
    Int_t 		my_int {};
    Bool_t 		my_bool {};
    String_t 	my_string {};
    Float_t 	my_float {};
    void print() const {
        cerr<< "my_int:  "<<my_int<<", my_bool :"<<my_bool<<", my_float:"<<my_float<<", my_str  :"<<my_string<<"<<"<<endl;
    }
};
/* struct Row_refs {
    int 		my_int {};
    bool 		my_bool {};
    float 		my_float {};
    std::string my_string {};
    void print() const {
        cerr<< "my_int:"<<my_int<<", my_bool:"<<my_bool<<", my_float:"<<my_float<<", my_string:"<<my_string<<endl;
    }
}; */

using Rows = std::vector<Row>;

static Row insert_row  		{0,0,"init_str_insert",0};  // todo, why can't we designate this a volatile?
static Row read_row       	{0,0,"init_str_read",0};
static Row insert_row_ref  	{0,0,"init_str_insert_ref",0};  // todo, why can't we designate this a volatile?
static Row read_row_ref    	{0,0,"init_str_read_ref",0};

struct Field_specification {
    std::string name {"init_name"};
    void * data_location_insert;
    void * data_location_read;
    void print() const {
        cerr<<"spec."<<"name:"<<std::hex<<name<<", data_location_insert:" <<(long)data_location_insert<<", data_location_read:"<<(long)data_location_read<<endl;
    }
};

struct Field_specification_ref_base {
    String_t	name {"init_name"};
    Field_specification_ref_base() {}
    Field_specification_ref_base( std::string const & name_ ) : name(name_) {
        //data_location_insert = data_location_insert_; //data_location_read = data_location_read_;
    }
    void print() const {
        cerr<<"spec."<<"name:"<<name<<endl; //", data_location_write:" <<data_location_insert<<", data_location_read:"<<data_location_read<<endl;
    }
};

struct Field_specification_ref_int : public Field_specification_ref_base {
    Int_t & data_location_insert;
    Int_t & data_location_read;
    Field_specification_ref_int( String_t const & name_, Int_t & data_location_insert_, Int_t & data_location_read_ )
        : data_location_insert(data_location_insert_), data_location_read(data_location_read_) {
        name = name_;
    }
};

struct Field_specification_ref_bool : public Field_specification_ref_base {
    Bool_t & data_location_insert;
    Bool_t & data_location_read;
    Field_specification_ref_bool( String_t const & name_, Bool_t & data_location_insert_, Bool_t & data_location_read_ )
        : data_location_insert(data_location_insert_), data_location_read(data_location_read_) {
        name = name_;
    }
};

struct Field_specification_ref_float : public Field_specification_ref_base {
    Float_t & data_location_insert;
    Float_t & data_location_read;
    Field_specification_ref_float( String_t const & name_, Float_t & data_location_insert_, Float_t & data_location_read_ )
        : data_location_insert(data_location_insert_), data_location_read(data_location_read_) {
        name = name_;
    }
};

struct Field_specification_ref_string : public Field_specification_ref_base {
    String_t & data_location_insert;
    String_t & data_location_read;
    Field_specification_ref_string( String_t const & name_, String_t & data_location_insert_, String_t & data_location_read_ )
        : data_location_insert(data_location_insert_), data_location_read(data_location_read_) {
        name = name_;
    }
};

using Field_specification_ref_variant =	std::variant<
    Field_specification_ref_int,
    Field_specification_ref_bool,
    Field_specification_ref_string,
    Field_specification_ref_float
    >;
using Specifications = 		std::vector<Field_specification>;
using Specification_refs =	std::vector<Field_specification_ref_variant>;

int main()
{
    Specifications 	my_specs  {
        // todo TODO, how are we supposed to know that a bool takes up 4 bytes when sizeof() is 1, or how do we control alignment?
        //Field_specification { "int  ", &insert_row.my_int, 	  (char*)&read_row }, // todo TODO how to use sizeof()?
        //Field_specification { "bool ", &insert_row.my_bool,   (char*)&read_row + sizeof(insert_row.my_int) },
        //Field_specification { "str  ", &insert_row.my_string, (char*)&read_row + sizeof(insert_row.my_bool) + sizeof(insert_row.my_int) },
        //Field_specification { "float", &insert_row.my_float,  (char*)&read_row + sizeof(insert_row.my_int) + sizeof (insert_row.my_bool)  + sizeof(insert_row.my_string) }
        Field_specification { "int  ", &insert_row.my_int,    (char *)&read_row + ((char *)&insert_row.my_int    - (char *)&insert_row.my_int) },
        Field_specification { "bool ", &insert_row.my_bool,   (char *)&read_row + ((char *)&insert_row.my_bool   - (char *)&insert_row.my_int) },
        Field_specification { "str  ", &insert_row.my_string, (char *)&read_row + ((char *)&insert_row.my_string - (char *)&insert_row.my_int) },
        Field_specification { "float", &insert_row.my_float,  (char *)&read_row + ((char *)&insert_row.my_float  - (char *)&insert_row.my_int) },
    };

    Field_specification_ref_int spec_ref1 		{"int  ", insert_row_ref.my_int, read_row_ref.my_int };
    Field_specification_ref_bool spec_ref2 		{"bool ", insert_row_ref.my_bool, read_row_ref.my_bool };
    Field_specification_ref_string spec_ref3 	{"str  ", insert_row_ref.my_string, read_row_ref.my_string };
    Field_specification_ref_float spec_ref4 	{"float", insert_row_ref.my_float, read_row_ref.my_float };

    Specification_refs 	my_specs_refs  {
        spec_ref1,
        spec_ref2,
        spec_ref3,
        spec_ref4
    };

    cout << "insert_row."; cout << "int  :"<<&insert_row.my_int; cout << ", read:"<<&read_row.my_int<<" sizeof():"<<sizeof (int)<<", "<< sizeof(insert_row.my_int)<<endl;
    cout << "insert_row."; cout << "bool :"<<&insert_row.my_bool; cout << ", read:"<<&read_row.my_bool<<" sizeof():"<<sizeof (bool)<<", "<< sizeof(insert_row.my_bool)<<endl;
    cout << "insert_row."; cout << "str  :"<<&insert_row.my_string; cout << ", read:"<<&read_row.my_string<<" sizeof():"<<sizeof (std::string)<<", "<< sizeof(insert_row.my_string)<<endl;
    cout << "insert_row."; cout << "float:"<<&insert_row.my_float; cout << ", read:"<<&read_row.my_float<<" sizeof():"<<sizeof (float)<<", "<< sizeof(insert_row.my_float)<<endl;
    for( auto & i:my_specs ) {
        i.print();
    }
    cout << "<<sizeof (long):"<< sizeof(long)<<endl;
    cout << "<<sizeof (long long):"<< sizeof(long long)<<endl;
    cout << "<<sizeof (double):"<< sizeof(double)<<endl;
    cout << "<<sizeof (long double):"<< sizeof(long double)<<endl;

    Rows my_rows {
        {2,1,"str2",2.01f},
        {3,1,"str3",3.01f}
    };

    insert_row.print();
    *((int *)(my_specs.at(0).data_location_insert)) = 97;
    *((bool *)(my_specs.at(1).data_location_insert)) = 0;
    *((std::string *)(my_specs.at(2).data_location_insert)) = "str97;lkj;lkj;lkj;lkj;lkj;lkj;lkj;lkj;lkj;lkj";
    *((float *)(my_specs.at(3).data_location_insert)) = 97.01f;
    insert_row.print();

    read_row.print();
    *((int *)(my_specs.at(0).data_location_read)) = 98;
    *((bool *)(my_specs.at(1).data_location_read)) = 0;
    *((std::string *)(my_specs.at(2).data_location_read)) = "str98;lkj;lkj;lkj;lkj;lkj;lkj;lkj;lkj;lkj;lkj";
    *((float *)(my_specs.at(3).data_location_read)) = 98.01f;
    read_row.print();

    my_rows.push_back( insert_row );
    my_rows.push_back( read_row );

    cerr<<"Dump the rows.\n";
    for (auto & i:my_rows) {
        i.print();
    }

    cerr<<"Read,copy whole row at once and dump the rows.\n";
    for (auto & i:my_rows) {
        // read_row.print();
        (read_row = i).print(); // copy the entire row
    }

    cerr<<"Read whole row, field by field and dump the row for all rows.\n";
    for (auto & i:my_rows) {
        insert_row = i;
        insert_row.print();
        int field_index {0};
        for (auto & fs:my_specs) {
            switch (field_index) {
            case 0 :
                // *((int *)(fs.data_location_read)) = *((int *)(fs.data_location_insert)); break;
                //int temp = *(reinterpret_cast<int const *>(fs.data_location_insert)); break;
                //*(reinterpret_cast<int *>(fs.data_location_read)) = temp;
                *(reinterpret_cast<int *>(fs.data_location_read)) = *(reinterpret_cast<int const *>(fs.data_location_insert)); break;
            case 1 :
                *(reinterpret_cast<bool *>(fs.data_location_read)) = *(reinterpret_cast<bool const *>(fs.data_location_insert)); break;
            case 2 :
                *(reinterpret_cast<std::string *>(fs.data_location_read)) = *(reinterpret_cast<std::string const *>(fs.data_location_insert)); break;
            case 3 :
                *(reinterpret_cast<float *>(fs.data_location_read)) = *(reinterpret_cast<float const *>(fs.data_location_insert)); break;
            }
            ++field_index;
        }
        read_row.print(); // copy the entire row
        *((std::string *)(my_specs.at(2).data_location_read)) = "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkstr98;lkj;lkj;lkj;lkj;lkj;lkj;lkj;lkj;lkj;lkj";
        read_row.print(); // copy the entire row
        *((std::string *)(my_specs.at(2).data_location_read)) = "str98";
        read_row.print(); // copy the entire row
        *((std::string *)(my_specs.at(2).data_location_read)) = "";
        read_row.print(); // copy the entire row
        *((std::string *)(my_specs.at(2).data_location_read)) = "str98;lkj;lkj;lkj;lkj;lkj;lkj;lkj;lkj;lkj;lkj";
        read_row.print(); // copy the entire row
    }

    cout << "\n###" << endl;
    return 0;
}
