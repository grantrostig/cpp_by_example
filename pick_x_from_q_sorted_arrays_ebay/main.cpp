#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <ranges>
#include <utility>
#include <vector>

/*
    Solving this question:
        https://stackoverflowteams.com/c/cppmsg/questions/28

        This is underspecified in the case where the total number
        of integers supplied is less than "k."
        We could throw in this case, but instead we'll specify that
        the return vector will return all the integers.

        The original calls for passing an array of arrays. This is
        problematic in that we don't know the size of passed arrays,
        so we cheat and pass a vector of vectors.

    */


namespace Smallest
{
// Keep track of vector within the vector of vectors using iterator pairs,
// where the first and second elements of the pair and the begin and end
// iterators. This means that a vector is empty if/when the first and last
// elements are equal. We need to check this in a few places so we use these
// handy functions.
namespace
{
    // equal_pair is a good name for the implemention...
template <typename P>
bool equal_pair_elements(P pair) {return pair.first == pair.second;}

// but the caller just wants to know if the vector is empty.
template <typename V>
bool empty_vec(V vec) {return equal_pair_elements(vec);}
}

// I like to always create aliases for any type I use.
using Source = std::vector<std::vector<int>>;

// Return the k smallest integers within the vector of sorted vectors.
// If the total number of integers is less than k, we just return all the integers.
std::vector<int> smallest(int k, Source const& src) {
    using Result = std::vector<int>;
    Result result;
    Result rresult;

    /* Our strategy is to create a container that holds "pointers" to the smallest
    // value in each vector in the source that has not yet been used (put in the
    // result).

    // We then sort these "pointer" by the smallest (first) value in each vector.

    // (Counterintuitively, we'll do this with a descending sort. Why? As we "take"
    // values from the vectors, we'll eventually take the last value from a vector.
    // At that point, we'll want to "pop" that vector from the container. If we
    // are using a vector for the container "pop_front" is expensive (linear), but
    // "pop_back" is constant time.)

    // This means that the smallest value in the source is the first value of the
    // last "pointer" in the container.

    // We'll "take" this value (put it in the result vector) in a loop. Every time
    // we "take" a value, we need to maintain the invariant that the smallest remaining
    // value in the source is the first item of the last pointer in the container.

    // So when we "take" a value we need to increment the last pointer so it points
    // to the next value in its vector. That value will be the smallest unused value
    // in this vector, but there may be other vectors that have a smaller value.

    // At this point, we could resort the container by the value pointed to by each
    // pointer, but note that every element is already in sorted order except (possibly)
    // the first.

    // So rather than completely re-sorting, we can just find new correct position
    // for the last "pointer" and re-position that one element.

    // Here we have a decision to make. If we use vector, we can use lower_bound (a
    // log operation) to find the new correct position, but then we need to do a linear
    // operator to put the "pointer" in that position.

    // If we were to use a list, then we would have to use a linear operation to find
    // the correct position, but re-positioning would be constant time.

    // I'm going to use vector, because I love lower_bound.

    // The "pointers" need to know when the pointed to vector is exhausted, so we
    // make the "pointers" a pair of (const) iterators which are (initially) the
    // begin and end of each of the vectors in the source.

    // Every time we "use" a value, we increment the first of the pair of iterators.
    // We know when a vector is exhausted when the two iterators are equal.*/

    using RSources = std::vector<
                        std::ranges::ref_view< std::vector<int> const>
        >;

    RSources rpositions;
    std::for_each(begin(src), end(src), [&](auto const&v)
                  {
                      rpositions.push_back(std::views::all(v));
                  });

    // Let's remove any empty vectors.
    rpositions.erase(remove_if(begin(rpositions), end(rpositions), [](auto const&vr)
                             {
                                 return empty(vr);
                             }), end(rpositions));

    // Descending sort. Empty vectors to the front (so they won't be used).
    auto rdescending_comp{[](auto l, auto r){
        if (empty(l))
        {
            return true;
        }
        else if (empty(r))
        {
            return false;
        }
        else
        {
            return *(begin(l)) > *(begin(r));
        };
    }};
    std::ranges::sort(begin(rpositions), end(rpositions), rdescending_comp);
    while (ssize(rresult) <= k) {
        // If we have no vectors...
        if (empty(rpositions)) {
            // We've run out of integers, so we return what we have.
            k = ssize(rresult);
        }

        auto last_pos { end( rpositions) - 1}; // The last source vector.

        assert(not empty(*last_pos));   // If we emptied the last
            // vector the last time
            // though the loop we
            // should have removed it.
        // Take the smallest unused value.
        rresult.push_back(*begin(*last_pos));
        if (ssize(rresult) == k) {
            // We could just fall out of the loop, but why wait?
            return rresult;
        }
        // Update to point to the next largest.
        auto i= std::views::drop( *last_pos, 1).begin();

        //*last_pos = i;
        //(std::ranges::ref_view< const std::vector<int> >)  i ;
        //*last_pos = std::ranges::ref_view< const std::vector<int> > ( i );
        //*last_pos = std::ranges::ref_view< const std::vector<int> > ( std::views::drop( *last_pos, 1) );

        // If that was the last one in this source vector, then
        // remove the "pointer" to it.

        if (empty(*last_pos)) {
            rpositions.pop_back();
        }
        else if (ssize(rpositions) != 1) // This is not the last remaining vector. {
            auto penultimate_pos{last_pos - 1};
            assert(not empty(*penultimate_pos));    // We should have removed all
                // empty vectors.
            // If the smallest value in this vector is smaller than the smallest
            // value in the remaining vectors, then we are sorted correctly.
            if ((*begin(*last_pos)) > (*begin(*penultimate_pos)))
            {
                // We are not sorted correctly we need to find our correct
                // position.
                auto correct_pos{std::lower_bound(  begin(rpositions),
                                                  end(rpositions),
                                                  *last_pos,
                                                  rdescending_comp)};
                rpositions.insert(correct_pos, *last_pos);
                rpositions.pop_back();
            }
        }
    }

