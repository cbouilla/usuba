#!/usr/bin/perl

use strict;
use warnings;
use v5.14;

use Cwd;
use File::Path qw( remove_tree );
use File::Copy;
use FindBin;


sub error {
    say "************ ERROR **************";
    exit $?;
}

my $temp_dir = "tmp_serpent";

say "################################ Serpent ##############################";

# switching to usuba dir
chdir "$FindBin::Bin/../..";

# Compiling the compiler.
unless ($ARGV[0]) { 
    say "Compiling...";
    error if system 'make';
}


# Switching to temporary directory.
say "Preparing the files for the test...";
remove_tree $temp_dir if -d $temp_dir;
mkdir $temp_dir;

# Compiling Usuba DES.
say "Compiling Serpent from Usuba to C...";
error if system "./usubac -o $temp_dir/serpent.c -arch sse -no-runtime -no-share samples/usuba/serpent.ua" ;
{
    local $^I = "";
    local @ARGV = "$temp_dir/serpent.c";
    while(<>) {
        s/#include .*//;
    } continue { print }
}

chdir $temp_dir;
copy $_, '.' for glob "$FindBin::Bin/serpent/*";

# Compiling the reference implementation
say "Compiling reference C implementation...";
error if system 'clang -O3 -march=native -I../arch -o serpent_ref ref.c';

for my $ARCH (qw(STD SSE AVX)) {
    # Compiling the C files
    say "Compiling the test executable with $ARCH...";
    error if system "clang -D $ARCH -O3 -march=native -I../arch -o serpent main.c";

    say "Running the test with $ARCH...";
    error if system 'head -c 8M </dev/urandom > input.txt';
    error if system './serpent_ref';
    error if system './serpent';

    error if system 'cmp --silent output.txt out.txt';
    unlink 'output.txt', 'out.txt';
}

chdir '..';
remove_tree $temp_dir;

say "n-sliced Serpent OK.\n\n";
