

g++ -std=gnu++11 -o main       ../main.cpp      ../includes/airport/simulation.cpp            -Igoogletest/googletest/include -pthread -Lgoogletest/build/lib -lgtest
g++ -std=gnu++11 -o basic_test ../_tests/_test_files/basic_test.cpp   ../includes/airport/simulation.cpp -Igoogletest/googletest/include -pthread -Lgoogletest/build/lib -lgtest
g++ -std=gnu++11 -o testB      ../_tests/_test_files/testB.cpp    ../includes/airport/simulation.cpp    -Igoogletest/googletest/include -pthread -Lgoogletest/build/lib -lgtest



