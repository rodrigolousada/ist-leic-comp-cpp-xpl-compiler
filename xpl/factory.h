// $Id: factory.h,v 1.1 2017/02/17 16:02:31 david Exp $ -*- c++ -*-
#ifndef __XPL_FACTORY_H__
#define __XPL_FACTORY_H__

#include <memory>
#include <cdk/yy_factory.h>
#include "xpl_scanner.h"

namespace xpl {

  /**
   * This class implements the compiler factory for the XPL compiler.
   */
  class factory: public cdk::yy_factory<xpl_scanner> {
    /**
     * This object is automatically registered by the constructor in the
     * superclass' language registry.
     */
    static factory _self;

  protected:
    /**
     * @param language name of the language handled by this factory (see .cpp file)
     */
    factory(const std::string &language = "xpl") :
        cdk::yy_factory<xpl_scanner>(language) {
    }

  };

} // xpl

#endif
