#!/usr/bin/perl
#!/usr/bin/env perl
# Copyright 2024 Grant Rostig, License: Boost 1.0 # DO NOT USE IN PRODUCTION, we are just playing around.
use strict; use warnings;

print 'hello world';
my $kkkk = "myk";

while ( <> ) {
    chomp;
    print $_ . ${kkkk} . "\n" ;                 # " is needed on \n
};


# while ( True ne False ) {
while ( 1.0 ne 2.0 ) {
    print "hello world";
};

