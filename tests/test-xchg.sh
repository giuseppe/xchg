#!/bin/bash

set -xeuo pipefail

env

dir=`mktemp -d`

cleanup() {
    rm -rf $dir
}
trap cleanup EXIT

echo a > $dir/a
echo b > $dir/b

./xchg $dir/a $dir/b

grep a $dir/b
grep b $dir/a

./xchg $dir/a $dir/b

grep a $dir/a
grep b $dir/b
