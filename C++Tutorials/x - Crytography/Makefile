#Tlamangile Expert Ngobeni NGBTLA003 CSC3023F Assignment 3 Makefile
#linking libraries
main : 
	# Compile sources	
	g++ -std=c++11 -c *.cpp *.h -fPIC -lboost_program_options
	# Unit Test Excutable
	g++ -std=c++11  DriverCmdlineParser.cpp -o cmd -fPIC -lboost_program_options
	# Cmdline Parser Excutable
	g++ -std=c++11  DriverUnitTest.cpp -o unit -fPIC -lboost_program_options
	# Results Directory
	mkdir results
	# Type "make runu" for unit test or "make runc" for cmdline parser
	# To one test use "./unit <name>" e.g "./unit PACK" or "./unit -h" for help
	# To specify tags use "./cmd -i input.txt -e XOR" or "/.cmd -?" for help 


#Clean runtime files
clean:
	# Delete runtime files 
	rm -r *.o *.h.gch ./unit ./cmd results

#Unit test driver run
runu: 
	# Unit test driver run, output is in results folder 
	./unit   

#Cmdline Driver run with default parameters
runc:
	# Cmdline Driver run with default parameters	
	./cmd -e XOR -x 20 

help:
	./unit -h
	# Group : "make group"
	# Pack  : "make pack"
	# Encode XOR : "make encodeX"
	# Decode XOR : "make decodeX"
	# Encode Vignere: "make encodeV"
	# Decode Vignere: "make decodeV"
	./cmd -?


group:
	./cmd -g true -o group.txt

pack:   
	./cmd -p true -o pack.data

encodeX:
	./cmd -e XOH -100 -m ECB -o encodeX.data

decodeX: 
	./cmd -d XOH -100 -m ECB -i result/encodeX.data -o decodedX.txt

encodeV:
	./cmd -e Vignere -v LEMON -m ECB -o encodeV.txt

decodeV:
	./cmd -d Vignere -v LEMON -m ECB -i results/encodeV.txt -o decodeV.txt


