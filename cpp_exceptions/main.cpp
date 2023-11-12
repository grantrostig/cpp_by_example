#include <iostream>

#include <exception>
#include <stdexcept>
#include <system_error>
#include <ios>
#include <filesystem>

struct My_error_class {
    int code;  				// todo:
    const std::string message;
    explicit My_error_class(std::string const message_) noexcept :message(message_) {}
    std::string const what() noexcept {
        std::cerr << "in My_error_class()\n";
        return message;
    }
};

[[noreturn]]
void my_error(std::string what) {  // not noexcept b/c is has a throw()!
    std::cerr << "in my_error(): what: "<< what << "\n";
    // std::runtime_error e(what);
    My_error_class e(what);
    throw e;
}

int main()
{
    try {
        if ( !std::cin ) my_error("!cin.");
    } catch (...) {
        std::cerr << "main try 1: catch ..."<<std::endl;
        throw;
    }

    try {
        if ( false ) my_error("!cin.");
    } catch (...) {
        std::cerr << "main try 2: catch ..."<<std::endl;
        throw;
    }

    try {
    }
    //  std:: heirarchy
    //  #include <exception>
    catch (std::exception & e){
        return 1;
    }
        // #include <stdexcept>
        catch (std::bad_alloc & e) {
            std::cout<< e.what();
        return 1;
        }
        catch (std::bad_exception & e) { return 1;}
        catch (std::bad_cast & e) { return 1;}

        catch (std::logic_error & e) { return 1;}
            catch (std::domain_error & e) { return 1;}
            catch (std::invalid_argument & e) { return 1;}
            catch (std::length_error & e) { return 1;}
            catch (std::out_of_range & e) { return 1;}

        catch (std::runtime_error & e) { return 1;}
            catch (std::underflow_error & e) { return 1;}
            catch (std::overflow_error & e) { return 1;}
            catch (std::range_error & e) { return 1;}

            // #include <system_error>
            catch (std::system_error & e) { return 1;}
                // #include <ios>
                catch (std::ios_base::failure & e) { return 1;}

                // #include <filesystem>
                catch (std::filesystem::filesystem_error & e) {
                    std::cout<< e.code();  // some error have a code!
                    std::cout<< e.what();
                return 1;
            }

    // user's heirarchy
    catch (My_error_class & e) {
        // do something like:
       std::cerr << "My_error_class thrown.\n";
       throw e;
    }
    // todo: does this provide any information on the error?
    catch (...) {
       std::cerr << "main() catch... thrown.\n";
       return 1;
    }				// user defined errors and catch all

    std::cout << "###" << std::endl;
    return 0;
}
