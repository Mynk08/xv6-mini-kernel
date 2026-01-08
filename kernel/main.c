// xv6 kernel initialization
#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"

int main(void) {
    kinit1(end, P2V(4*1024*1024)); // Physical page allocator
    kvmalloc();      // Kernel page table
    mpinit();        // Detect other processors
    lapicinit();     // Interrupt controller
    seginit();       // Segment descriptors
    picinit();       // Disable pic
    ioapicinit();    // Another interrupt controller
    consoleinit();   // Console I/O
    uartinit();      // Serial port
    pinit();         // Process table
    tvinit();        // Trap vectors
    binit();         // Buffer cache
    fileinit();      // File table
    ideinit();       // Disk
    startothers();   // Start other processors
    kinit2(P2V(4*1024*1024), P2V(PHYSTOP)); // Must come after startothers()
    userinit();      // First user process
    mpmain();        // Finish initialization
}
