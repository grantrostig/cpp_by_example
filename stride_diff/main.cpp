/* copyright Grant Rostig 2019 all rights reserved.
 * this test program compares the performance of three methods for searching raw memory for
 * 8 bit values.
 * we search for nonzero v4, take the corresponding v123,
 * and search for another matching v123 where v4 is also nonzero.
 */
#include <iostream>
#include <iterator>
#include <bitset>
#include <array>
#include <vector>
#include <valarray>
// #include <variant>
#include <algorithm>
#include <chrono>
#include <memory>
#include <cstring>
#include <cassert>
using namespace std;

// we have a datum (byte), a word holds 4 of these.  words are held in registers and buffers.
using DATUM = unsigned char; // a byte is always 8 bits, an uchar is always a byte.
constexpr unsigned int DATUM_SIZE_BYTES = 	sizeof (DATUM);
constexpr unsigned int DATUM_SIZE_BITS = 	DATUM_SIZE_BYTES * 8;
constexpr unsigned int WORD_DATUM_QTY = 	4; // see struct Word {};
constexpr unsigned int WORD_SIZE_BYTES = 	WORD_DATUM_QTY * DATUM_SIZE_BYTES;
constexpr unsigned int WORD_SIZE_BITS = 	WORD_DATUM_QTY * DATUM_SIZE_BITS;

constexpr unsigned int REGISTER_SIZE_BITS = 512;
constexpr unsigned int REGISTER_SIZE_BYTES= REGISTER_SIZE_BITS/DATUM_SIZE_BITS; // todo: constexpr if to verity no remainder.
constexpr unsigned int REGISTER_CHUNKS = 	REGISTER_SIZE_BITS/WORD_SIZE_BITS;  // todo: constexpr if to verity no remainder.

//constexpr unsigned int BUFFER_WORDS_QTY = 	512*512; 							// number of words in a buffer
constexpr unsigned int BUFFER_WORDS_QTY = 	1024*3; 							// number of words in a buffer
// constexpr unsigned int BUFFER_WORDS_QTY = 	32*32; 							// number of words in a buffer
constexpr unsigned int BUFFER_SIZE_BITS = 	BUFFER_WORDS_QTY*WORD_SIZE_BITS;
constexpr unsigned int BUFFER_SIZE_BYTES = 	BUFFER_WORDS_QTY*WORD_SIZE_BYTES;
constexpr unsigned int BUFFER_REGISTERS_QTY=BUFFER_SIZE_BITS/REGISTER_SIZE_BITS; // todo: constexpr if to verity no remainder.

struct Word { 		// 32 bits at this time.
    DATUM v1 {};
    DATUM v2 {};
    DATUM v3 {};
    DATUM v4 {};
};
using Word_full = uint32_t;  //  WARNING: this does not necessarily comply to Word type and the CONSTANTS above.  // todo: fix this.
using Register =  bitset<REGISTER_SIZE_BITS>;
using Buffer =    bitset<BUFFER_SIZE_BITS>;

