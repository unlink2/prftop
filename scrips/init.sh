#!/bin/bash

# rename to project specific values
NAME="prf"
CONST="prf"
STRUCT="prf"
FN="prf"

# will be replaced
prf_NAME="prf"
prf_STRUCT="prf"
prf_CONST="prf"
prf_FN="prf"

function replace() {
	echo "Replacing $1 with $2"
	find ./ -type f -name '*.c' -exec sed -i "s/$1/$2/g" {} \;
	find ./ -type f -name '*.h' -exec sed -i "s/$1/$2/g" {} \;
	find ./ -type f -name '*.md' -exec sed -i "s/$1/$2/g" {} \;
	find ./ -type f -name '*.lua' -exec sed -i "s/$1/$2/g" {} \;
	find ./ -type f -name '*.sh' -exec sed -i "s/$1/$2/g" {} \;
	find ./doc/ -type f -name '*' -exec sed -i "s/$1/$2/g" {} \;
}

replace $prf_NAME $NAME
replace $prf_CONST $CONST
replace $prf_STRUCT $STRUCT
replace $prf_FN $FN

mv "include/$prf_NAME.h" "include/$NAME.h"
mv "src/$prf_NAME.c" "src/$NAME.c"
mv "doc/$prf_NAME" "doc/$NAME" 
