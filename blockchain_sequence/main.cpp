#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <limits>

/*

Blockchains maintain consensus over the global ordering of a set of independent blocks.
Each block must link into the chain at only one point however, at any given point there
may be multiple blocks that share the same previous block.  It is therefore the problem
of consensus to pick one fork over all others as the true path of forward.

In this problem, you are asked to find the ordered sequence of blocks from the beginning of a
blockchain (its genesis) to a block identified by a certain globally unique ID (the head ID)
amongst a unordered collection of all the blocks that have been created.

Input:
3 //< desired HEAD ID
1 0
3 2
2 1

Expected Output:
RESULTS:
1 0
2 1
3 2

TestCase #0: Wrong Answer [View Sample TestCase]
Output:
RESULTS:
3 2
1 0

Expected Output:
RESULTS:
1 0
2 1
3 2

TestCase #1: Wrong Answer
TestCase #2: Wrong Answer
TestCase #3: Success
TestCase #4: Wrong Answer
TestCase #5: Success

 */

class block {
public:
   uint32_t  id;
   uint32_t  previous;

   block( uint32_t id, uint32_t previous )
   :id(id)
   ,previous(previous)
   {}
};

/**
 * This method returns the VALID CHAIN of blocks present in the given blocks that ends in a block with the given id
 *
 * A VALID CHAIN is an ordered list of blocks where:
 *   1) the first entry in the list has a `previous` member === 0
 *   2) each subsequent entry in the list has a `previous` member === to the previous entry's `id` member
 *
 * The head of a VALID CHAIN is the last entry in the implied ordered list of blocks.
 *
 * @pre known_blocks is guaranteed to have at most one block per `id` value
 * @param head_id - the ID of the desired HEAD block
 * @param known_blocks - an unordered vector of all known blocks
 * @return - the VALID CHAIN composed of blocks from known_blocks which terminates at the desired head block if one exists
 *           OR an empty vector if no such chain exists in known_blocks
 */
std::vector<block> find_chain_by_id(uint32_t head_id, const std::vector<block>& known_blocks) // not ordered, unique id.
{
    std::vector<block>  my_vec {};
    uint32_t            current_iteration {};
    uint32_t            head_index {};

    size_t max_iterations = known_blocks.size();

    // get index of head

    auto it = std::find_if(known_blocks.begin(), known_blocks.end(), [&head_id] (block b) { return (b.id == head_id); } );

    if ( known_blocks.end() == it ) return std::vector<block> {};
    head_index = it->previous;

    if ( known_blocks[head_index].id == 0 ) return std::vector<block> {};

    do {
        my_vec.push_back( known_blocks[current_iteration] );
        if ( ++current_iteration > max_iterations ) return std::vector<block> {};
        current_iteration = known_blocks[current_iteration].previous;
    } while ( !(my_vec[current_iteration].previous == 0) );

    reverse( my_vec.begin(), my_vec.end() );

    // fix up the previous pointers

    return my_vec;
}

namespace {
    template<typename T>
    T read_line(std::istream&);

    template<typename T>
    void print_line(const T&, std::ostream& out);

    template<>
    block read_line<block>(std::istream& in) {
        uint32_t id, previous;
        in >> id >> previous;
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return {id, previous};
    }

    template<>
    void print_line(const block& b, std::ostream& out) {
        out << b.id << " " << b.previous << std::endl;
    }
}

int main() {
   std::ofstream fout(getenv("OUTPUT_PATH"));

   uint32_t head_id = 1;
   std::cin >> head_id;
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   std::vector<block> known_blocks;
   while (std::cin) {
      known_blocks.emplace_back(read_line<block>(std::cin));
   }

   auto result = find_chain_by_id(head_id, known_blocks);

   fout << "RESULTS:" << std::endl;
   for (const auto& b: result) {
      print_line(b, fout);
   }

   return 0;
}
