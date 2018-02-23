/* 
 * File:   x86_dbg.h
 * Author: ideras
 *
 * Created on September 12, 2016, 10:41 AM
 */

#ifndef X86_DBG_H
#define X86_DBG_H
#include <stdint.h>
#include <fstream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include "adbg.h"

using namespace std;

class MemPool;
class XInstruction;
class X86Sim;

class X86Debugger: public AsmDebugger
{
public:    
    X86Debugger(X86Sim *sim, vector<XInstruction *> instList, MemPool *mPool) {
        this->sim = sim;
        this->instList = instList;
        this->mPool = mPool;
        inBreakpoint = false;
        finished = false;
    }

    void showStatus();
    void addBreakpoint(int line) { breakpoints.insert(line); }
    void removeBreakpoint(int line) { breakpoints.erase(line); } 
    void removeAllBreakpoints() { breakpoints.clear(); }
    bool isInBreakpoint() { return inBreakpoint; }
    bool isFinished() { return finished; }
    void setSourceLines(vector<string> sourceLines) { this->sourceLines = sourceLines; }
    void start();
    bool next();
    bool run();
    void stop();
    bool doSimCommand(string cmd);
    
private:    
    bool inBreakpoint;
    bool finished;
    vector<string> sourceLines;
    vector<XInstruction *> instList;
    set<int> breakpoints;
    X86Sim *sim;
    MemPool *mPool;
};

#endif /* X86_DBG_H */

