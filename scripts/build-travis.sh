#!/bin/bash



function	list_directories()
{
	echo "."
	find tests/demos -mindepth 1 -maxdepth 1 -type d
}





retcode=0

echo $(pwd)

for directory in $(list_directories)
do
	pushd $directory

	echo -e "\n\n\033[1;30;46m"
	echo -e "################################################################################\033[K"
	echo -e "#\033[K"
	echo -e "#   Executing make $@ in directory '$(pwd)'\033[K"
	echo -e "#\033[K"
	echo -e "################################################################################\033[K"
	echo -e "\033[0m"

	if ! make $@
	then
		((retcode++))
	fi

	popd
done


if [[ "${retcode}" != "0" ]]
then
	echo -e "\033[1;41m#\033[K"
	echo -e "#   Detected ${retcode} errors while building !"
	echo -e "#\033[K\033[0m"
else
	echo -e "\033[1;30;42m#\033[K"
	echo -e "#   All builds successfull ! :-)"
	echo -e "#\033[K\033[0m"
fi

exit ${retcode}
