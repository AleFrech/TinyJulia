#include <iostream>
#include "x86_dbg.h"
#include "x86_tree.h"

//X86 debugger functions
void X86Debugger::showStatus()
{
    XRtContext *ctx = sim->runtimeCtx;
    XInstruction *inst = instList[ctx->ip];
    
    cout << inst->line << ": " <<  sourceLines[inst->line - 1] << endl;
}

void X86Debugger::start()
{
    sim->runtimeCtx->ip = 0;
    sim->runtimeCtx->stop = false;
}

bool X86Debugger::next()
{
    XRtContext *ctx = sim->runtimeCtx;
    XInstruction *inst = instList[ctx->ip];
    int count = instList.size();
        
    ctx->line = inst->line;
    ctx->ip ++;
    
    if (!inst->exec(sim, sim->lastResult)) {
        return false;
    }
        
    if (ctx->stop || (ctx->ip >= count)) {
        finished = true;
    }

    return true;
}

bool X86Debugger::run()
{
    XRtContext *ctx = sim->runtimeCtx;
    int count = instList.size();
        
    while (1) {
        XInstruction *inst = instList[ctx->ip];
        
        if (breakpoints.find(inst->line) != breakpoints.end()) {
            if (inBreakpoint)
                inBreakpoint = false;
            else {
                cout << "Program paused due to breakpoint at line " << inst->line << endl;
                
                inBreakpoint = true;
                return false;
            }
        }
        
        ctx->line = inst->line;
        ctx->ip ++;

        if (!inst->exec(sim, sim->lastResult)) {
            return false;
        }

        if (ctx->stop || (ctx->ip >= count)) {
            finished = true;
            break;
        }
    }
    
    return true;
}

void X86Debugger::stop()
{
    delete mPool; //This releases all the tree nodes
    
    delete sim->runtimeCtx;
    delete sim->jumpTbl;

    sim->runtimeCtx = NULL;
    sim->jumpTbl = NULL;
    sim->dbg = NULL;
    
    delete this;
}

bool X86Debugger::doSimCommand(string cmd)
{
    stringstream in;
            
    in.str(cmd);

    XParserContext ctx;

    if (sim->parseFile(&in, ctx)) {
        XInstruction *inst = ctx.instList.front();
        XReference result;

        inst->exec(sim, result);
    } else {
        cout << "Error in command." << endl;
        return false;
    }
    
    return true;
}
