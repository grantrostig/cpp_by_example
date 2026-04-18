#include <cassert>
#include <iostream>
#include <ostream>
#include <set>
#include <vector>
#include <algorithm>
#include <print>
#include <format>
#include <ranges>
#include <iterator>
#include <string>
#include <numeric>
using std::cout; using std::endl;

//#define CHATGPT
#ifdef CHATGPT
// Propositional Logic Utilities
bool implies(bool p, bool q) {
    return (!p) || q;
}
bool biconditional(bool p, bool q) {
    return p == q;
}
// Predicate Examples
bool is_even(int x) {
    return x % 2 == 0;
}
bool is_positive(int x) {
    return x > 0;
}
// Quantifier Implementations
template<typename Range, typename Pred>
bool forall(const Range& r, Pred p) {
    return std::ranges::all_of(r, p);
}
template<typename Range, typename Pred>
bool exists(const Range& r, Pred p) {
    return std::ranges::any_of(r, p);
}
int main() {
    // 1. Propositional Logic + Equivalences
    bool p = true;
    bool q = false;
    cout << "Propositional Logic:" << endl;
    bool lhs1 = !(p && q);
    bool rhs1 = (!p || !q);
    assert(lhs1 == rhs1);
    cout << "De Morgan !(p && q) == (!p || !q) holds: " << lhs1 << endl;
    bool lhs2 = !(p || q);
    bool rhs2 = (!p && !q);
    assert(lhs2 == rhs2);
    cout << "De Morgan !(p || q) == (!p && !q) holds: " << lhs2 << endl;

           // Implication equivalence: (p -> q) == (!p || q)
    bool impl = implies(p, q);
    bool impl_equiv = (!p || q);
    assert(impl == impl_equiv);
    cout << "Implication equivalence holds: " << impl << endl;

           // Biconditional: (p <-> q)
    bool bic = biconditional(p, q);
    cout << "Biconditional (p <-> q): " << bic << endl;

           // 2. Set Theory

    cout << "\nSet Operations:" << endl;
    std::set<int> A = {1, 2, 3};
    std::set<int> B = {3, 4, 5};
           // Union
    std::set<int> union_set;
    std::ranges::set_union(A, B, std::inserter(union_set, union_set.begin()));

    cout << "Union A ∪ B: ";
    for (int x : union_set) cout << x << " ";
    cout << endl;

    std::set<int> intersection_set;
    std::ranges::set_intersection(A, B, std::inserter(intersection_set, intersection_set.begin()));
    cout << "Intersection A ∩ B: ";
    for (int x : intersection_set) cout << x << " ";
    cout << endl;
    assert(intersection_set == std::set<int>{3});

           // Difference A - B
    std::set<int> difference_set;
    std::ranges::set_difference(A, B, std::inserter(difference_set, difference_set.begin()));
    cout << "Difference A - B: ";
    for (int x : difference_set) cout << x << " ";
    cout << endl;
    auto answer=std::set<int>{1,2}; //TODO??: why does this fail with strange error? auto answer{std::set<int>{1,2}};
    assert(difference_set == answer);

           // 3. Predicates
    cout << "\nPredicates:" << endl;
    int value = 4;
    cout << value << " is even: " << is_even(value) << endl;
    cout << value << " is positive: " << is_positive(value) << endl;
    assert(is_even(4));
    assert(!is_even(5));

           // 4. Quantifiers
    cout << "\nQuantifiers:" << endl;
    std::vector<int> data = {2, 4, 6, 8};
    // ∀x ∈ data: is_even(x)
    bool all_even = forall(data, is_even);
    cout << "All elements are even: " << all_even << endl;
    assert(all_even);

    cout << " ∃x ∈ data: x > 5" << endl;
    bool exists_gt5 = exists(data, [](int x){ return x > 5; });
    cout << "Exists element > 5: " << exists_gt5 << endl;
    assert(exists_gt5);

    // cout < " ∀x: P(x) -> Q(x) //Example: if x is even, then x % 2 == 0 (tautological sanity check)" << endl;

    // cout < " for_all_char x: P(x) -> Q(x) Example: if x is even, then x percent 2 == 0 (tautological sanity check) " << endl;

    std::vector<int> mixed = {2, 4, 5, 6, 8};  // TODO?: why does a odd number pass?
    bool implication_over_set = forall(mixed, [](int x){ return implies(is_even(x), x % 2 == 0);});
    // cout << "Predicate implication over set holds: " << implication_over_set << endl;
    assert(implication_over_set);

    // cout <<" 5. Counterexample (negation of ∀)" <<endl;

    cout <<" 5. Counterexample (negation of for_all_char)" <<endl;
    bool all_even_mixed = forall(mixed, is_even);
    cout << "All elements in mixed are even: " << all_even_mixed << endl;
    assert(!all_even_mixed);
    bool exists_odd = exists(mixed, [](int x){ return !is_even(x); });
    cout << "Exists odd element in mixed: " << exists_odd << endl;
    assert(exists_odd);

    cout << "\nAll assertions passed." << endl;
    return 0;
}
#endif