int main() {
    chrono::system_clock::time_point    time_start_any {};
    chrono::system_clock::time_point    time_start_diff {};
    chrono::system_clock::time_point    time_end_any {};
    chrono::system_clock::time_point    time_end_diff {};
    chrono::system_clock::duration      time_elapsed_any {};
    chrono::system_clock::duration      time_elapsed_diff {};
    // constexpr chrono::system_clock::duration duration_zero_time = {};

    Word word_data  {0xaa,0xab,0xac,0xad}; // single word
    //Word word_empty {0x00,0x00,0x00,0x00}; // single word
    //Word word_v123  {0xff,0xff,0xff,0x00}; // single word
    //Word word_v4    {0x00,0x00,0x00,0xff}; // single word

    // ========== Example 1: conventional search ==========

    bool is_any_v4_nonzero      { false };  // if all are zero, we are done, looking for any v4 that is not zero.
    bool is_any_v123_same       { false };  // looking for any v1-v3 that is same as the first one (where all have a non zero v4)

    // ===== prepare buffer with test data =====

    std::vector<Word> buffer {BUFFER_WORDS_QTY}; // heap memory, just like in the alternative algorithm/data structure using pointers.  // todo: would valarray be faster?
    std::array<Word, BUFFER_WORDS_QTY> buffer_va; // todo: is this heap memory? probably not?
    // std::valarray<Word> buffer_va {BUFFER_WORDS_QTY}; // heap memory, just like in the alternative algorithm/data structure using pointers.  // todo: would valarray be faster?
    // std::vector<Word> buffer_va {BUFFER_WORDS_QTY}; // heap memory, just like in the alternative algorithm/data structure using pointers.  // todo: would valarray be faster?

    fill( buffer.end()-(buffer.size()/2), buffer.end()-(buffer.size()/2)+1, word_data);  // put one v1234 at half way point to trigger first search
    fill( buffer.end()-2, buffer.end(), word_data);                                      // put a match (2 actually) at end to make second search to to near end

    u_int32_t i = 0; // set same test values
    for ( Word w:buffer) {
        buffer_va[i] = w;
        ++i;
    }

    Word word_v123_first;  // exclude all variable creation from timing section. // todo: does the optimizer move the creation of stack variables out of loop contexts?

    time_start_any = chrono::system_clock::now();
    time_start_diff = chrono::system_clock::now();

    // ===== find non zero Datum.v4 =====

    auto buffer_iterator = std::find_if( buffer.begin(),
                                         buffer.end(),
                                         []( Word word ){ return 0 != word.v4; } );

    time_end_any = chrono::system_clock::now();
    time_start_diff = chrono::system_clock::now();

    if ( buffer_iterator == buffer.end() )
    {
        is_any_v4_nonzero = false;            // all are zero, so we are done
    }
    else
    // ===== search for another matching v123 =====
    {
        is_any_v4_nonzero = true;                  // we have at least one v4 that is nonzero
        word_v123_first.v1 = buffer_iterator->v1;  // v4 is not zero, so store the word
        word_v123_first.v2 = buffer_iterator->v2;
        word_v123_first.v3 = buffer_iterator->v3;
                                                   //word_v123_first.v4 = buffer_iterator->v4;
        ++buffer_iterator;  					   // move to next word
        buffer_iterator = std::find_if( buffer_iterator, buffer.end(),
                                        [ word_v123_first ](Word word){ return
                   word.v1 == word_v123_first.v1
                && word.v2 == word_v123_first.v2
                && word.v3 == word_v123_first.v3
                && 0       != word.v4;
                } );
        if ( buffer_iterator != buffer.end() ) {
            is_any_v123_same = true;
        }
    }

    time_end_diff = chrono::system_clock::now();

    cout << "is_any_v4_nonzero, is_any_v123_same, 2 buffer values: " << is_any_v4_nonzero <<", "<< is_any_v123_same << ", " << buffer[20].v1 << ", " << buffer[20].v1 << ", "<<i<< endl;
    time_elapsed_any  = time_end_any  - time_start_any;
    time_elapsed_diff = time_end_diff - time_start_diff;
    cout << " Duration ns: " << chrono::duration_cast<chrono::nanoseconds >(time_elapsed_any).count() << endl;
    cout << " Duration us: " << chrono::duration_cast<chrono::microseconds>(time_elapsed_any).count() << endl;
    cout << " Duration ms: " << chrono::duration_cast<chrono::milliseconds>(time_elapsed_any).count() << endl;
    cout << " Duration ns: " << chrono::duration_cast<chrono::nanoseconds >(time_elapsed_diff).count() << endl;
    cout << " Duration us: " << chrono::duration_cast<chrono::microseconds>(time_elapsed_diff).count() << endl;
    cout << " Duration ms: " << chrono::duration_cast<chrono::milliseconds>(time_elapsed_diff).count() << endl;

    // ========== Example 1.B: Valarray array search ==========

    i = 0; // set same test values, and renew memory cache.
    for ( Word w:buffer) {
        buffer_va[i] = w;
        ++i;
    }

    is_any_v123_same  = false;
    is_any_v4_nonzero = false;

    time_start_any = chrono::system_clock::now();
    time_start_diff = chrono::system_clock::now();

    // ===== find non zero Datum.v4 =====

    i = 0;
    for ( ; i < buffer_va.size(); ) {
        if (0 != buffer_va[i].v4) {
           is_any_v4_nonzero = true;                  // we have at least one v4 that is nonzero
           break;
        }
        ++i;
    }

    time_end_any = chrono::system_clock::now();
    time_start_diff = chrono::system_clock::now();

    word_v123_first.v1 = buffer_va[i].v1;  // v4 is not zero, so store the word
    word_v123_first.v2 = buffer_va[i].v2;
    word_v123_first.v3 = buffer_va[i].v3;
    //word_v123_first.v4 = buffer_va[i].v4;

    ++i;  // more to next word, which might put it beyond the end, meaning we can't have another equal one.
    if ( is_any_v4_nonzero && i != buffer_va.size()-1 ) {

        // ===== search for another matching v123 =====

        for ( ; i < buffer_va.size(); ++i ) {
             if ( buffer_va[i].v1 == word_v123_first.v1
               && buffer_va[i].v2 == word_v123_first.v2
               && buffer_va[i].v3 == word_v123_first.v3
               && buffer_va[i].v4 != 0 ) {
                    is_any_v123_same = true;
                    break;
             }
        }
    }

    time_end_diff = chrono::system_clock::now();

    cout << "is_any_v4_nonzero, is_any_v123_same, 2 buffer values: " << is_any_v4_nonzero <<", "<< is_any_v123_same << ", " << buffer_va[20].v1 << ", " << buffer_va[20].v1 << ", "<<i<< endl;
    time_elapsed_any = time_end_any - time_start_any;
    time_elapsed_diff = time_end_diff - time_start_diff;
    cout << " Duration ns: " << chrono::duration_cast<chrono::nanoseconds >(time_elapsed_any).count() << endl;
    cout << " Duration us: " << chrono::duration_cast<chrono::microseconds>(time_elapsed_any).count() << endl;
    cout << " Duration ms: " << chrono::duration_cast<chrono::milliseconds>(time_elapsed_any).count() << endl;
    cout << " Duration ns: " << chrono::duration_cast<chrono::nanoseconds >(time_elapsed_diff).count() << endl;
    cout << " Duration us: " << chrono::duration_cast<chrono::microseconds>(time_elapsed_diff).count() << endl;
    cout << " Duration ms: " << chrono::duration_cast<chrono::milliseconds>(time_elapsed_diff).count() << endl;

    // ========== Example 2: bitmask search ==========

    // ===== prepare bitmasks and data =====
    string word_mask_v123_s      {"11111111111111111111111100000000"};
    string word_mask_v4_s        {"00000000000000000000000011111111"};
    string register_mask_v123_s;
    string register_mask_v4_s;
    register_mask_v123_s.reserve( REGISTER_SIZE_BITS );
    register_mask_v4_s.reserve(   REGISTER_SIZE_BITS );
    for (uint32_t var = 0; var <  REGISTER_CHUNKS; ++var) {  // build initializier string for register masks.
        register_mask_v4_s +=    word_mask_v4_s;
        register_mask_v123_s +=  word_mask_v123_s;
    };
    bitset< REGISTER_SIZE_BITS > register_mask_v4  {register_mask_v4_s};
    assert ( REGISTER_SIZE_BITS == register_mask_v4_s.size() );
    assert ( REGISTER_SIZE_BITS == register_mask_v4.size() );
//    bitset<REGISTER_SIZE_BITS> register_mask_v123 {bits_register_v123_s};
//    bitset<REGISTER_SIZE_BITS> register_mask_ones {};
//    register_mask_ones.set(); // all ones
//    bitset<REGISTER_SIZE_BITS> register_mask_zeros {};
//    register_mask_zeros.reset(); // all zeros

    unsigned char *            register_mask_v123_first_cs [REGISTER_SIZE_BYTES+1] {};  // specific value will be set later.
    bitset<REGISTER_SIZE_BITS> register_mask_v123_first  {};
    bitset<REGISTER_SIZE_BITS> register_mask_tmp  {};



    // ===== prepare buffer with test data =====

    void * ptr = calloc( BUFFER_SIZE_BYTES, 1 ); 			// init a word buffer to all 0.
    if (!ptr) { throw; };  								  	// todo: handle this better.
    Word *     ptr_word =     static_cast<Word *>(ptr);
    Register * ptr_register = static_cast<Register *>(ptr);
    for (uint32_t var = 0; var < BUFFER_WORDS_QTY; ++var) { // an extra int is used, just for clarity.
        if (( BUFFER_WORDS_QTY/2 == var ) || ( BUFFER_WORDS_QTY - 3 < var )) {
            memcpy( ptr_word, &word_data, WORD_SIZE_BITS);  	// similar data criteria as above example // todo: what likely errors to check for from memcpy and slow it down? none?
        }
        ++ptr_word;
    }

    bitset<REGISTER_SIZE_BITS> register_result_v4 {};
    unsigned int buffer_index_v4 {};
    is_any_v4_nonzero = false;
    is_any_v123_same =  false;

    // ===== find nonzero Datum.v4 =====
    time_start_any = chrono::system_clock::now();
    for (uint32_t var = 0; var < BUFFER_REGISTERS_QTY; ++var) { // var must be [0..(var-1)] when in loop, it is being used.
        register_result_v4 = *ptr_register & register_mask_v4;
        if (register_result_v4.any() ) {                         // did we find any non-zero v4 in any of the words of the register.
            is_any_v4_nonzero = true;                          // all are zero, so we are done = true;
           // buffer_index_v4 = var;
            break;
        }
        ++ptr_register;
    }

//    time_start_any = chrono::system_clock::now(); // todo:  get the types correct cppmsg
//    for (Register * ptr_ = ptr; ptr < ((char *)ptr)*(8*(BUFFER_REGISTERS_QTY-1)+1); ++ptr_) { // var must be [0..(var-1)] when in loop, it is being used.
//        register_result_v4 = *ptr_ & register_mask_v4;
//        if (register_result_v4.any() ) {                         // did we find any non-zero v4 in any of the words of the register.
//            is_any_v4_nonzero = true;                          // all are zero, so we are done = true;
//           // buffer_index_v4 = var;
//            break;
//        }
//        ++ptr_;
//    }

    time_end_any = chrono::system_clock::now();
    time_start_diff = chrono::system_clock::now();

// ========== ALL BELOW IS NOT COMPLETED! ========== since the above examples are much faster and therefore this experiment doesn't appear to be a productive approach or at least is not yet successfull. ==========

    if ( false /* is_any_v4_nonzero */ ) {

        // ========== search for another matching v123 ==========

        // ===== look for first bit of first v4 that is != 0 =====
        auto register_bit_index_v4 = register_result_v4._Find_first();  // WARNING: using SGI_Extension to the C++ STL. maybe GNU specific  // todo:  works on all 3 platforms?

        // ========== Get the v123 value for the word we found ==========
        // ===== Translate the bit index to a word index =====
        auto   register_word_index_v4 =
             ( register_bit_index_v4 + 1) / WORD_SIZE_BITS ;  // todo: could I use ceil() or similar to simplify?
        if ( ( register_bit_index_v4 + 1) % WORD_SIZE_BITS )
        {
             ++register_word_index_v4;
        }

        // ===== Needed?? Convert the word index to the register bit index =====
        // auto register_word_bit_index_v4 = register_word_index_v4 * WORD_SIZE_BITS;

        // =====
        auto buffer_register_word_offset = buffer_index_v4 * BUFFER_WORDS_QTY;

        // ===== Prepare a mask for the v123 value =====
        // todo:
        Word v1234 = *( ptr_word + (buffer_register_word_offset + register_word_index_v4) );
        v1234.v4 = 0;                                                   // v4 could be any nonzero value, we only consider v123 for subsequent difference

        // ===== Logical Extract the v123 value =====
        bitset<REGISTER_SIZE_BITS> bit_op_v123_result_register {};
        // todo: do the AND

        // ===== Copy the v123 value to a Word =====
//        bitset<WORD_SIZE_BITS> word_mask
//        {
//            static_cast<unsigned long long>(
//                        (Word_full)bit_op_v123_result_register[ v4_register_word_bit_start_index ]
//                        )
//        };
        // ===== Make a mask for the balance of the register and one for entire registers (may need it) =====
        // ===== Loop

        // ===== prepare specific mask =====
        //    for (unsigned int var = 0; var < REGISTER_CHUNKS; ++var) {  // build initializer for register mask.
        //        if (v4_word_index != var) bitmask_24_first_s+=bits_24_first_s;
        //        else {
        //        bitmask_24_first_s+=bits_24_first_s;
        //        bitmask_24_first_s+=bits_24_first_s;
        //        }
        //    };

    }
    time_end_diff = chrono::system_clock::now();

    free( ptr );

    cout << "is_any_v4_nonzero, is_any_v123_same, 2 buffer values: " << is_any_v4_nonzero <<", "<< is_any_v123_same << ", " << buffer[20].v1 << ", " << buffer[20].v1 << ", "<<i<< endl;
    time_elapsed_any = time_end_any - time_start_any;
    time_elapsed_diff = time_end_diff - time_start_diff;
    cout << " Duration ns: " << chrono::duration_cast<chrono::nanoseconds >(time_elapsed_any).count() << endl;
    cout << " Duration us: " << chrono::duration_cast<chrono::microseconds>(time_elapsed_any).count() << endl;
    cout << " Duration ms: " << chrono::duration_cast<chrono::milliseconds>(time_elapsed_any).count() << endl;
    cout << " Duration ns: " << chrono::duration_cast<chrono::nanoseconds >(time_elapsed_diff).count() << endl;
    cout << " Duration us: " << chrono::duration_cast<chrono::microseconds>(time_elapsed_diff).count() << endl;
    cout << " Duration ms: " << chrono::duration_cast<chrono::milliseconds>(time_elapsed_diff).count() << endl;

    cout << "###" << endl;
    return 0;
}
