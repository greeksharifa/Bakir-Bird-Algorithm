all: BakerBird checker

BakerBird: main.cpp
	g++ -o BakerBird -O3 main.cpp


checker: checker.cpp
	g++ -o checker -O3 checker.cpp

run_BakerBird: BakerBird
	./BakerBird bb_in.txt bb_out.txt


run_checker: checker
	./checker bb_in.txt bb_out.txt cc_out.txt

clean:
	rm BakerBird checker