// #define GROK
#ifdef GROK
int main() {
    std::cout << "C++23 Program Illustrating Discrete Mathematics Concepts\n";
    std::cout << "1. Sets and Basic Set Operations\n";
    std::set<int> A{1, 2, 3};
    std::set<int> B{2, 3, 4};

           // Union
    std::set<int> unionAB;
    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::inserter(unionAB, unionAB.begin()));
    std::cout << "A = {1,2,3}, B = {2,3,4}\n";
    std::cout << "A ∪ B = ";
    for (int x : unionAB) std::cout << x << ' ';
    std::cout << '\n';

           // Intersection
    std::set<int> interAB;
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::inserter(interAB, interAB.begin()));
    std::cout << "A ∩ B = ";
    for (int x : interAB) std::cout << x << ' ';
    std::cout << '\n';

           // Set identities (commutativity and associativity verified by equality)
    std::set<int> unionBA;
    std::set_union(B.begin(), B.end(), A.begin(), A.end(), std::inserter(unionBA, unionBA.begin()));
    assert(unionAB == unionBA);  // Commutativity of union
    std::cout << "Verified: A ∪ B == B ∪ A (commutativity)\n\n";

    std::cout << "2. Propositional Logic and Equivalences\n";
    bool p = true;
    bool q = false;
           // Negation, conjunction, disjunction
    bool not_p_and_q   = !(p && q);
    bool not_p_or_not_q = !p || !q;

    std::cout << "p = true, q = false\n";
    std::cout << "De Morgan's law: ¬(p ∧ q) == ¬p ∨ ¬q → "
              << (not_p_and_q == not_p_or_not_q) << '\n';
    assert(not_p_and_q == not_p_or_not_q);

           // Commutativity of disjunction
    assert((p || q) == (q || p));
    std::cout << "Verified: (p ∨ q) == (q ∨ p) (commutativity)\n";

           // Distributivity: p ∧ (q ∨ r) == (p ∧ q) ∨ (p ∧ r)
    bool r = true;
    bool left  = p && (q || r);
    bool right = (p && q) || (p && r);
    assert(left == right);
    std::cout << "Verified: p ∧ (q ∨ r) == (p ∧ q) ∨ (p ∧ r) (distributivity)\n\n";

    std::cout << "3. Predicates (Boolean-valued functions)\n";
    auto is_even = [](int x) -> bool { return x % 2 == 0; };
    auto is_positive = [](int x) -> bool { return x > 0; };
    std::cout << "Predicate is_even(4)  = " << is_even(4) << '\n';
    std::cout << "Predicate is_even(5)  = " << is_even(5) << '\n';
    std::cout << "Predicate is_positive(0) = " << is_positive(0) << '\n';
    assert(is_even(4));
    assert(!is_even(5));
    assert(!is_positive(0));
    std::cout << "Predicates verified via assertions.\n\n";

    std::cout << "4. Quantifiers over Finite Domains\n";
    std::vector<int> numbers{2, 4, 6, 8, 10};
           // Universal quantifier ∀x ∈ numbers, P(x)
    bool all_even = std::all_of(numbers.begin(), numbers.end(), is_even);
    std::cout << "∀x ∈ {2,4,6,8,10} (is_even(x)) → " << all_even << '\n';
    assert(all_even);

           // Existential quantifier ∃x ∈ numbers, P(x)
    bool exists_even = std::any_of(numbers.begin(), numbers.end(), is_even);
    std::cout << "∃x ∈ {2,4,6,8,10} (is_even(x)) → " << exists_even << '\n';
    assert(exists_even);

           // Counter-example for universal quantifier
    std::vector<int> mixed{1, 2, 3, 4};
    bool all_even_mixed = std::all_of(mixed.begin(), mixed.end(), is_even);
    std::cout << "∀x ∈ {1,2,3,4} (is_even(x)) → " << all_even_mixed << '\n';
    assert(!all_even_mixed);

           // Combined predicate with both quantifiers
    auto is_even_and_positive = [&](int x) { return is_even(x) && is_positive(x); };
    bool exists_even_positive = std::any_of(mixed.begin(), mixed.end(), is_even_and_positive);
    std::cout << "∃x ∈ {1,2,3,4} (even(x) ∧ positive(x)) → " << exists_even_positive << '\n';
    assert(exists_even_positive);

    std::cout << "###\n";
    return 0;
}
#endif

