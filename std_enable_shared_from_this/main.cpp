// Grant Rostig, inspired by the work of Jon Kalb.
#include <functional>
#include <iostream>
#include <memory>
#include <unordered_set>
#include <cassert>

struct Task : std::enable_shared_from_this<Task> {
  using Work = 			std::function<auto()->void>;		// or <void()>;
  using TaskSharedPtr = 	std::shared_ptr<Task>;
  using TaskConstSPtr = 	std::shared_ptr<Task const>;		// todo: why needed?
  static std::unordered_set<TaskSharedPtr> 	pending_Tasks;

  [[nodiscard]] static TaskSharedPtr create() { // Best practice is to define a static "construction" function and a private constructor.
    TaskSharedPtr result{new Task{}};           // todo: could have been make_shared<>
    return result;
  }
  void set_work(Work w) {
    work_ = w;
    TaskSharedPtr task {shared_from_this()}; 	// returns: shared_ptr to myself, a Task.
    if (work_) {
      pending_Tasks.insert(task); 	    	// returns: pair/second as bool.
    } else {
      assert(false);
      size_t const num_erased = pending_Tasks.erase(task); 	// todo: is this needed, and what does it do, when?
      std::cout << "set_work():num erased:" << num_erased << std::endl;
    }
  }
  void execute() {
    if (work_) {
      work_();
      size_t const num_erased {pending_Tasks.erase(shared_from_this())};
      std::cout << "execute():num erased:" << num_erased << std::endl;
    } else
      assert(false);
  }
private:
  Task() = default;
  Work 	work_;
};
std::unordered_set<Task::TaskSharedPtr> Task::pending_Tasks{}; 	// Init the static variable in Task type

template <class T> constexpr bool is_shared_type{std::is_base_of_v<std::enable_shared_from_this<T>, T>};	// todo: is this? Check that T is derived from enable_shared_from_this, and so T can get a s_ptr of itself.

template <class T>
//requires is_shared_type<T>
requires std::is_base_of_v<std::enable_shared_from_this<T>, T>		// todo: does this require line benefit from somehow adding "constexpr"?
void print_number_of_owners(T const &owned_obj) { // Returns the number of owners of any object of a type derived from std::enable_shared_from_this
  // Get a shared pointer to this Task object;
  Task::TaskConstSPtr owned_obj_ptr {owned_obj.shared_from_this()}; 	// todo: why does this need to be const?
  std::cout << "owners: " << owned_obj_ptr<<", "<< owned_obj_ptr.use_count() - 1  << "\n";  	// we just created one for the purpose of querying it.
}

int main() {
  /* nothing in this set of comment lines makes sense to me, untill after the blank line.
  // Cannot be created on the stack, which would be unsafe.   // todo: what cannot be created?
  // Task fails;						// todo: what???
  // C++ Concepts feature prevents this from compiling
  // "because 'is_shared_type<std::unordered_set<std::shared_ptr<Task> > >' evaluated to false"

  // how_many_owners(Task::pending_Tasks);
  // Instead we create by calling the static create (psuedo ctor) member
  // auto task_ptr{Task::create()};
  */
  assert(is_shared_type<Task::TaskSharedPtr>);
  bool mystery =  std::is_base_of_v< std::enable_shared_from_this<Task::TaskSharedPtr>, Task::TaskSharedPtr>;
  //static_assert(  std::is_base_of_v< std::enable_shared_from_this<Task::TaskSharedPtr>, Task::TaskSharedPtr> ); // todo: why not compile/work?
  //static_assert(  std::is_base_of< std::enable_shared_from_this<Task::TaskSharedPtr>, Task::TaskSharedPtr> );	  // todo: why not compile/work?
         //assert(  std::is_base_of_v< std::enable_shared_from_this<Task::TaskSharedPtr>, Task::TaskSharedPtr> ); // todo: why not compile/work?

  Task::TaskSharedPtr task_ptr1{Task::create()};
  static_assert(  std::is_base_of_v< std::enable_shared_from_this<Task::TaskSharedPtr>, task_ptr1> );

  std::cout << "Task created\n";
  print_number_of_owners(*task_ptr1);
  task_ptr1->set_work( [] { std::cout << "One worker did work under a task."<<std::endl; });
  std::cout << "Work added to a task; now in pending set.\n";
  print_number_of_owners(*task_ptr1);

  Task::TaskSharedPtr task_ptr2{Task::create()};
  task_ptr2->set_work( [] { std::cout << "One worker did work under a task."<<std::endl; });
  Task::TaskSharedPtr task_ptr3{Task::create()};
  task_ptr3->set_work( [] { std::cout << "One worker did work under a task."<<std::endl; });
  std::cout << "Pending_tasks size:" << Task::pending_Tasks.size() << std::endl;

  std::cout<<"While....\n";
  while (not Task::pending_Tasks.empty()) {
    std::cout<<"One iteration....\n";
    print_number_of_owners(*task_ptr1);
    print_number_of_owners(*task_ptr2);
    print_number_of_owners(*task_ptr3);
    Task::TaskSharedPtr  tsp = *Task::pending_Tasks.cbegin(); // can't execute() this one: Task::TaskConstPtr   b = *Task::pending_Tasks.cbegin();
    Task 		*ptr =  Task::pending_Tasks.cbegin()->get();	// what is the consequence or potential problem of using get() instead of *()?
    print_number_of_owners(*tsp);
    print_number_of_owners(*ptr);
    print_number_of_owners(*task_ptr1);
    print_number_of_owners(*task_ptr2);
    print_number_of_owners(*task_ptr3);
    tsp->execute();
    print_number_of_owners(*tsp);
    ptr->execute();		// does this delete it a second time?
    print_number_of_owners(*ptr);
                                //(*Task::pending_Tasks.begin())->execute();
                                //Task::pending_Tasks.begin() ->get()->execute();
    print_number_of_owners(*task_ptr1);
    print_number_of_owners(*task_ptr2);
    print_number_of_owners(*task_ptr3);
  }
  std::cout<<"After While....Finished all tasks.\n";
  print_number_of_owners(*task_ptr1);
  print_number_of_owners(*task_ptr2);
  print_number_of_owners(*task_ptr3);
  std::cout << "###" << std::endl;
  return 0;
}
