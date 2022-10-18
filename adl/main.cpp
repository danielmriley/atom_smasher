#include <iostream>
#include "scanner.hpp"
#include "Parser.h"
#include "driver.h"
#include "semantic_checks.cpp"

int main(int argc, char **argv) {
    adl::Driver drv;
    int res = drv.parse();

    if(res == 0) std::cout << "Parsing successful!\n";
    else std::cout << "Parsing failed.\n";

    if(res == 0) std::cout << "ast.size(): " << drv.ast.size() << "\n";
    if(res == 0) { adl::setTables(drv); }
    if(res == 0) { adl::testAST(drv); }

    if(res == 0) for(auto d: drv.definitionTable) std::cout << "d: " << d << "\n";
    if(res == 0) for(auto d: drv.objectTable) std::cout << "o: " << d << "\n";
    if(res == 0) for(auto d: drv.regionTable) std::cout << "r: " << d << "\n";

    return res;
}