//#define META_AI
#ifdef META_AI
bool is_even(int n) { return n % 2 == 0; }

int main() {
    // --- Propositional Logic and Equivalences ---
    std::cout << "--- 1. Propositional Logic and Equivalences ---\n";
    bool p = true;
    bool q = false;
           // Basic operations
    std::cout << "p = true, q = false\n";
    std::cout << "p AND q: " << (p && q) << "\n"; // Conjunction
    std::cout << "p OR q: " << (p || q) << "\n";  // Disjunction
    std::cout << "NOT p: " << (!p) << "\n\n";      // Negation
           // De Morgan's Law: !(p && q) <=> !p || !q
    std::cout << "Illustrating De Morgan's Law: !(p && q) <=> !p || !q\n";
    bool de_morgan_lhs = !(p && q);
    bool de_morgan_rhs = !p || !q;
    std::cout << "!(p && q) is " << std::boolalpha << de_morgan_lhs << "\n";
    std::cout << "!p || !q is " << std::boolalpha << de_morgan_rhs << "\n";
    assert(de_morgan_lhs == de_morgan_rhs);
    std::cout << "Assertion passed: The equivalence holds.\n\n";
           // --- Sets ---
    std::cout << "--- 2. Sets ---\n";
    std::set<int> A = {1, 2, 3, 4}; std::cout << "Set A = {1, 2, 3, 4}\n";
    std::set<int> B = {3, 4, 5, 6}; std::cout << "Set B = {3, 4, 5, 6}\n\n";
           // Union
    std::set<int> a_union_b;
    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::inserter(a_union_b, a_union_b.begin()));
    std::cout << "Union (A U B): ";
    for (int x : a_union_b) std::cout << x << " ";
    std::cout << ".\n";
    assert(a_union_b == std::set<int>({1, 2, 3, 4, 5, 6}));
           // Intersection
    std::set<int> a_intersect_b;
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::inserter(a_intersect_b, a_intersect_b.begin()));
    std::cout << "Intersection (A n B): ";
    for (int x : a_intersect_b) std::cout << x << " ";
    std::cout << "\n";
    assert(a_intersect_b == std::set<int>({3, 4}));
           // Difference
    std::set<int> a_diff_b;
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::inserter(a_diff_b, a_diff_b.begin()));
    std::cout << "Difference (A - B): ";
    for (int x : a_diff_b) std::cout << x << " ";
    std::cout << "\n\n";
    assert(a_diff_b == std::set<int>({1, 2}));

    std::cout << "--- 3. Predicates ---\n";
    std::cout << "A predicate is a function that returns a boolean.\n";
    std::cout << "Using predicate 'is_even(n)'\n";
    std::cout << "is_even(4): " << std::boolalpha << is_even(4) << "\n";
    std::cout << "is_even(7): " << std::boolalpha << is_even(7) << "\n";
    assert(is_even(4) == true);
    assert(is_even(7) == false);
    std::cout << "Assertions passed.\n\n";

           // --- Quantifiers ---
    std::cout << "--- 4. Quantifiers ---\n";
    std::vector<int> numbers = {2, 4, 6, 8, 10}; std::cout << "Set S1 = {2, 4, 6, 8, 10}\n";
    std::vector<int> mixed_numbers = {1, 2, 3, 4, 5}; std::cout << "Set S2 = {1, 2, 3, 4, 5}\n\n";
           // Universal Quantifier (For All - ∀)
    std::cout << "Universal Quantifier (For All - \u2200): Are all numbers in S1 even?\n";
    bool all_are_even = std::all_of(numbers.begin(), numbers.end(), is_even);
    std::cout << "Result: " << std::boolalpha << all_are_even << "\n";
    assert(all_are_even);
    std::cout << "Assertion passed.\n\n";
           // Existential Quantifier (There Exists - ∃)
    std::cout << "Existential Quantifier (There Exists - \u2203): Is there at least one even number in S2?\n";
    bool any_is_even = std::any_of(mixed_numbers.begin(), mixed_numbers.end(), is_even);
    std::cout << "Result: " << std::boolalpha << any_is_even << "\n";
    assert(any_is_even);
    std::cout << "Assertion passed.\n\n";
           // Negation of Existential Quantifier (None of - ∄)
    std::cout << "Negation (None of - \u2204): Are there no numbers greater than 5 in S2?\n";
    bool none_are_greater_than_5 = std::none_of(mixed_numbers.begin(), mixed_numbers.end(), [](int n){ return n > 5; });
    std::cout << "Result: " << std::boolalpha << none_are_greater_than_5 << "\n";
    assert(none_are_greater_than_5);
    std::cout << "Assertion passed.\n\n";

    return 0;
}
#endif