    using VectorPair = std::pair<   typename std::vector<int>::const_iterator,
                                     typename std::vector<int>::const_iterator>;
    using Sources = std::vector<VectorPair>;
    Sources sources;
    std::for_each(begin(src), end(src), [&](auto const&v) {
                      sources.push_back({begin(v), end(v)});
                  });
    // Let's remove any empty vectors.
    sources.erase(remove_if(begin(sources), end(sources), [](auto const&vp) {
                                return vp.first == vp.second;
                            }), end(sources));

    // Descending sort. Empty vectors to the front (so they won't be used).
    auto descending_comp{[](auto l, auto r){
        if (empty_vec(l))
        {
            return true;
        }
        else if (empty_vec(r))
        {
            return false;
        }
        else
        {
            return *(l.first) > *(r.first);
        };
    }};
    std::sort(begin(sources), end(sources), descending_comp);

    while (ssize(result) <= k) {
        // If we have no vectors...
        if (empty(sources)) {
            // We've run out of integers, so we return what we have.
            k = ssize(result);
        }
        auto last_pos{end(sources) - 1}; // The last source vector.
        assert(not empty_vec(*last_pos));   // If we emptied the last
            // vector the last time
            // though the loop we
            // should have removed it.
        // Take the smallest unused value.
        result.push_back(*(last_pos->first));
        if (ssize(result) == k) {
            // We could just fall out of the loop, but why wait?
            return result;
        }
        // Update to point to the next largest.
        ++(last_pos->first);
        // If that was the last one in this source vector, then
        // remove the "pointer" to it.
        if (empty_vec(*last_pos)) {
            sources.pop_back();
        }
        else if (ssize(sources) != 1) // This is not the last remaining vector.
        {
            auto penultimate_pos{last_pos - 1};
            assert(not empty_vec(*penultimate_pos));    // We should have removed all
                // empty vectors.
            // If the smallest value in this vector is smaller than the smallest
            // value in the remaining vectors, then we are sorted correctly.
            if (*(last_pos->first) > *(penultimate_pos->first))
            {
                // We are not sorted correctly we need to find our correct
                // position.
                auto correct_pos{std::lower_bound(  begin(sources),
                                                  end(sources),
                                                  *last_pos,
                                                  descending_comp)};
                sources.insert(correct_pos, *last_pos);
                sources.pop_back();
            }
        }
    }

    return result;
}
}

int main()
{
    Smallest::Source src{   {10, 20, 30, 40, 50, 60, 70, 80},
                         {15, 25, 35, 45, 55, 65, 75},
                         {-2, 3, 11, 15, 53, 55, 90}};
    auto res{Smallest::smallest(7, src)};
    auto expected = {-2, 3, 10, 11, 15, 15, 20};
    assert(std::ranges::equal(res, expected));
    std::copy(begin(res), end(res), std::ostream_iterator<int>(std::cout, " "));

}
