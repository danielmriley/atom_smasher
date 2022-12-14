#include "driver.h"

namespace adl {
  Driver::Driver () :
    scanner(*this),
    parser(scanner, *this),
    loc(0) {}

  int Driver::parse () {
    loc = 0;
    return parser.parse();
  }

  int Driver::visitAST(int (*f)(ExprVector& _ast)) {
    return f(ast);
  }

  int Driver::setTables() {
    for(int i = 0; i < ast.size(); i++) {
      std::string token = ast[i]->getToken();
      if(token == "DEFINE") {
        addDefine(ast[i]->getId());
      }
      else if(token == "OBJECT") {
        addObject(ast[i]->getId());
      }
      else if(token == "REGION") {
        addRegion(ast[i]->getId());
      }
    }

    return 0;
  }

  void Driver::addNode(Expr* node) {
    ast.push_back(node);
  }

  void Driver::addDefine(std::string id) {
    definitionTable.push_back(id);
  }

  void Driver::addObject(std::string id) {
    objectTable.push_back(id);
  }

  void Driver::addRegion(std::string id) {
    regionTable.push_back(id);
  }

  void Driver::incrementLocation(unsigned int l) {
    loc+=l;
  }

  unsigned int Driver::location() {
      return loc;
  }
} // end namespace adl