#define GEMINI
// had many errors, I fixed them 2x.
#ifdef GEMINI
int main() {
    // 1. PROPOSITIONAL LOGIC & EQUIVALENCES
    // Illustrating p -> q equivalent to!p || q [1, 22]
    auto implication   =[](bool p, bool q) { return !p || q; };
    auto biconditional =[](bool p, bool q) { return p == q; };

    std::println("--- Propositional Equivalences ---");
    // Verify De Morgan's Laws:!(p && q) == (!p ||!q) [6, 26]
    for (bool p : {true, false}) {
        for (bool q : {true, false}) {
            bool left  =!(p && q);
            bool right =!p || !q;
            assert(left == right);

            // Verify Implication Identity: (p -> q) == (!p || q) [1, 3]
            assert(implication(p, q) == (!p || q));
            std::println("p: {:>5}, q: {:>5} |!(p && q) == (!p ||!q): {:>5}", p, q, (left == right));
        }
    }

    // 2. SET THEORY
    // C++23 ranges set operations on sorted ranges [27, 20, 28]
    std::set<int> A = {1, 2, 3, 4, 5};
    std::set<int> B = {4, 5, 6, 7, 8};

    // Materialize results using std::ranges::to [13, 14, 29]
    std::set<int> set_union;
    std::ranges::set_union(A, B,std::inserter(set_union, set_union.begin()) );

    std::set<int> set_intersection;
    std::ranges::set_intersection(A, B,std::inserter(set_union, set_union.begin()) );

    std::set<int> set_difference;
    std::ranges::set_difference(A, B, std::inserter(set_difference, set_difference.begin()) );

    std::println("\n--- Set Operations ---");
    std::println("Set A: {}", A); // C++23 range formatting [24, 30]
    std::println("Set B: {}", B);
    std::println("A \u222A B (Union):        {}", set_union);
    std::println("A \u2229 B (Intersection): {}", set_intersection);
    std::println("A \\ B (Difference):   {}", set_difference);

    // 3. PREDICATES & QUANTIFIERS
    // Predicates as lambdas [17, 31, 23]
    auto is_even  =[](int n) { return n % 2 == 0; };
    auto is_prime =[](int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false;
        return true;
    };

    std::vector numbers = {2, 3, 5, 7, 11};

    // Universal Quantification (\u2200): all_of [16, 32, 33]
    bool all_prime = std::ranges::all_of(numbers, is_prime);
    // Existential Quantification (\u2203): any_of [16, 33]
    bool some_even = std::ranges::any_of(numbers, is_even);

    std::println("\n--- Predicates & Quantifiers ---");
    std::println("Numbers: {}", numbers);
    std::println("\u2200 x in Numbers, is_prime(x): {:>5}", all_prime);
    std::println("\u2203 x in Numbers, is_even(x):  {:>5}", some_even);

    assert(all_prime == true);
    assert(some_even == true);

    // 4. RANGE FOLDING (C++23)
    // Using fold_left to compute a logical conjunction over a range [34]
    std::vector<bool> truth_values = {true, true, false, true};
    bool logical_and_fold = std::ranges::fold_left(truth_values, true, std::logical_and<>{});

    std::println("\n--- Range Folding ---");
    std::println("Folding AND over {}: {}", truth_values, logical_and_fold);
    assert(logical_and_fold == false);

    std::println("\nAll assertions passed. Discrete logic verification complete.");
    return 0;
}


#endif
