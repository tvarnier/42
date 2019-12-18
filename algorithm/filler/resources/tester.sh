p1color="\033[38;2;85;255;85m"
p2color="\033[38;2;255;255;85m"
defcolor="\033[30;1m"
endcolor="\033[39m"
bold="\033[1m"
italic="\033[3m"
normal="\033[0m"

p1score=0
p2score=0
p1=$(echo $1 | rev | cut -d"/" -f1 | rev | cut -f 1 -d '.')
p2=$(echo $2 | rev | cut -d"/" -f1 | rev | cut -f 1 -d '.')

if [ $# -eq 2 ] && [ -x $1 ] && [ -x $2 ]
then
	for map in 'map01' 'map03'
	do
		printf " || $bold$map$normal ||\n"
		for i in {0..4}
		do
			output=$(./filler_vm -f maps/${map} -p1 $1 -p2 $2)
			p1round=$(echo $output | cut -d '=' -f3 | cut -d ' ' -f4)
			p2round=$(echo $output | cut -d '=' -f5 | cut -d ' ' -f4)
			if [ $p1round -gt $p2round ]
			then
				printf "$p1color$italic"
				printf "$p1 WIN\n"
				printf "$p1round : $p2round\n"
				printf "$endcolor$normal"
				((p1score++))
			elif [ $p2round -gt $p1round ]
			then
				printf "$p2color$italic"
				printf "$p2 WIN\n"
				printf "$p1round : $p2round\n"
				printf "$endcolor$normal"
				((p2score++))
			else
				printf "$defcolor$italic"
				printf "EGALITE\n"
				printf "$p1round : $p2round\n"
				printf "$endcolor$normal"
			fi
			if [ $i -eq 4 ]
			then
				printf "\n"
			fi
		done
	done
	if [ $p1score -gt $p2score ]
	then
		printf "$bold$p1color"
	elif [ $p2score -gt $p1score ]
	then
		printf "$bold$p2color"
	else
		printf "$bold$defcolor"
	fi
	printf " __      __.__                            \n"
	printf "/  \\    /  \\__| ____   ____   ___________ \n"
	printf "\\   \\/\\/   /  |/    \\ /    \\_/ __ \\_  __ \\"
	printf "\n"
	printf " \\        /|  |   |  \\   |  \\  ___/|  | \\/\n"
	printf "  \\__/\\  / |__|___|  /___|  /\\___  >__|   \n"
	printf "       \\/          \\/     \\/     \\/       \n"
	printf "$normal$endcolor"
else
	echo "usage : ./tester.sh ./player1.filler ./player2.filler"
fi
