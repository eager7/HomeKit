//
// Created by pct on 17-1-12.
//
#include "utils.h"
#include "light_bulb.h"

int main(void)
{
    DBG_vPrintln(T_TRUE, "home kit light bulb test");
    eLightBulbProfileInit("DimmerLight", "12345678", "TopBand", "1234");



    eLightBulbProfileFinished();

    return 0;
}